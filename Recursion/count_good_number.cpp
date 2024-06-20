#include <iostream>
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

bool isPrime(long long n)
{
    // cout << "num prime" << n << endl;

    if (n == 0)
    {
        return false;
    }

    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int lenOfNum(int num)
{
    int len = 0;
    while (num != 0)
    {
        len++;
        num = num / 10;
    }

    return len;
}

bool isGoodNumber(long long num)
{
    int index = lenOfNum(num) - 1;

    // cout << "---------------------" << endl;
    // cout << "num " << num << endl;

    while (num != 0)
    {
        int lastDigit = num % 10;
        // cout << "last digit " << lastDigit << endl;
        // cout << "index " << index << endl;
        if (index % 2 == 1 && !isPrime(lastDigit))
        {
            return false;
        }

        else if (index % 2 == 0 && lastDigit % 2 != 0)
        {
            return false;
        }

        index--;
        num = num / 10;
    }

    // cout << "---------------------" << endl;

    return true;
}

int countGoodNumbers(long long N)
{
    long long largestNum = largestNumberWithGivenDigit(N);

    int count = 0;

    int smallestNum = 0;

    if (N > 1)
    {
        smallestNum = 1;
    }

    cout << largestNum << endl;
    for (long long i = smallestNum; i <= largestNum; i++)
    {

        if (isGoodNumber(i))
        {
            // cout << "num " << i << endl;
            cout << "num " << i << endl;
            count++;
        }
    }

    return count;
}

int main()
{

    cout << countGoodNumbers(4) << endl;
    return 0;
}