/**
 * Variations of Binary search
 *
 * Distribution
 *
 * We want to make a dish which requires N ingredients. We are given how much of each ingredient is required to make 1 dish. We are also given amount of each ingredient available in our kitchen. There is a shop from where we can buy infinite amount of any ingredient (given the price of each). We have a fixed amount of money with us.
 *
 * How many at max dish we can make?
 *
 * https://codeforces.com/contest/371/problem/C
 * https://codeforces.com/contest/670/problem/D1
 * https://wentao-shao.gitbook.io/leetcode/array/1231.divide-chocolate
 * Agrressive Cows
 *
 * I/p-
 *
 * BBBSSC {3-B, 2-S and 1-C are required to make 1 dish}
 * 6 4 1 {amount of B,S,C we have in kitchen}
 * 1 2 3 {price of B,S,C }
 * 4 {amount}
 *
 *
 * O/p-2
 *
 *
 * Approach-
 *
 * Think how many dishes can we make? min =0 max=2e12 (according to constraints)
 *
 */

#include <bits/stdc++.h>
#define ll long long int


using namespace std;
void solve()
{

    string s;
    cin >> s;

    vector<ll> have(3);
    vector<ll> price(3);
    ll amount;

    for (int i = 0; i < 3; i++)
    {
        cin >> have[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> price[i];
    }
    cin >> amount;

    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }

    char arr[3] = {'B', 'S', 'C'};

    ll l = 0;
    ll h = 2000000000001;
    ll ans = 0;
    while (l <= h)
    {
        //check if we can make "mid" no. of dishes?
        ll mid = l + (h - l) / 2;


        //----------func to validate mid------------------------------
        ll cost = 0;

        //cost to make mid dishes
        for (int i = 0; i < 3; i++)
        {
            //(amount of ingredient to make 1 * mid - amount we have)*price
            cost += max((m[arr[i]] * mid - have[i]) * price[i], (ll)0);
        }
        
        //------------------------------------------------


        //if cost is less than amount then it is a possible ans
        if (cost <= amount)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans << endl;
    return;
}


//Structure-

/**
 *
 * int low=0;
 * int high=2e12+1;
 *
 * while(l<=h)
 * {
 *      int mid=(low+high)/2;
 * 
 *      //A function to check if mid is a valid answer
 *      func(mid) => this function can even have O(n) or more or any complexity
 * 
 *      //move left/right accordingly
 * }
 *
 */