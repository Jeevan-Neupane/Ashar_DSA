#include <iostream>
#include <vector>
using namespace std;

void getCombination(int i, vector<int> &comb, int target, vector<int> A, vector<vector<int>> &ans, int K)
{
    if (i == A.size())
    {
        if (target == 0)
        {
            if (comb.size() == K)
            {
                ans.push_back(comb);
            }
        }
        return;
    }
    // cout << i << endl;

    if (A[i] <= target)
    {
        // cout << "a[i] " << A[i] << endl;
        comb.push_back(A[i]);
        getCombination(i + 1, comb, target - A[i], A, ans, K);
        comb.pop_back();
    }
    getCombination(i + 1, comb, target, A, ans, K);
}

vector<vector<int>> combinationSum(int K, int N)
{
    // code here
    vector<vector<int>> ans;
    vector<int> comb;
    vector<int> A;
    for (int i = 1; i <= 9; i++)
    {
        A.push_back(i);
    }

    getCombination(0, comb, N, A, ans, K);

    return ans;
}

int main()
{

    vector<vector<int>> ans = combinationSum(3, 9);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}