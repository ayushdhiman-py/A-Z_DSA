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

Node *arrtoll(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *curr = new Node(v[i]);
        mover->next = curr;
        mover = curr;
    }
    return head;
}

Node *deleteFromStart(Node *head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
    return head;
}

Node *deleteFromLast(Node *head)
{
    Node *todelete = head;
    while (todelete->next->next != NULL)
    {
        todelete = todelete->next;
    }
    delete todelete->next;
    todelete->next = NULL;
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

Node *insertAtBegin(int n, Node *head)
{
    Node *temp = new Node(n);
    temp->next = head;
    return temp;
}

Node *insertAtK(int position, Node *head, int ele)
{
    if (head == NULL || head->next == NULL)
        return head;

    if (position == 1)
    {
        return insertAtBegin(ele, head);
    }

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == (position - 1))
        {
            Node *curr = new Node(ele, temp->next);
            temp->next = curr;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    fast;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arrtoll(arr);
    cout << "\n";
    print(head);
    head = deleteFromStart(head);
    cout << "\n";
    print(head);
    head = deleteFromLast(head);
    cout << "\n";
    print(head);
    cout << "\n";
    cout << "\n";
    head = insertAtBegin(1, head);
    print(head);
    cout << "\n";
    head = insertAtK(1, head, 100);
    print(head);
    cout << "\n";

    return 0;
}