/**
 * https://www.interviewbit.com/problems/potions/
 *
 * 
 * 
 * sol1 + sol2 => sol3 (x+y)%100
 * 
 * Break into 2 groups
 * 
 * Smoke in (i,i+1,i+2 ... k) + Smoke in (k+1,k+2,...,j) + Smoke due to resultant of mixing (i,k) & (k+1,j)
 * 
 * Resultant color of a group will basically be sum (taking mod) of all the colors in it.
 *
 */

#include <bits/stdc++.h>
using namespace std;

static long long dp[101][101];

long long sum(int l, int r, vector<int> &arr)
{
    int sum = arr[l];
    for (int i = l + 1; i <= r; i++)
    {
        sum = (sum + arr[i]) % 100;
    }

    return sum;
}

long long help(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    long long ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        ans = min(ans, help(i, k, arr) + help(k + 1, j, arr) + (sum(i, k, arr) * sum(k + 1, j, arr)));
    }

    return dp[i][j] = ans;
}

int solve(vector<int> &arr)
{

    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    int ans = help(0, n - 1, arr);

    return ans;
}
