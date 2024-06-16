#include <iostream>
#include <cmath>
using namespace std;

void findPrime(int n, bool isPrime[])
{
    isPrime[0] = false;
    isPrime[1] = false;
    

    for (int i = 2; i < sqrt(n); i++)
    {
        if (isPrime[i])
        {
            for (int p = 2; p < n; p++)
            {
                int out = p * i;
                if (out > n)
                    break;
                isPrime[out] = false;
            }
        }
    }
}

int main()
{
    int n = 54;

    bool isPrime[100];

    for (int i = 0; i < n; i++)
    {
        isPrime[i] = true;
    }

    findPrime(n, isPrime);

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}