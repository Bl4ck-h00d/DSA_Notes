/**
 *
 * https://cses.fi/problemset/task/1653/
 * https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
 *
 */

#include <bits/stdc++.h>

using namespace std;

int minRides(vector<int> &weight, int limit)
{

    /*
        dp[s]={Rides used, last ride weight(coz that will be minimum of all rides)  }

        s->subset

        we check if the new person P can be accomodated in that minimum ride                   
        or
        we need to reserve a new ride?
    */

    int n = weight.size();
    vector<pair<int, int>> dp(1 << n);

    dp[0] = {1, 0}; // empty set

    // consider all subsets
    for (int s = 1; s < (1 << n); s++)
    {
        dp[s] = {INT_MAX, 0};

        for (int p = 0; p < n; p++)
        {
            /*
                If current has been included consider the case when this task
                was "to be included"
            */
            if (s & (1 << p))
            {
                /*
                    Case when current task was to be included
                */
                auto option = dp[s ^ (1 << p)]; // unset this task bit

                // Can be added in last (min) session
                if (weight[p] + option.second <= limit)
                {
                    option.second += weight[p];
                }
                // create a new session
                else
                {
                    option = {option.first + 1, weight[p]};
                }
                dp[s] = min(dp[s], option);
            }
        }
    }

    return dp[(1 << n) - 1].first;
}

int main()
{
    return 0;
}