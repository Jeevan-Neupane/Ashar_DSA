#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateAll(int k, int n, char str[], vector<string> &ans)
{

    if (n == k)
    {
        str[n] = '\0';
        ans.push_back(str);
        return;
    }

    if (str[n - 1] == '1')
    {
        str[n] = '0';
        generateAll(k, n + 1, str, ans);
    }
    if (str[n - 1] == '0')
    {
        str[n] = '0';
        generateAll(k, n + 1, str, ans);
        str[n] = '1';
        generateAll(k, n + 1, str, ans);
    }
}

vector<string> generateString(int k)
{

    char str[13];
    vector<string> v;
    str[0] = '1';

    generateAll(k, 1, str, v);

    str[0] = '0';
    generateAll(k, 1, str, v);

    sort(v.begin(), v.end());

    return v;
}

int main()
{
    vector<string> ans = generateString(13);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}