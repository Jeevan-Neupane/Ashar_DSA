#include <iostream>
#include <vector>
using namespace std;

int possibleValue(vector<int> adj[], int s, int e, int &count)
{
    cout << s << " ";
    if (s == e)
    {
        count++;
        return count;
    }

    if (adj[s].size() == 0)
    {
        return count;
    }

    for (int i = 0; i < adj[s].size(); i++)
    {
        possibleValue(adj, adj[s][i], e, count);
    }

    return count;
}

int possible_paths(vector<vector<int>> edges, int n, int s, int d)
{
    // Code here
    vector<int> adj[10];

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    // print adj
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "trace back path " << endl;
    int count = 0;

    int value = possibleValue(adj, s, d, count);

    // cout << value << endl;

    return value;
}

int main()
{

    //    8 22 4 3
    // 0 2
    // 0 3
    // 0 4
    // 0 6
    // 0 7
    // 1 3
    // 1 5
    // 1 6
    // 1 7
    // 2 3
    // 2 4
    // 2 5
    // 2 6
    // 3 4
    // 3 6
    // 3 7
    // 4 5
    // 4 6
    // 4 7
    // 5 6
    // 5 7
    // 6 7

    vector<vector<int>> edges = {{0, 2}, {0, 3}, {0, 4}, {0, 6}, {0, 7}, {1, 3}, {1, 5}, {1, 6}, {1, 7}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 6}, {3, 7}, {4, 5}, {4, 6}, {4, 7}, {5, 6}, {5, 7}, {6, 7}};

    int n = 8;
    int s = 4;
    int d = 3;

    cout << possible_paths(edges, n, s, d) << endl;

    return 0;
}