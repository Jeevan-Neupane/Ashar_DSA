#include <iostream>
#include <vector>
using namespace std;

void reverseIt(vector<int> &v, int low, int high)
{

    for (int i = low; i < high / 2; i++)
    {
        swap(v[i], v[high - i]);
    }
}

void rotateIt(vector<int> &v, int k, int n)
{
    reverseIt(v, 0, k);
    cout << " first reverse: ";
    for (auto i : v)
        cout
            << i << " ";
    cout << endl;
    reverseIt(v, k + 1, n);
    cout << " second reverse: ";
    for (auto i : v)
        cout
            << i << " ";
    cout << endl;
    reverseIt(v, 0, n);
}

vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat)
{
    // code here
    vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));

    for (int i = 0; i < mat.size(); i++)
    {
        rotateIt(mat[i], k, mat[i].size() - 1);

        for (int j = 0; j < mat[i].size(); j++)
        {
            res[i][j] = mat[i][j];
        }
    }

    return res;
}

int main()
{
    // k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]

    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 2;

    vector<vector<int>> res = rotateMatrix(k, mat);

    // for (auto v : res)
    // {
    //     for (auto i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
}