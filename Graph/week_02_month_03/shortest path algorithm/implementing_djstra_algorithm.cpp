#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dis(V, INT16_MAX);
    vector<int> vis(V, 0);
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    pq.push({S, 0});

    dis[S] = 0;

    while (!pq.empty())
    {
        int nodeValue = pq.top().first;
        int distance = pq.top().second;

        vis[nodeValue] = 1;
        pq.pop();

        for (auto it : adj[nodeValue])
        {
            if (vis[it[0]] == 1)
                continue;
            int neighbournode = it[0];
            int neighbourdistance = it[1];

            if (!vis[neighbournode] && distance + neighbourdistance < dis[neighbournode])
            {
                dis[neighbournode] = distance + neighbourdistance;
                pq.push({neighbournode, dis[neighbournode]});
            }
        }
    }

    return dis;
}

int main()
{

    //     V = 3, E = 3
    // adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
    // S = 2

    int V = 3;
    vector<vector<int>> adj[3];

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    vector<int> res = dijkstra(V, adj, 2);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}