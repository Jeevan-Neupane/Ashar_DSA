#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getCombination(int i, vector<int> &comb, int target, vector<int> A, vector<vector<int>> &ans)
{
    if (i == A.size())
    {
        if (target == 0)
        {
            ans.push_back(comb);
        }
        return;
    }

    if (A[i] <= target)
    {
        comb.push_back(A[i]);

        getCombination(i, comb, target - A[i], A, ans);
        comb.pop_back();
    }
    getCombination(i + 1, comb, target, A, ans);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    // Your code here
    vector<vector<int>> ans;
    vector<int> comb;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    getCombination(0, comb, B, A, ans);

    // sort ans according to the ascending order
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     sort(ans[i].begin(), ans[i].end());
    // }
    // sort(ans.begin(), ans.end());
    // // sort each vector of ans
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     sort(ans[i].begin(), ans[i].end());
    // }
    // remove duplicates

    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main()
{

    vector<int> A = {7, 2, 6, 5};

    vector<vector<int>> ans = combinationSum(A, 16);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}