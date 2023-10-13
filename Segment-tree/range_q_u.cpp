/*
    Range Query + Range Update
    Query(L,R) => Sum of elements from L to R

    -Here we will need 2 tree arrays
        -1st will be similar to range update tree (initially all nodes 0 + propagation) => lazy[]
        -2nd tree nodes will have sum values of ranges => tree[]

    For Propagation-
        - say we for range [0,7] curr sum is 44 and we have to update [0,7] by 2
        - we propagate 2 as usual in lazy tree
        - but in tree[] we update the value of 44 to 44 + (7-0+1)*2 coz, adding 2 will increase sum by 2*no. of elements in range

*/

#include <bits/stdc++.h>

using namespace std;

int arr[100001];  // arr[n]
int tree[400002]; // tree[4*n]
int lazy[400002]; // tree[4*n]

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        lazy[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1]; // <=========
    lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int x)
{
    // no overlap
    if (start > r || end < l)
    {
        return;
    }
    if(start==end)
    {
        tree[node] += x;
        return;
    }
    // complete overlap
    if (start >= l && end <= r)
    {
        lazy[node] += x;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, x);
    update(2 * node + 1, mid + 1, end, l, r, x);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void propagate(int node, int start, int end)
{
    //leaf node - donot propagate further
    if(start==end)
    {
        tree[node] += lazy[node];
        lazy[node] = 0;
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;

    int x = lazy[node];

    // lazy propagation
    lazy[left] += lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;

    // update curr sum value
    tree[node] += x * (end - start + 1);
}
int query(int node, int start, int end, int l, int r)
{
    // no overlap
    if (start > r || end < l)
    {
        return 0;
    }
    propagate(node, start, end);

    // complete overlap
    if (start >= l && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);
    return left + right;
}
