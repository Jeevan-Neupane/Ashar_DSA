#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "5/6, 11/45";

    int a = stoi(str.substr(0, str.find('/')));
    int b = stoi(str.substr(str.find('/') + 1, str.find(',')));

    int c = stoi(str.substr(str.find(',') + 1, str.find('/', str.find(',') + 1)));
    int d = stoi(str.substr(str.find('/', str.find(',') + 1) + 1));

    if (a * d > b * c)
    {
        cout << to_string(a) + '/' + to_string(b) << endl;
    }
    else
    {
        cout << c / d << endl;
    }

    return 0;
}