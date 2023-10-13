/**
 *
 * Asked in Razorpay
 *
 * given a tree with n nodes and n-1 edges with weights.
 * F(i,j)=> max edge wt between a simple path between i and j
 * return the sum of F(i,j) for all pairs
 *
 * Similart to - https://leetcode.com/problems/number-of-good-paths/submissions/
 *
 *
 */

/**
 *  INTUITION-
 *      ->Sort the edges (increasing order of wt)
 *      -> say we have 2 trees A and B with parent a and b respectively
 *      -> consider the edge {a,b,w}
 *      -> if w > maxEdge(A) and w> maxEdge(B) => current edge wt is max among both the trees
 *              => ans+=(w x size(A) x size(B)) we would have A x B path which have w as max wt
 *      
 * 
 * 
*/