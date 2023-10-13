/*
    Range Update + Point Query

    ->update(L,R,x)-> Update the values in a given range L to R by x
    ->query(idx)-> value at index idx
*/

/**
 * Idea-
 *
 * Update(l,r,x)-
 *  - when [start,end] is completely inside the [l,r] then update that node by x (initially all the nodes where 0)
 *  - when we query a index in that range, we traverse down that leaf node.
 *  - while traversing when we hit the updated node, we set that node back to 0 and propagate that updated values to the children
 *
 *          3                     0              0
 *         / \        q(i)       / \            / \
 *        0   0      =====>     3   3     =>   3   0
 *       /    / \              /   / \        /   / \
 *      0    0   0            0   0   0      0   3   3
 *      L    i   R
 *
 *
 */

/**
 * Build
 * -Initially tree nodes have value 0
 * -When start==end place the value of array there (leaf)
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;

int arr[100001];  // arr[n]
int tree[400002]; // tree[4*n]

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = 0;  //<---------
}

void update(int node, int start, int end, int l, int r, int x)
{
    // no overlap
    if (start > r || end < l)
    {
        return;
    }
    // complete overlap
    if (start >= l && end <= r)
    {
        tree[node] += x;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, x);
    update(2 * node + 1, mid + 1, end, l, r, x);
}

int propagate(int node)
{
    int left = 2 * node;
    int right = 2 * node + 1;
    tree[left] += tree[node];
    tree[right] += tree[node];
    tree[node] = 0;
}
int query(int node, int start, int end, int idx)
{
    if (start == end)
    {
        return tree[node];
    }
    if (tree[node] != 0)
        propagate(node);
    int mid = (start + end) / 2;
    if (idx <= mid)
        return query(2 * node, start, mid, idx);
    else
        return query(2 * node + 1, mid + 1, end, idx);
}

