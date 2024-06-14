#include <iostream>
#include <cmath>
using namespace std;

int countDigit(int n)
{
    int count = 0;
    
    while (n != 0)
    {
        count++;
        n = n / 10;
    }

    return count;
}

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int ans = power(n, p / 2);

    if (p % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return ans * ans * n;
    }
}

string armstrongNumber(int n)
{
    // code here
    int digitcount = countDigit(n);
    // cout << digitcount << endl;

    int num = n;
    int sum = 0;
    while (num != 0)
    {
        int lastDigit = num % 10;
        sum += power(lastDigit, digitcount);
        // cout << sum << endl;
        num = num / 10;
    }

    if (sum == n)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main()
{
    cout << armstrongNumber(152) << endl;

    return 0;
}