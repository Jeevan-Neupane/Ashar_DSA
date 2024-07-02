#include <iostream>
#include <vector>
using namespace std;

void findPath(vector<vector<int>> &grid, int srcRow, int srcCol, int endRow, int endCol, vector<vector<int>> &vis, int n, int m, int &moves, int &ans)
{
    if (srcRow == endRow && srcCol == endCol)
    {
        // cout << "moves: " << moves << endl;
        // cout << "reached destination" << endl;
        ans = min(ans, moves);

        return;
    }

    vis[srcRow][srcCol] = 1;

    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int rowMove = srcRow + rowDir[i];
        int colMove = srcCol + colDir[i];

        if (rowMove >= 0 && rowMove < n && colMove >= 0 && colMove < m && vis[rowMove][colMove] != 1 && grid[rowMove][colMove] == 1)
        {
            findPath(grid, rowMove, colMove, endRow, endCol, vis, n, m, moves = moves + 1, ans);
            vis[rowMove][colMove] = 0;
            moves = moves - 1;
        }
    }
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    // code here
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

    int moves = 0;
    int ans = INT16_MAX;
    findPath(grid, startRowIndex, startColIndex, endRowIndex, endColumnIndex, vis, n, m, moves, ans);

    if (ans == INT16_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{

    //     grid[][] = {{1, 1, 1, 1},
    //             {1, 1, 0, 1},
    //             {1, 1, 1, 1},
    //             {1, 1, 0, 0},
    //             {1, 0, 0, 1}}
    // source = {0, 1}
    // destination = {2, 2}

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