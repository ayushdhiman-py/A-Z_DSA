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

// BRUTE FORCE
Node *delMid(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        return NULL;
    }

    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    cnt = floor(cnt / 2);
    temp = head;

    while (temp != NULL)
    {
        cnt--;
        if (cnt == 0)
        {
            Node *mid = temp->next;
            temp->next = temp->next->next;
            free(mid);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// BETTER WITH SLOW AND FAST POINTER
Node *betterDelMid(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fastt = head->next->next;
    while (fastt != NULL && fastt->next != NULL)
    {
        slow = slow->next;
        fastt = fastt->next->next;
    }
    auto mid = slow->next;
    slow->next = slow->next->next;
    free(mid);
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
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = arrtoll(arr);
    head = betterDelMid(head);
    print(head);
    return 0;
}