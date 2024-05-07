#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Stack
{
    int top = -1;
    int size = 0;
    int *stack;

public:
    Stack(int n)
    {
        top = -1;
        size = n;
        stack = new int[size];
    }

public:
    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "element cannot be inserted - " << element << "\n";
            return;
        }
        top++;
        stack[top] = element;
        cout << "element inserted - " << element << "\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "element cannot be popped \n";
            return;
        }
        int element = stack[top];
        top--;
        cout << "element popped - " << element << "\n";
    }

    void Top()
    {
        if (top == -1)
        {
            cout << "element cannot be seen its empty";
            return;
        }
        int element = stack[top];
        cout << "top element - " << element << "\n";
    }

    void Size()
    {
        cout << "size - " << top + 1 << "\n";
    }
};

int main()
{

    fast;

    Stack s(5);
    s.push(6);
    s.push(3);
    s.push(7);
    s.Top();
    s.Size();
    s.pop();
    s.Size();
    s.Top();
    s.pop();
    s.Size();
    s.Top();

    s.pop();
    s.Size();
    s.Top();
    s.push(6);
    s.push(3);
    s.push(7);
    s.push(6);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(7);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.Top();
    s.Size();
    return 0;
}