#include <iostream>
#include <vector>
using namespace std;

bool isToepliz(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < n && j + 1 < m)
            {
                if (mat[i][j] != mat[i + 1][j + 1])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    // mat = [[6, 7, 8],
    //    [4, 6, 7],
    //    [1, 4, 6]]

    vector<vector<int>> mat = {{6, 7, 8}, {4, 7, 7}, {1, 4, 6}};

    cout << isToepliz(mat) << endl;

    return 0;
}