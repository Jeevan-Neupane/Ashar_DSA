#include<iostream>
#include<vector>
#include<queue>
using namespace std;


 int spanningTree(int N, vector<vector<int>> adj[])
    {
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<int> visited(N, 0);

    pq.push({0, {0, -1}});

    vector<vector<int>> V(N);
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if (visited[node] == 1)
        {
            continue;
        }
        visited[node] = 1;
        sum += weight;
        V.push_back({node, parent});

        vector<vector<int>> v = adj[node];

        for (int i = 0; i < v.size(); i++)
        {
            int edge_weight = v[i][1];
            int next_vertex = v[i][0];
            pq.push({edge_weight, {next_vertex, node}});
        }
    }

    return sum;
    }


int main(){

    int N = 5;
    vector<vector<int>> adj[5];
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});

    adj[4].push_back({2, 7});

    cout<<spanningTree(N, adj);

    



    return 0;
}