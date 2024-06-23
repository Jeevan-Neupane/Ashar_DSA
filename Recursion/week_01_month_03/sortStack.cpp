#include <iostream>
#include <stack>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void sortedInsert(stack<int> &s, int elm)
{
    if (s.empty() || elm > s.top())
    {
        s.push(elm);
    }
    else
    {
        int temp = s.top();
        s.pop();
        sortedInsert(s, elm);
        s.push(temp);
    }
}

void sortStack(stack<int> &s)

{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
}

void SortedStack ::sort()
{
    sortStack(s);
}

int main()
{

    return 0;
}