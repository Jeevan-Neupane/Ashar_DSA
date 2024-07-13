#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        input.push(x);
    }

    int dequeue()
    {
        if (input.empty())
        {
            return -1;
        }
        while (input.size() != 1)
        {
            output.push(input.top());
            input.pop();
        }

        int value = input.top();
        input.pop();

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }

        return value;
    }
};

int main()
{

    return 0;
}