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

    Node(int d, Node *next1)
    {
        data = d;
        next = next1;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *oddeven(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even->next != NULL || even != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    fast;
    ;

    return 0;
}