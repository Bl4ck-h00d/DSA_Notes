/**
 *
 * Modulo
 *
 * 1. (a+b)%M = ((a%M) + (b%M))%M
 * 2. (a*b)%M = ((a%M) * (b%M))%M
 * 3. (a-b)%M = ((a%M)-(b%M) + M)%M //We added +M coz, difference could be negative
 * 4. (a/b)%M = ((a%M) * (b^-1)%M)%M // b^-1 => multiplicative inverse (Binary Exponentiation )
 *
 */

/**
 *
 * Subset Generation Using Bitmask
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int> &arr)
{
    int n = arr.size();
    int subsetCount = (1 << n); // 2^n
    vector<vector<int>> ans;

    // iterate through all the possible masks
    for (int mask = 0; mask < subsetCount; mask++)
    {
        vector<int> subset;

        // get all set bits
        for (int i = 0; i < n; i++)
        {
            // check if ith bit is set
            if (mask & (1 << i))
            {
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto res = subsets(arr);
}

/**
 * GCD & LCM
 *
 *  IMP->  A*B = GCD(A,B)*LCM(A*B) => [ A*B = GCD*LCM ]
 *
 */

// Calculatin GCD by long division method

/*
12 ) 18
     12
---------
      6 ) 12
          12
        -----
           0     gcd =6

Remainder becomes divisor and prev divisor becomes dividend

*/

// b ) a  => b<a (initially)
// b-> divisor
// a-> dividend

// gcd(dividend, divisor) => T(logN)

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    // remainder becomes divisor and prev divisor becomes dividend
    gcd(b, a % b);
}

/**
 * Binary Exponentiation
 *
 * Efficiently calculate a^b
 *
 * Brute force - T(b)
 *
 * Binary Exponentiation -> T(logb)
 *
 * -> Divide n Conquer
 *
 * ex- 2^16 =>
 *     2^8 * 2^8 <-
 *                |
 *     2^4 * 2^4 <-
 *                |
 *     2^2 * 2^2 <-
 *                |
 *     2^1 * 2^1---
 *
 * IF b is even => f(a,b)=> f(a,b/2)*f(a,b/2);
 * ELSE  => f(a,b) => a * f(a,b/2)*f(a,b/2);
 *
 */

int mod = 1e9 + 7;
int power(int a, int b)
{
    if (b == 0)
        return 1;
    int cache = power(a, b / 2);
    if (b & 1)
    {
        // return a * power(a, b / 2) * power(a, b / 2);
        return (a * (cache * 1LL * cache) % mod) % mod;
    }
    else
    {
        // return power(a, b / 2) * power(a, b / 2);
        return (cache * 1LL * cache) % mod;
    }
}