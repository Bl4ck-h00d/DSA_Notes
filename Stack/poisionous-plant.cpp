/**
 * VERY IMPORTANT QUESTION BASED ON STACK
 *
 * https://www.hackerrank.com/challenges/poisonous-plants/problem
 * 
 * 
 *
 *
 */

#include<bits/stdc++.h>

using namespace std;

/**
 *
 * Intuition-
 *
 * Intuition - [6 5 8 4 7 10 9]
    -6 will always survive to [{6,0}]
    -5 6 ko dekh k bolega tu to mujhe nyi maar skta (coz 5<6) to ye bta tu kab mar rha hai => 6 will never die to 5 will also survive
    - 8 5 ko bolega tu to mujhe maar dega, 8 dies on day 1 => [{6,0},{5,0},{8,1}]
    - 4 8 ko dekh k bolega tu to mujhe nyi maar skta to ye bta tu kab mar rha hai, 8 bola 1 din baad fir 4 age dekhega 5 ko same question, to 5 bola kabhi nyi to apan bhi kabhi nyi marenge => [{6,0},{5,0},{8,1},{4,0}]
    - 7 4 se bolega tu mujhe maar dega => [{6,0},{5,0},{8,1},{4,0},{7,1}]
    -10 7 se bolega tu mujhe maar dega =>  [{6,0},{5,0},{8,1},{4,0},{7,1},{10,1}]
    - 9 10 se bolega tu kab maar rha hai to vo bolega day 1, fir apan 7 se bolenge tu to mujhe maar dega aur raste mein 10 mila tha to apan uske baad hi marenge i.e, day 2 =>  [{6,0},{5,0},{8,1},{4,0},{7,1},{10,1},{9,2}]
 *
 *
*/

int poisonousPlants(vector<int> p)
{

    int n = p.size();
    stack<pair<int, int>> s;
    s.push({p[0], 0});
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int d = 0;

        // you cant kill me, so tell me when you die?
        while (!s.empty() && s.top().first >= p[i])
        {
            d = max(d, s.top().second);
            s.pop();
        }

        // I never die
        if (s.empty())
        {
            s.push({p[i], 0});
        }
        // I die
        else
        {
            s.push({p[i], d + 1});
            ans = max(ans, d + 1);
        }
    }
    return ans;
}