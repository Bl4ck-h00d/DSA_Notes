//Point Update and Range Query

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define fii fiied << setprecision(10)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vec vector<ll>
#define pb push_back
#define mod (1000000000 + 7)
#define all(v) v.begin(), v.end()

using namespace std;

vector<long long> tree;

void build(int node, int start, int end, vector<int> &nums)
{
    if (start == end)
    {
        tree[node] = nums[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, nums);
    build(2 * node + 1, mid + 1, end, nums);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int ind, int val, vector<int> &nums)
{
    if (start == end)
    {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (ind <= mid)
        update(2 * node, start, mid, ind, val, nums);
    else
        update(2 * node + 1, mid + 1, end, ind, val, nums);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

long long query(int node, int start, int end, int l, int r, vector<int> &nums)
{
    if (start > r || end < l)
        return 1e15;
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    long long left = query(2 * node, start, mid, l, r, nums);
    long long right = query(2 * node + 1, mid + 1, end, l, r, nums);
    return min(left, right);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;
    vector<int> nums(n, 0);
    tree.resize(4 * n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    build(1, 0, n - 1, nums);
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1)
        {
            update(1, 0, n - 1, a - 1, b, nums);
        }
        else
        {
            long long res = query(1, 0, n - 1, a - 1, b - 1, nums);
            cout << res << endl;
        }
    }

    return 0;
}