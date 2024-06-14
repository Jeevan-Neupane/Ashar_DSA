#include <iostream>
#include <unordered_map>
using namespace std;
#include <map>

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{
    // code here
    // return the head of intersection list

    Node *temp = head2;
    unordered_map<int, int> mp;

    while (temp != NULL)
    {
        mp[temp->data]++;
        temp = temp->next;
    }

    Node *newNode = NULL;
    Node *newTemp = NULL;

    temp = head1;

    while (temp != NULL)
    {
        if (mp[temp->data] == 1)
        {

            if (newNode == NULL)
            {
                newNode = new Node(temp->data);
                newTemp = newNode;
            }
            else
            {
                newTemp->next = new Node(temp->data);
                newTemp = newTemp->next;
            }
        }
    }

    return newNode; 
}
Node *findIntersection(Node *head1, Node *head2)
{
    // code here
    // return the head of intersection list
    map<int, int> mp;
    map<int, int> mpOne;

    Node *temp = head1;

    while (temp != NULL)
    {
        mp[temp->data]++;
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        mpOne[temp->data]++;
        temp = temp->next;
    }
    Node *newHead = NULL;
    Node *newtemp = NULL;
    for (auto it : mp)
    {

        if (mpOne[it.first] == 1)
        {
            if (newHead == NULL)
            {
                newHead = new Node(it.first);
                newtemp = newHead;
            }
            else
            {
                newtemp->next = new Node(it.first);
                newtemp = newtemp->next;
            }
        }
    }

    return newHead;
}

int main()
{

    return 0;
}