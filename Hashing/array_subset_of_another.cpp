#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[a1[i]]++;
    }

    for (int j = 0; j < m; j++)
    {
        if (mp[a2[j]] == 0)
        {
            return "NO";
        }
        mp[a2[j]]--;
    }

    return "YES";
}

int main()
{
    //     a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
    // a2[] = {11, 3, 7, 1, 7}

    int a1[] = {11, 7, 1, 13, 21, 3, 3};
    int a2[] = {11, 3, 7, 1};

    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    cout << isSubset(a1, a2, n, m) << endl;

    return 0;
}