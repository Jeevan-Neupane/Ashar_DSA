#include <iostream>
#include <cmath>
using namespace std;

long long power(int num, int pow)
{

    if (pow == 0)
    {
        return 1;
    }

    long long val = power(num, pow / 2);
    if (pow % 2 == 1)
    {
        return val * val * num;
    }
    else
    {
        return val * val;
    }
}

long long smallestNumberWithGivenDigit(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return power(10, n - 1);
    }
}

long long largestNumberWithGivenDigit(int n)
{
    return power(10, n) - 1;
}

int main()
{
    cout << smallestNumberWithGivenDigit(2) << endl;
    cout << largestNumberWithGivenDigit(3) << endl;
}
