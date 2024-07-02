#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    // code here
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }

    int startRowIndex = source.first;
    int startColIndex = source.second;

    int endRowIndex = destination.first;
    int endColumnIndex = destination.second;

    vis[startRowIndex][startColIndex] = 1;

    q.push({0, {startRowIndex, startColIndex}});

    int colDir[] = {-1, 0, 1, 0};
    int rowDir[] = {0, -1, 0, 1};
    int moves = 0;

    while (!q.empty())
    {
        int rowIndex = q.front().second.first;
        int colIndex = q.front().second.second;
        moves = q.front().first;
        // cout << rowIndex << " " << colIndex << endl;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = rowIndex + rowDir[i];
            int newCol = colIndex + colDir[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newRow < m && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
            {
                q.push({moves + 1, {newRow, newCol}});
                vis[newRow][newCol] = 1;

                if (newRow == endRowIndex && newCol == endColumnIndex)
                {
                    return moves + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    cout << shortestPath(grid, source, destination);

    return 0;
}