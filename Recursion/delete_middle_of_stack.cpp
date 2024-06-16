#include <iostream>
#include <stack>
using namespace std;

void deleteIt(stack<int> &s, int mid, int i)

{
    if (i == mid)
    {
        s.pop();
        return;
    }

    int a = s.top();
    s.pop();
    deleteIt(s, mid, i + 1);
    s.push(a);
}

void printStack(stack<int> s)
{

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

void deleteMid(stack<int> &s, int sizeOfStack)
{
    // code here..
    int middle = sizeOfStack / 2;
    // printStack(s);

    deleteIt(s, middle, 0);
    // printStack(s);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    deleteMid(s, s.size());

    return 0;
}