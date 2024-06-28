#include <iostream>
#include <vector>
using namespace std;

bool isRowPalindrome(int low, vector<vector<int>> arr, int m)
{
    bool palindrome = true;
    for (int i = 0; i < m / 2; i++)
    {
        if (arr[low][i] != arr[low][m - i - 1])

        {
            palindrome = false;
        }
    }

    return palindrome;
}
bool isColPalindrome(int low, vector<vector<int>> arr, int n)
{
    bool palindrome = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i][low] != arr[n - i - 1][low])

        {
            palindrome = false;
        }
    }

    return palindrome;
}

string pattern(vector<vector<int>> &arr)
{
    // Code Here

    int n = arr.size();
    int m = arr[0].size();

    int rowNo = -1;
    int colNo = -1;
    bool rowPalindrome = false;
    for (int i = 0; i < n; i++)
    {
        if (isRowPalindrome(i, arr, m))
        {
            rowNo = i;

            break;
        }

        if (isColPalindrome(i, arr, m))
        {
            colNo = i;
        }
    }
}

int main()
{

    // arr[][] =  [[1, 0, 0],
    //        [0, 1, 0],
    //        [1, 1, 0]]

    vector<vector<int>> arr = {{1, 0, 0}, {0, 1, 0}, {1, 1, 0}};

    cout << isColPalindrome(0, arr, 3) << endl;
    cout << isRowPalindrome(0, arr, 3) << endl;

    return 0;
}