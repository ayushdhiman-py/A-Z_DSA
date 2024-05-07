#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Queue
{
    int size = 0;
    int *queue;
    int front;
    int rear;

public:
    Queue(int n)
    {
        size = n;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int ele)
    {
        if (rear == -1)
        {
            front += 1;
            rear += 1;
            queue[rear] = ele;
            cout << "element inserted " << ele << "\n";
        }
        else if (rear == size - 1)
        {
            cout << "queue is full\n";
        }
        else
        {
            rear += 1;
            queue[rear] = ele;
            cout << "element inserted " << ele << "\n";
        }
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "queue is empty\n";
        }
        else if (front == rear)
        {
            int ele = queue[front];
            cout << "element deleted is " << ele << "\n";
            cout << "queue is empty now\n";
            front = -1;
            rear = -1;
        }
        else
        {
            int ele = queue[front];
            cout << "element deleted is " << ele << "\n";
            front++;
        }
    }
    
    int top()
    {
        if (front == -1) {
            cout << "queue is empty\n";
            return -1; 
        }
        return queue[front];
    }

    int Size()
    {
        if (rear == -1 && front == -1)
        {
            return 0;
        }
        return rear - front + 1;
    }
};

int main()
{

    fast;
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    q.push(34);
    q.push(34);
    q.push(34);
    q.push(8);
    cout << "Top of q is " << q.top() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << "Size of q " << q.Size() << endl;
    q.pop();
    q.pop();
    return 0;
}