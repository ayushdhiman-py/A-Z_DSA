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
bool checkPalindrome(Node *head)
{
    stack<int> st;
    Node *temp = head;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
}

Node *reverseLinkedList(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool checkPalindrome2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fastt = head;

    while (fastt->next != nullptr && fastt->next->next != NULL)
    {
        slow = slow->next;
        fastt = fastt->next->next;
    }

    Node *newhead = reverseLinkedList(slow->next);
    Node *first;
    Node *second;
    first = head;
    second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLinkedList(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newhead);
    return true;
}

int main()
{
    fast;
    vector<int> arr = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    Node *head = arrtoll(arr);

    // checkPalindrome(head);
    cout << (checkPalindrome2(head) ? "true" : "false");

    return 0;
}