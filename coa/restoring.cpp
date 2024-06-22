#include <iostream>
using namespace std;
// write restoring algorithm division for number entered in binary 

int main()
{
    int n;
    cout << "Enter the number in binary: ";
    cin >> n;
    int q = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int i = 0;
    while (n != 0)
    {
        a = n % 10;
        n = n / 10;
        b = n % 10;
        if (a == 1)
        {
            q = q + pow(2, i);
        }
        i++;
    }
    cout << "The number in decimal is: " << q;
    return 0;
}