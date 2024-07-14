#include <iostream>
#include <stack>
using namespace std;

bool ispar(string x)
{
    // Your code here
    cout << "--------------------------------" << endl;
    stack<char> st;

    for (int i = 0; i < x.length(); i++)
    {
        if ((x[i] == ')' || x[i] == '}' || x[i] == ']') && st.empty())
        {
            return false;
        }
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
        {
            // cout << x[i] << endl;
            st.push(x[i]);
        }
        else if (x[i] == ')' && st.top() == '(' || x[i] == '}' && st.top() == '{' || x[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "{([])}";
    cout << ispar(s);

    return 0;
}