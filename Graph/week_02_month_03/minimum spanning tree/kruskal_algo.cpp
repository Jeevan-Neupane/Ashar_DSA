#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here

    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int weight = it[1];
            int node = i;

            edges.push_back({{node, adjNode}, weight});
        }
    }

    DisjointSet ds(V);

    sort(edges.begin(), edges.end());

    int minimumWeight = 0;

    for (auto it : edges)
    {
        int wt = it.second;
        int u = it.first.first;
        int v = it.first.second;

        int par_u = ds.findUPar(u);
        int par_v = ds.findUPar(v);

        if (par_u != par_v)
        {
            minimumWeight += wt;
            ds.unionByRank(u, v);
        }
    }

    return minimumWeight;
}

int main()
{
    //     3 3
    // 0 1 5
    // 1 2 3
    // 0 2 1

    // First line of the custom input must contain two space separated integers V denoting the number of vertices and E denoting the number of edges. Next E lines contains three space-separated integers denoting each edge and weight between the edges

    // create adjacency list

    int V = 3;
    vector<vector<int>> adj[3];

    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});

    return 0;
}