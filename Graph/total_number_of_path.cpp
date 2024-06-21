#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findTheNeighbourOne(int row, int col, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &vis)
{
    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, -1, 0, 1};
    int count = 0;
    // cout << grid[row][col] << endl;

    queue<pair<int, int>> q;
    bool inBoundary = false;

    q.push({row, col});
    vis[row][col] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        // cout << "r: " << r << " c: " << c << endl;

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
        {
            inBoundary = true;
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rIndex = r + rowDir[i];
            int cIndex = c + colDir[i];

            if (rIndex >= 0 && rIndex < n && cIndex >= 0 && cIndex < m && grid[rIndex][cIndex] == 1 && vis[rIndex][cIndex] == 0)
            {

                vis[rIndex][cIndex] = 1;
                count++;
                q.push({rIndex, cIndex});
            }
        }
    }

    if (inBoundary)
    {
        return 0;
    }
    return count + 1;
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here

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

    int maxValue = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                int ans = findTheNeighbourOne(i, j, grid, n, m, vis);
                // cout << "ans: " << ans << endl;
                maxValue = max(ans, maxValue);
            }
        }
    }

    return maxValue;
}

int main()
{

    // grid[][] = {{0, 0, 0, 0},
    //         {1, 0, 1, 0},
    //         {0, 1, 1, 0},
    //         {0, 0, 0, 0}}

    vector<vector<int>> grid = {{0, 0, 0, 1},
                                {0, 1, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 1},
                                {0, 1, 1, 0}};

    cout << numberOfEnclaves(grid) << endl;
    return 0;
}