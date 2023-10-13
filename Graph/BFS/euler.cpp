/**
 * ==Euler Path & Euler Circuit===
 *
 * Euler path- Path that visits all the edges in a graph exactly once.
 *
 * Euler circuit- Euler path with same starting and ending point.
 *
 * ==Undirected Graph==
 *
 * -> Eulerian Cycle-
 *      -All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path.
 *      -All vertices have even degree.
 *
 *
 *
 * -> Eulerian Path-
 *      -All non-zero degree nodes should be connected.
 *      -we have out[i] == in[i] for each node i. Or
we have out[i] == in[i] for all nodes i except exactly 2 nodes x and y, with out[x] = in[x] + 1, out[y] = in[y] - 1.
 *
 *
 * ==Directed Graph==
 *
 * -> Euler Circuit-
 *      -All vertices with non-zero degree belong to 1 strongly connected component.
 *      - Indegree == Outdegree for all vertices.
 *
 */

// https: // practice.geeksforgeeks.org/problems/circle-of-strings4530/1