/**
 * DUTCH NATIONAL FLAG ALGORITHM
 *
 * PS- Sort an array of 0,1,2 in single pass and constant space
 * [2,0,2,1,1,0]
 *
 */


/**
 * -We will try to partition the array using 3 ptrs 
 * -i,j=0 and k=n-1
 *  Region of i to k => unknown
 *  Region of 0 to j-1 => 0
 *  Region of j to i => 1
 *  Region of k+1 to n-1 => 2
 * 
 * 
*/

/*
   i,j             k
    2  0  2  1  1  0

    Case1- a[i]==0 => swap(a[i],a[j]) => 0 ko j k piche dalo
                      i++, j++
                      
    Case2- a[i]==2 => swap(a[i],a[k]) => 2 ko k k piche dalo
                      k--; i ko age nyi badhaya kyu ki k pe jo value tha pehle vo unknown tha.

    Case3- a[i]==1 => i++ => i k piche dalo

*/