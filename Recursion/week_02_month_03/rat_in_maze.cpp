#include <iostream>
#include <vector>
using namespace std;

void path(vector<vector<int>> &m, int n, int rPos, int colPos, vector<char> ans, vector<vector<char>> &pathlist, vector<vector<int>> &vis)

{
    // cout << " i am here" << rPos << " " << colPos << endl;
    if (rPos == n - 1 && colPos == n - 1)
    {
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        pathlist.push_back(ans);
        return;
    }

    int rDir[] = {-1, 0, 1, 0};
    int cDir[] = {0, -1, 0, 1};

    char dir[] = {'U', 'L', 'D', 'R'};

    for (int i = 0; i < 4; i++)
    {
        int newRowPos = rPos + rDir[i];
        int newColPos = colPos + cDir[i];

        if (newRowPos >= 0 && newRowPos < n && newColPos >= 0 && newColPos < n && m[newRowPos][newColPos] == 1 && vis[newRowPos][newColPos] == 0)
        {
            ans.push_back(dir[i]);
            vis[newRowPos][newColPos] = 1;
            // cout << dir[i] << endl;
            // cout << "i am here" << newRowPos << " " << newColPos << endl;
            path(m, n, newRowPos, newColPos, ans, pathlist, vis);
            vis[newRowPos][newColPos] = 0;
            ans.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    string p = "";

    if (m[0][0] == 0)
    {
        return {"-1"};
    }
    vector<vector<char>> pathList;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    visited[0][0] = 1;

    vector<char> ans;

    path(m, n, 0, 0, ans, pathList, visited);

    vector<string> pathString;

    for (int i = 0; i < pathList.size(); i++)
    {
        string s = "";
        for (int j = 0; j < pathList[i].size(); j++)
        {
            s += pathList[i][j];
        }
        pathString.push_back(s);
    }

    if (pathString.size() == 0)
        pathString.push_back("-1");

    return pathString;
}

int main()
{
    //     4
    // 0 1 1 1 1 1 1 0 1 0 1 1 0 0 1 1

    vector<vector<int>> m = {{1, 0, 1, 1},
                             {0, 0, 0, 1},
                             {0, 1, 0, 0},
                             {1, 1, 1, 1}};

    int n = 4;

    vector<string> p = findPath(m, n);

    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}