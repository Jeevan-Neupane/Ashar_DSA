#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *removeAllDuplicates(struct Node *head)
{
    Node *left = head;
    Node *right = head;
    int i = 0, j = 0;

    Node *temp = new Node(-1);
    Node *result = temp;

    while (right != NULL)
    {
        while (right != NULL && right->data == left->data)
        {
            right = right->next;
            j++;
        }
        if (j - i == 1)
        {
            temp->next = left;
            temp = temp->next;
        }
        left = right;
        i = j;
    }

    temp->next = NULL;
    return result->next;
}

int main()
{

    Node *head = new Node(1);

    head->next = new Node(2);

    head->next->next = new Node(2);

    head->next->next->next = new Node(3);

    head->next->next->next->next = new Node(3);


    Node *result = removeAllDuplicates(head);

    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}