// will be using 2 queues

#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (!q1.empty())
            q1.pop();
        else
            cout << "its empty!";
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.front();
        }
        return -1;
    }

    bool empty()
    {
        if (q1.empty())
            cout << "its empty!";
        return q1.empty();
    }
};

int main()
{

    fast;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl;

    s.pop();

    cout << "Top element after popping: " << s.top() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}