/**
 * Grid-Surrounding pattern
 *
 * There are a few questions in which given a grid with 0/1 and we gotta find components(all 0 connected in 4-direction) surrounded by 1s on all sides. Components with a 0 on edge cant be surrounded.
 *
 * In such questions first mark the components which have a node on edges as visited and then count remaining 0s that are not visited.
 *
 * https://leetcode.com/problems/number-of-closed-islands/
 * https://www.interviewbit.com/problems/capture-regions-on-board/
 *
 */

// psuedo code-

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
    //dfs
}
int solve()
{
    // Assuming nxm grid
    vector<vector<int>> grid;
    int n, m;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // dfs/bfs all the nodes on edges

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 'O')
            dfs(i, 0, vis, grid);
        if (grid[i][m - 1] == 'O')
            dfs(i, m - 1, vis, grid);
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O')
            dfs(0, j, vis, grid);
        if (grid[n - 1][j] == 'O')
            dfs(n - 1, j, vis, grid);
    }

    //Now solve the actual question
}

int main()
{
    solve();

    return 0;
}