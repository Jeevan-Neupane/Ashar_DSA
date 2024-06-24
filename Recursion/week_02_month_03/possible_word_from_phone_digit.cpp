#include <iostream>
#include <vector>
using namespace std;

void allString(vector<string> &str, vector<char> arr)
{
    if (str.size() == 0)
    {
        string word = "";
        for (int i = 0; i < arr.size(); i++)
        {

            word = "";
            word += arr[i];
            str.push_back(word);
        }
    }
    else
    {
        int n = str.size();
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < arr.size(); j++)
            {
                string outerString = str[i];
                outerString += arr[j];
                cout << outerString << endl;
                str.push_back(outerString);
            }
        }
        str.erase(str.begin(), str.begin() + n);
    }
}

vector<string> possibleWords(int a[], int N)
{
    // Your code here
    vector<vector<char>> keypad = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> str;

    // for (int i = 0; i < keypad[2].size(); i++)
    // {
    //     cout << keypad[2][i] << " ";
    // }

    for (int i = 0; i < N; i++)
    {
        cout << i << endl;
        allString(str, keypad[a[i]]);
    }

    return str;
}

int main()
{
    int a[] = {2, 3, 4};
    int N = sizeof(a) / sizeof(a[0]);

    vector<string> result = possibleWords(a, N);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}