/**
 * https://atcoder.jp/contests/dp/tasks/dp_e
 * 
 * Check the constraint of weight, instead of forming dp[i][wt]=val we will form the dp[i][val]=wt
 * 
 * We will check what is minimum possible wt sum to achieve a particular value.
 * 
 * Instead of maximum possible value at an index and given wt sum.
 *
 *
 */

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

static ll dp[101][100001];

ll solve(int i, int valLeft, vector<int> &val, vector<int> &wt)
{
    if (valLeft == 0)
        return 0;

    if (i >= val.size())
        return 1e15 + 3;

    if (dp[i][valLeft] != -1)
        return dp[i][valLeft];

    ll ans = solve(i + 1, valLeft, val, wt);

    if (valLeft - val[i] >= 0)
        ans = min(ans, wt[i] + solve(i + 1, valLeft - val[i], val, wt));

    return dp[i][valLeft] = ans;
}

void solve2()
{
    int n, w;
    cin >> n >> w;

    vector<int> val(n);
    vector<int> wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        cin >> val[i];
    }

    memset(dp, -1, sizeof(dp));
    int maxValue = 1e5 + 1;

    //first value where wt constraint is satisfied is the ans
    for (int v = maxValue; v >= 0; v--)
    {
        long long k = solve(0, v, val, wt);

        if (k <= w)
        {
            cout << v << endl;
            break;
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve2();

    return 0;
}