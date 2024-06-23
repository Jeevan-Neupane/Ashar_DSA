#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permute(string s, int l, int r, vector<string> &ans)
{

    if (l == r)
    {
        // cout << "added s " << s << endl;
        ans.push_back(s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            // cout << "before s " << s << endl;
            swap(s[l], s[i]);
            // cout << "after s " << s << endl;
            permute(s, l + 1, r, ans);
            swap(s[l], s[i]);
        }
    }
}

vector<string> find_permutation(string S)
{
    // Code here there
    vector<string> ans;

    permute(S, 0, S.length() - 1, ans);

    // return the unique value in ans
    set<string> s(ans.begin(), ans.end());
    ans.assign(s.begin(), s.end());

    return ans;
}

int main()
{

    string S = "ABB";

    vector<string> ans = find_permutation(S);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}