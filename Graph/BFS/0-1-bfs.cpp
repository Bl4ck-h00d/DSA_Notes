/**
 * 0-1 BFS
 *
 *
 * It is well-known, that you can find the shortest paths between a single source and all other vertices in O(E) using Breadth First Search in an unweighted  graph, i.e. the distance is the minimal number of edges that you need to traverse from the source to another vertex. We can interpret such a graph also as a weighted graph, where every edge has the weight . If not all edges in graph have the same weight, that we need a more general algorithm, like Dijkstra which runs in O(ElogV)  time.

However if the weights are more constrained, we can often do better. In this article we demonstrate how we can use BFS to solve the SSSP (single-source shortest path) problem in O(E), if the weight of each edge is either 0 or 1.
 *
 *
 * Observation- In case of BFS, at a time there are nodes of atmax 2 levels-> the current level nodes (being processed) and the child level nodes (being pushed).
 *
 *If we have a graph with weights 0 or 1, we can greedily consider the child nodes with edge wt 0 on same level as of parent. Coz we can reach that child node without any cost.
 *
 *          0
 *      1/ 0|  \1                 => 0-2 can be considered on same level
 *      /   |   \
 *     1    2    3
 *
 * Therefore, to consider we need a child node on same level we will have to push the node at the front of queue, else if node is not on same level we will push node at the end of the queue.
 *
 * We will use dequeue instead of priority_queue or queue => This optimises the dijkstra as insertion takes logN time.
 *
 *
 * Questions- https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/ -Google onsite
 *
*/

// https://www.codechef.com/problems/REVERSE -> Given a directed graph of N nodes and M edges. Find min cost to reach from 1 to N. Cost of reverting an edge is 1

// https : // leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/


/**
 * Identification-
 * Graph diya rahega 
 * cost nikalna rahega src to dest ka`
 * edges reverse krna hoga/obstacle remove krna hoga/ kuch to bhi krne ka option rahega aur uska cost 1 hoga
 * 
*/

// code

// Approach- We will add reversed edge with wt 1 and then will do 0-1 bfs

#include <bits/stdc++.h>
        using namespace std;

// similar to dijkstra
int bfs(int src, int dest, vector<pair<int, int>> g[], vector<int> &dist)
{
    deque<int> q;
    q.push_back(src);
    dist[src] = 0; // src node

    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();

        for (auto child : g[curr])
        {
            int childNode = child.first;
            int wt = child.second;

            if (dist[curr] + wt < dist[childNode])
            {
                dist[childNode] = dist[curr] + wt;
                if (wt == 1)
                {
                    q.push_back(childNode);
                }
                else
                {
                    q.push_front(childNode);
                }
            }
        }
    }

    return dist[dest]==INT_MAX?-1:dist[dest];
}

int main()
{

    int n, m;
    cin >> n >> m;

    //{node, wt}
    vector<pair<int, int>> g[n + 1];
    vector<int> dist(n + 1, INT_MAX);

    for (int i = 1; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a==b)
            continue;
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }

    bfs(1, n, g, dist);

    return 0;
}