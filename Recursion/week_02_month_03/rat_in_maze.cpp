#include <iostream>
#include <vector>
using namespace std;

string path(vector<vector<int>> &m, int n, int rPos, int colPos, string p, vector<string> &pathlist)
{
    if (rPos == n - 1 && colPos == n - 1)
    {
        pathlist.push_back(p);
        return p;
    }

    int rDir[] = {-1, 0, 1, 0};
    int cDir[] = {0, -1, 0, 1};
    char dir[] = {'D', 'L', 'U', 'R'};

    for (int i = 0; i < 4; i++)
    {
        int newRowPos = rPos + rDir[i];
        int newColPos = colPos + cDir[i];

        if (newRowPos >= 0 && newRowPos < n && newColPos >= 0 && newColPos < n - 1 && m[newColPos][newRowPos] == 1)
        {
            cout << newRowPos << " " << newColPos << endl;
            p += dir[i];
            path(m, n, newRowPos, newColPos, p, pathlist);
        }
    }

    return "";
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    string p = "";

    vector<string> pathList;

    string ans = path(m, n, 0, 0, p, pathList);

    cout << ans << endl;

    return pathList;
}

int main()
{
    //     N = 4
    // m[][] = {{1, 0, 0, 0},
    //          {1, 1, 0, 1},
    //          {1, 1, 0, 0},
    //          {0, 1, 1, 1}}

    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    int n = 4;

    vector<string> p = findPath(m, n);

    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}