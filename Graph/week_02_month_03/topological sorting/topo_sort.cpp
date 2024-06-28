#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        st.push(i);

        while (!st.empty())
        {
            int node = st.top();
            vis[node] = 1;

            if (adj[node].size() == 0)
            {
                break;
            }

            st.pop();

            for (auto it : adj[node])
            {
                if (vis[it] != 1)
                {
                    st.push(it);
                }
            }
        }
    }
}

int main()
{

    return 0;
}