#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }

    Node(int d, Node *next1)
    {
        data = d;
        next = next1;
    }
};

Node *arrtoll(vector<int> &v)
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    //
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *curr = new Node(v[i]);
        temp->next = curr;
        temp = curr;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node *add1number(Node *head)
{
    head = reverseLinkedList(head);
    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newnode = new Node(carry);
        head = reverseLinkedList(head);
        newnode->next = head;
        return newnode;
    }
    head = reverseLinkedList(head);
    return head;
}

int helpertoadd1(Node *head)
{
    if (head == nullptr)
    {
        return 1;
    }
    int carry = helpertoadd1(head->next);
    head->data += carry;

    if (head->data > 9)
    {
        head->data = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

Node *add1toll(Node *head)
{
    Node *temp = head;
    int carry = helpertoadd1(temp);
    // cout << carry;
    if (carry > 0)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    fast;
    vector<int> arr = {9};
    Node *head = arrtoll(arr);
    head = add1toll(head);
    print(head);

    return 0;
}