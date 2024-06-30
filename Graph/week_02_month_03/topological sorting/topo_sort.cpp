#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[])
{
    vis[start] = 1;

    for (int nbr : adj[start])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, s, adj);
        }
    }

    s.push(start);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }
    vector<int> res;
    for (int i = 0; i < V; i++)
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
int main()
{

    //     6 8
    // 6 3
    // 7 3
    // 6 5
    // 3 5
    // 7 1
    // 1 2

    int V = 8;
    vector<int> adj[8];

    adj[6].push_back(3);
    adj[7].push_back(3);
    adj[6].push_back(5);
    adj[3].push_back(5);
    adj[7].push_back(1);
    adj[1].push_back(2);

    vector<int> res = topoSort(V, adj);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}