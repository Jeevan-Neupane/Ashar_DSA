#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<int> vis(n + 1, 0);
    vector<int> minDis(n + 1, INT16_MAX);
    minDis[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({1, 0});

    // create a adjacency list with weight using vector only no array

    


    while (!pq.empty())
    {
        int node = pq.top().first;
        int weight = pq.top().second;
        vis[node] = 1;
        pq.pop();

        for (auto it : edges[node])
        {
        }
    }
}

int main()
{

    // Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]

    int n = 5;
    int m = 6;

    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> res = shortestPath(n, m, edges);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}