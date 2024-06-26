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

Node *getKthNode(Node *temp, int k)
{
    k -= 1;
    while (temp != nullptr && k--)
    {
        temp = temp->next;
    }
    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevNode = NULL;
    while (temp != nullptr)
    {
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == nullptr)
        {
            if (prevNode != NULL)
            {
                prevNode->next = temp;
            }
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLinkedList(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

Node *arrtoll(vector<int> &v)
{
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

int main()
{
    fast;
    vector<int> arr = {9, 2, 3, 5, 0, 6, 1, 8};
    Node *head = arrtoll(arr);
    print(head);
    cout << "\n\n\n";
    head = kReverse(head, 3);
    print(head);

    return 0;
}