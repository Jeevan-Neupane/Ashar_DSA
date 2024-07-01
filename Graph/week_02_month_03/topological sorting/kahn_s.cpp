#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {

        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
        ans.push_back(node);
    }

    return ans;
}

int main()
{

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