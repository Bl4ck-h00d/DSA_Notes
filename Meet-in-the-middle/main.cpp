/**
 *
 * Meet in the Middle
 *
 * Use when we can solve problem for n smaller than n/2.
 * -> We can solve for each half and merge the answer.
 * -> It is not Divide n Conquer
 *
 *
 *
 */

/**
 * Question List
 *
 * https://leetcode.com/problems/closest-subsequence-sum/
 * https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
 *
 *
 * Pattern -> Minimise absolute difference + partition in subset/subsequence + N<=40 + seems like DP but is not
 *
 * Approach-
 *  Divide the given array in 2 halves n/2 n/2 (take care of odd length)
 * 
 *  -left partition and right partition
 *  -Generate all the subset/subseq of left and right part using bitmask and create left sum array and right sum array 
 *  - sort right array and do upper/lower bound for each element in left.
 * 
 *
 */

/**
 * Q1 Given N<=40 numbers, find subsets summing equal to S.
 *
 *
 * Meet in the middle=> If N was <=20, we could have solved by generating all the subsets (using bitmasks). T- (2^N);
 *
 * Using Meet in the Middle we want to achieve T-(2^(N/2))
 *
 *
 * Approach-
 *
 *  2 1 6 | _ _ _ ...
 *
 * We partition the array into half and generate all the subsets in each halves. Say in part 1 we get a subset with sum x, then we will look if we have a subset sum S-x in the other half.
 *
 */

/**
 *
 * Q2, Given a sequence a1,a2,a3,....an (n<=2000), count increasing subsequence of length 3.
 *
 *
 * 2 5 4 1 8 9 20 15
 *
 * Brute-force-> O(N^3)
 *
 * We want to achieve O(N^2)
 *
 * Even if n=1000 instead of 2000, it wouldnt help much.
 *
 * There is another Number in the statement => 3, if 3 was smaller it would have been easier to solve it.
 *
 *
 * Count subsequence of length K => focus on calculating subsequence of length ceil(k/2)
 *
 * Therefore, if K=ceil(3/2)=2, we can solve in O(N2)
 *
 * "Middle" => second of three elements
 *
 *
 * Approach-
 * -> We are looking for pairs (i,j,k).
 * -> We will focus on 'j' and for it I will independently look for i and k on left and right respectively.
 *
 *  Ans = [no. of elems smaller than j on left]*[no. of elems greater than j on right]
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 8;
    int arr[n] = {2, 5, 4, 1, 8, 9, 20, 15};
    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        int smaller = 0; // no. of elemenst smaller than j
        int bigger = 0;  // no. of elements greater than j

        // iterate on left of j
        for (int i = 0; i < j; i++)
        {
            if (arr[i] < arr[j])
            {
                smaller++;
            }
        }

        // iterate on right of j
        for (int k = j + 1; k < n; k++)
        {
            if (arr[k] > arr[j])
            {
                bigger++;
            }
        }
        ans += smaller * bigger;
    }
}






/**
 * Q3, 4 Sum
 * 
 * x=100, n<=1000
 * 
 *  _ _ _ 15 _ _ 25 _ _ _
 *        i      j
 * 
 * we want (i,j,k,l)
 * we have i,j=> required = x-(15+25)=60 = a[k]+a[l]
 * 
 * Instead of focusing on 4 numbers we will focus on a pair of numbers
 * 
 * We need following structure
 * 
 * _ _ _ _ _ | _ _ _ _
 *    prefix     i   j
 * 
 * prefix-> keeps the possible sum pairs
 * 
 *   5 7 10 11 _ _ | i _ j _
 * 12 15 17.....
 * 
 * For i&j we can lookup the missing sum pair in the prefix
 * 
 * 
 * 
 * 
 * 
*/    

void solve(){
    set<int> pairs; //prefix pair sums, stores pairs upto (i-1)
    int n;
    int sum;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            int missing = sum - (a[i] + a[j]);

            if(pairs.count(missing))
            {
                cout << "YES\n";
                return 0;
            }
        }
        //update pairs

        for (int z = 0; z < i;z++)
        {
            pairs.insert(a[z] + a[i]);
        }
    }
}