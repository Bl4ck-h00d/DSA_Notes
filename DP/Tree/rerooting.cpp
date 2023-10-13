//Check notes copy

/**
 * Questions-
 * CSES- Tree dist 1,2
 * https://leetcode.com/problems/minimum-height-trees/
 *
 */

#include <bits/stdc++.h>
using namespace std;

int depth[200001];
int ans[200001];

void solve(int node, int parent, int partialAns, vector<int> g[])
{

    vector<int> prefix, suffix;

    // get the depth of each child node
    for (auto child : g[node])
    {
        if (child != parent)
        {
            prefix.push_back(depth[child]);
            suffix.push_back(depth[child]);
        }
    }

    // build prefix and suffix
    for (int i = 1; i < prefix.size(); i++)
    {
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }
    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }

    // for current node, 
    ans[node] = 1 + max(partialAns, prefix.size() > 0 ? prefix.back() : -1);

    //Calculate partialAns for child nodes considering curr node as parent
    // calculate partailAns for node considering each child doesnt exist;
    // This will be used in child nodes
    int childNo = 0;
    for (auto child : g[node])
    {
        if (child != parent)
        {
            int op1 = childNo == 0 ? INT_MIN : prefix[childNo - 1];
            int op2 = childNo == suffix.size() - 1 ? INT_MIN : suffix[childNo + 1];
            int partial = 1 + max({op1, op2, partialAns}); // paritalAns-> partial ans of parent considering node not present

            //The calculated partial will be used by curr child node.
            solve(child, node, partial, g);
            childNo++;
        }
    }

   
}
void eval_depth(int node, int parent, vector<int> g[])
{
    int d = 0;

    for (auto child : g[node])
    {
        if (child != parent)
        {
            eval_depth(child, node, g);
            d = max(d, 1 + depth[child]);
        }
    }

    depth[node] = d;
}
int main()
{
    int n;
    cin >> n;

    vector<int> g[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //get depth of each node (depth-> max subtree height)
    eval_depth(1, 0, g);

    solve(1, 0, -1, g);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

