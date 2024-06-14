#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // code here

    int num1 = b, num2 = a;

    if (a > b)
    {
        num1 = a;
        num2 = b;
    }

    while (num2 != 0)
    {
        int q = num1 / num2;
        int rem = num1 % num2;

        num1 = num2;
        num2 = rem;
    }

    return num1;
}

int main()
{

    cout << gcd(12, 3) << endl;

    return 0;
}