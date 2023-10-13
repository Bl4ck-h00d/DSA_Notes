#include <bits/stdc++.h>

using namespace std;

class DSU
{

public:
    vector<int> parent;
    vector<int> rank; //stores the height of the tree
    DSU(int n)`
    {
        parent.resize(n, -1);
        rank.resize(n, 0);
    }

    int findParent(int node);
    void unionNode(int u, int v);
};

//path compression
int DSU::findParent(int node){
    if(parent[node]==-1)
        return node;

    return parent[node] = findParent(parent[node]);
}

/**
 * if (rank[u]==rank[v])
 * {
 *      parent[u]=v OR parent[v]=u
 *      rank[v]++ OR rank[u]++; // only time when rank updates
 * }
 *
 */

void DSU::unionNode(int u, int v) {

    int parU = findParent(u);
    int parV = findParent(v);

    if(parU==parV)
        return;
    
    else{

        if(rank[u]==rank[v])
        {
            parent[u] = v;
            rank[v]++;
        }
        else if(rank[u]<rank[v])
        {
            //bade mein chota add krna hai
            //rank update nyi hogi
            parent[u] = v;
        }
        else{
            parent[v] = u;
        }
    }
}

int main()
{
    return 0;
}



/******************************************************************************************************************************/


/**
 * REVERSE DSU-
 * 
 * In some questions we need to to do reverse DSU
 * 
 * Question Type- 
 *  There is an entity where you have to add/remove some items in N steps and output the final state.
 * 
 *  -> Try solving questions forward if cant think of dsu soln going forward. Try applying it backward
 * 
 *  -> Try to generate the final State by applying all state at once. 
 *  -> Now, do the reverse operations. If question was to remove item then add items back and try applying DSU.
 * 
 * 
*/


/**
 * NOTE- In Graphs, it is easy to join/combine things to make something but it is very hard to dynamically disconnect/remove items form graph. In such type of questions try going backwards (add stuff)
 * 
*/