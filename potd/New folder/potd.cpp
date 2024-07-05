#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int verticalWidth(Node *root)
{
    // code here
    int cnt = 0;
    if (root == NULL)
        return cnt;
    queue<pair<Node *, int>> q;
    unordered_set<int> st;
    q.push({root, 0});
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *node = q.front().first;
            int ver = q.front().second;
            q.pop();
            if (st.find(ver) == st.end())
            {
                cnt++;
            }
            st.insert(ver);
            if (node->left)
            {
                q.push({node->left, ver - 1});
            }
            if (node->right)
            {
                q.push({node->right, ver + 1});
            }
        }
    }
    return cnt;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    cout << verticalWidth(root) << endl;

    

    return 0;
}