#include <iostream>
#include <unordered_map>
using namespace std;

int findDiff(int arr[], int n)
{

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        mp[arr[i]]++;
    }

    int max = INT16_MIN;
    int min = INT16_MAX;

    for (auto it : mp)
    {
        if (it.second < min)
        {
            min = it.second;
        }

        if (it.first > max)
        {
            max = it.second;
        }
    }
    cout << "max " << max << endl;
    cout << "min " << min << endl;
    return max - min;
}


int main()
{
    int arr[] = {5, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findDiff(arr, n) << endl;
    return 0;
}