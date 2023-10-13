/**
 * Fisher-Yates Algorithm-
 * 
 * Question-> Generate a shuffled array from a given array
 * 
 * 
 * M1 -> 
 *  - Select a random index and append the value at that index in another array named Shuffle.
 *  - Also pop that index from original index
 *  - repeat above steps till original array is empty.
 * 
 *  T- O(N2) -> Generate N random numbers * shift numbers after the popped index
 *  S -O(N) -> Shuffled array
 * 
 * M2 -> Fisher Yates Algorithm
 * 
 *  - Consider the range [0..N] 
 *  - Generate a random index in that range and swap it with last Number in the range (N)
 *  - Now reduce the range [0...N-1]
 *  - Again generate a random index and swap with last number
 *  - range [0..N-2]
 * 
 *  At the end we will have our shuffled array 
 * 
 *  T-O(N)
 *  S-O(1)
 * 
*/


#include<bits/stdc++.h>

using namespace std;

void shuffle(vector<int>&arr, int n)
{
    for (int i = 0; i < n;i++)
    {
        // generate random index in the range
        int randIndex = rand() % (n - i);
        swap(arr[randIndex], arr[n - i - 1]);
    }

    // Print arr;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};

    shuffle(arr,5);
}