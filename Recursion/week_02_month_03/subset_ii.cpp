#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void findAllSubset(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &subset)
{

    if (idx == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    subset.push_back(nums[idx]);
    findAllSubset(nums, idx + 1, ans, subset);
    subset.pop_back();
    findAllSubset(nums, idx + 1, ans, subset);
}

vector<vector<int>> printUniqueSubsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    vector<int> subset;

    findAllSubset(nums, 0, ans, subset);

    set<vector<int>> s(ans.begin(), ans.end());

    ans.assign(s.begin(), s.end());

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // 4 4 4 1 4
    vector<int> nums = {4, 4, 4, 1, 4};
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans = printUniqueSubsets(nums);

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "size " << ans[i].size() << endl;
    }

    return 0;
}