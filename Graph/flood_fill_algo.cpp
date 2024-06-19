#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here

    int intialColor = image[sr][sc];
    int colMov[] = {-1, 0, 1, 0};
    int rowMov[] = {0, -1, 0, 1};
    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> q;

    q.push({sr, sc});
    image[sr][sc] = newColor;

    while (!q.empty())
    {
        int rIndex = q.front().first;
        int cIndex = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrIndex = rIndex + rowMov[i];
            int ncIndex = cIndex + colMov[i];

            if (nrIndex >= 0 && nrIndex < n && ncIndex >= 0 && ncIndex < m && image[nrIndex][ncIndex] == intialColor && image[nrIndex][ncIndex] != newColor)
            {
                image[nrIndex][ncIndex] = newColor;
                q.push({nrIndex, ncIndex});
            }
        }
    }

    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 0, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> res = floodFill(image, sr, sc, newColor);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}