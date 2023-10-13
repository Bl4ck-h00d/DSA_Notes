/**
 * Difference Array
 *
 * A=> 1 2 3 4 5 6 7 8
 *
 * Difference array d is defined as-
 * d[0]=A[0]
 * d[i]=A[i]-A[i-1]
 *
 * d=> 1 1 1 1 1 1 1 1
 *
 *
 * Problem-> Given an array and Q queries each query has a range L to R in which we have to perform A[i]+=x or A[i]-=x on all elements in the given range.
 *
 * operation-> a[i]+=1
 *
 *      0 1 2 3 4 5 6 7
 * A => 0 0 0 0 0 0 0 0
 *
 * Q-
 * 0 5  1 1 1 1 1 1
 * 6-7              1 1
 * 3-4        2 2
 * 1-2    2 2
 * ---------------------------
 *      1 2 2 2 2 1 1 1 ===> ANS
 *
 * Approach->
 * -Create a difference array of length n+1
 * -Given a query L to R => d[L]+=x and d[R+1]-=x, why?
 *
 *  say L=0 & R=4
 *
 *         0 1 2 3 4 5 6 7
 *  Diff-> 0 0 0 0 0 0 0 0
 *  D[0]=1
 *  D[5]=1
 *  Diff-> 1 0 0 0 0 -1 0 0
 *   
 *  We know that D[i]=A[i]-A[i-1]
 *      => A[i]=D[i]+A[i-1]
 *  
 *  Resultant array->
 *  A[0] = D[0] = 1
 *  A[1] = D[1] + A[0] = D[1] + D[0] =1
 *  A[2] = D[2] + D[0] + D[1] = 1
 *  ...
 *  A[5] = D[5] + D[4] + D[3] +...+ D[0] = -1+1 = 0
 * 
 * => We see that val at D[L] is carried through the array till (R+1)th where it is compensated by negative value.
 * 
 */
