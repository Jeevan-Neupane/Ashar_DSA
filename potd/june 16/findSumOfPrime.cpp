#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime[100] = {true};
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

vector<int> getPrimes(int n)
{
    vector<int> ans;
    bool isPrime[100];

    for (int i = 0; i < n; i++)
    {
        isPrime[i] = true;
    }
    findPrime(n, isPrime);

    for (int i = n / 2; i >= 0; i--)
    {
        int y = n - i;
        if (isPrime[y] && isPrime[i])
        {
            ans.push_back(i);
            ans.push_back(y);
        }
    }

    if (ans.size() == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;
}
int main()
{
    int n = 72;

    vector<int> ans = getPrimes(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}