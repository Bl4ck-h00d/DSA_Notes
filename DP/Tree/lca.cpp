/**
 * Lowest Common Ancestor (LCA)
 *
 *
 *
A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.

Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?

Input

The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,…,n, and employee 1 is the general director.

The next line has n−1 integers e2,e3,…,en: for each employee 2,3,…,n their boss.

Finally, there are q lines describing the queries. Each line has two integers a and b: who is the lowest common boss of employees a and b?

Output

Print the answer for each query.

Constraints
1≤n,q≤2⋅105
1≤ei≤i−1
1≤a,b≤n
Example

Input:
5 3
1 1 3 3
4 5
2 5
1 4

Output:
3
1
1
 *
 * M1- Binary lifting + Binary Search => T(logN*logN)
 *
*/

#include <bits/stdc++.h>

using namespace std;

int up[200005][20];
vector<int> g[200001];
int level[200001];

void binaryLift(int node, int parent)
{
    up[node][0] = parent;

    for (int i = 1; i < 20; i++)
    {
        if (up[node][i - 1] != -1)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        else
        {
            up[node][i] = -1;
        }
    }

    for (auto child : g[node])
    {
        if (parent != child)
        {
            binaryLift(child, node);
        }
    }
}

void dfs(int node, int parent, int height)
{
    level[node] = height;
    for (auto child : g[node])
    {
        if (child != parent)
        {
            dfs(child, node, height + 1);
        }
    }
}

int makeJump(int node, int jump)
{
    if (node == -1 || jump == 0)
        return node;

    for (int i = 19; i >= 0; i--)
    {
        if (jump >= (1 << i))
        {
            return makeJump(up[node][i], jump - (1 << i));
        }
    }
}

int LCA(int u, int v) //)(logN * logN)
{
    if (level[u] < level[v])
        swap(u, v);

    u = makeJump(u, level[u] - level[v]);

    int l = 0;
    int h = level[u];
    while (l <= h)
    {
        int mid = (l + h) / 2;

        int x1 = makeJump(u, mid);
        int x2 = makeJump(v, mid);

        if (x1 == x2)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return makeJump(u, l);
}

/**
 * LCA-2
 *
 *              R
 *              |
 *              |
 *              L     ----
 *             / \       |
 *            /   \      x
 *           /     \     |
 *          u       v ___|
 *
 * We will make jumps (as large as possible s.t, makeJump(u,y)!=makeJump(v,y)) from u to reach at level x-1
 *
 * Simply, keep making large jumps till makeJump(u,y)!=makeJump(v,y), when no more jumps can be made we have reached x-1 lvl
 * 
 * now we will make just 1 jump to reach LCA
 *
 * 
 * T- O(logN)
 */

int LCA2(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);

    u = makeJump(u, level[u] - level[v]); //make u & v at same level

    if (u == v)
        return u;

    //make as large as possible jumps
    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i]) 
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    //now u & v are at x-1 level
    return makeJump(u, 1);
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        g[i].push_back(a);
        g[a].push_back(i);
    }

    memset(up, -1, sizeof(up));

    binaryLift(1, -1); // calculate ancestor for each node

    dfs(1, -1, 0); // find level

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int res = LCA(u, v);
    }

    return 0;
}
