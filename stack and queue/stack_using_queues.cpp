#include <iostream>
#include <queue>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code
    q1.push(x);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    if (q1.empty())
    {
        return -1;
    }
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        cout << "Q2: " << q2.front() << endl;
        q1.pop();
    }

    int value = q1.front();
    q1.pop();
    cout << "Value: " << value << endl;

    while (!q2.empty())
    {
        q1.push(q1.front());
        cout << "Q1: " << q1.front() << endl;
        q2.pop();
    }

    return value;
}

int main()
{

    QueueStack *qs = new QueueStack();
    qs->push(1);
    qs->push(2);

    cout << qs->pop() << endl;
    cout << qs->pop() << endl;

    return 0;
}