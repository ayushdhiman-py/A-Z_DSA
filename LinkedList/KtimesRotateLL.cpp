#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int d)
    {
        data = d;
        next = NULL;
    }

    ListNode(int d, ListNode *next1)
    {
        data = d;
        next = next1;
    }
};

ListNode *arrtoll(vector<int> &v)
{
    ListNode *head = new ListNode(v[0]);
    ListNode *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *curr = new ListNode(v[i]);
        temp->next = curr;
        temp = curr;
    }
    return head;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findlength(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

ListNode *rotate(ListNode *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    ListNode *temp = head;
    int len = findlength(head);
    k = k % len;
    if (k == 0)
        return head;

    int pos = len - k - 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = temp->next;
    while (pos--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}
int main()
{
    fast;
    vector<int> arr = {9, 2, 3, 5, 0, 6, 1, 8};
    ListNode *head = arrtoll(arr);
    print(head);
    cout << "\n\n\n";
    head = rotate(head, 3);
    print(head);

    return 0;
}