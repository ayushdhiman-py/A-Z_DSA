#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Queue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        while (!s1.empty())
        {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
            cout << "pushed from 1 to 2-> " << ele << "\n";
        }
        s1.push(x);
        cout << "pushed " << x << "\n";
        while (!s2.empty())
        {
            int ele = s2.top();
            s2.pop();
            s1.push(ele);
            cout << "pushed from 2 to 1-> " << ele << "\n";
        }
    }
    void pop()
    {
        if (!s1.empty())
        {
            int ele = s1.top();
            cout << "element popped-> " << ele << "\n";
            s1.pop();
        }
        else
        {
            cout << "queue is empty\n";
        }
    }
    int top()
    {
        if (!s1.empty())
            return s1.top();
        else
        {
            cout << "its empty\n";
            return -1;
        }
    }
};

int main()
{

    fast;
    Queue q;

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
    q.pop();

    return 0;
}