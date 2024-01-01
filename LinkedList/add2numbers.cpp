#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Node
{
public:
    int val;
    Node *next;

    Node(int v, Node *n)
    {
        val = v;
        next = n;
    }
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *cnode = dummyNode;
    Node *h1 = l1;
    Node *h2 = l2;
    int carry = 0;
    while (h1 != NULL || h2 != NULL)
    {
        int csum = carry;
        if (h1)
            csum += h1->val;
        if (h2)
            csum += h2->val;
        Node *nextNum = new Node(csum % 10);
        carry = csum / 10;
        cnode->next = nextNum;
        cnode = cnode->next;
        if (h1)
            h1 = h1->next;
        if (h2)
            h2 = h2->next;
    }
    if (carry)
    {
        Node *t = new Node(carry);
        cnode->next = t;
    }
    return dummyNode->next;
}

int main()
{

    fast;

    cout << "name";

    return 0;
}