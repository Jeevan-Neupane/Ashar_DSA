#include <iostream>
#include <vector>
using namespace std;

void allSubset(vector<int> arr, int idx, int sum, vector<int> &sumSub)
{

    if (idx == arr.size())
    {

        sumSub.push_back(sum);
        return;
    }

    sum += arr[idx];
    allSubset(arr, idx + 1, sum, sumSub);
    sum -= arr[idx];
    allSubset(arr, idx + 1, sum, sumSub);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    // Write Your Code here
    vector<int> sumSubset;
    allSubset(arr, 0, 0, sumSubset);
    return sumSubset;
}

int main()
{
    vector<int> arr = {2, 3};
    vector<int> sumSubset = subsetSums(arr, arr.size());

    for (int i = 0; i < sumSubset.size(); i++)
    {
        cout << sumSubset[i] << " ";
    }

    return 0;
}