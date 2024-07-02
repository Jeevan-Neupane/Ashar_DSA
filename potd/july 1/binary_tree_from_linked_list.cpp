#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createTree(vector<int> v, int i)
{
    if (i >= v.size())
    {
        return NULL;
    }

    TreeNode *newNode = new TreeNode();
    newNode->data = v[i];
    newNode->left = createTree(v, 2 * i + 1);
    newNode->right = createTree(v, 2 * i + 2);

    return newNode;
}

void convert(Node *head, TreeNode *&root)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    root = createTree(arr, 0);
}

int main()
{

    return 0;
}