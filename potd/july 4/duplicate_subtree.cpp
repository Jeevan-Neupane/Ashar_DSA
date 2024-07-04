#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

unordered_map<string, int> mp;
vector<Node *> subtrees;

string func(Node *root)
{
    // we will use preorder travsersal
    string s = "";
    // for
    if (root == NULL)
        return ("N");

    string leftAns = func(root->left);

    string rightAns = func(root->right);

    s = leftAns + "," + to_string(root->data) + "," + rightAns;

    if (mp[s] == 1)
    {
        // cout<<" subtrree found at node"<<root->data<<endl;
        subtrees.push_back(root);
    }

    mp[s]++;

    return s;
}
vector<Node *> printAllDups(Node *root)
{
    func(root);
    return subtrees;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->left = new Node(2);

    root->right->left->left = new Node(4);

    root->right->right = new Node(4);

    vector<Node *> res = printAllDups(root);

    for (Node *node : res)
    {
        cout << node->data << " ";
    }

    return 0;
}