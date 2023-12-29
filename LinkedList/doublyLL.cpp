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
    Node *prev;

    Node(int d, Node *nxt, Node *prv)
    {
        data = d;
        next = nxt;
        prev = prv;
    }

    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node *arrtoDll(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *prev = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *curr = new Node(v[i], nullptr, prev);
        prev->next = curr;
        prev = curr;
    }
    return head;
}

Node *deleteFirstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    head = head->next;
    head->prev = nullptr;
    curr->next = nullptr;
    delete curr;
    return head;
}

Node *deleteEnd(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = nullptr;
    temp->prev = nullptr;
    delete temp;
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

void printDoublyLinkedList(Node *head)
{
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->prev;
    cout << temp->data << " ";
    temp = temp->prev;
    cout << temp->data << " ";
    temp = temp->prev;
    cout << endl;
}

Node *removeKthEle(Node *head, int k)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->prev;
    Node *next = temp->next;

    if (prev == NULL && next == NULL)
    {
        return nullptr;
    }
    else if (prev == nullptr)
        return deleteFirstNode(head);
    else if (next == nullptr)
        return deleteEnd(head);

    prev->next = temp->next;
    next->prev = temp->prev;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;
    return head;
}

Node *insertAtHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    newHead->prev = nullptr;
    return newHead;
}

Node *reverseLL(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *lastNode = head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }

    head = lastNode;
    return head;
}

int main()
{

    fast;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arrtoDll(arr);
    print(head);
    cout << "\n";
    head = deleteFirstNode(head);
    print(head);
    cout << "\n";
    head = deleteEnd(head);
    print(head);
    cout << "\n";
    head = removeKthEle(head, 2);
    print(head);
    cout << "\n";
    head = insertAtHead(head, 111);
    head = insertAtHead(head, 222);
    head = insertAtHead(head, 333);
    print(head);
    
    // printDoublyLinkedList(head);
    // cout << "\n";
    // head = reverseLL(head);
    cout << "\n";
    return 0;
}