#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue element " << element << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = element;
        cout << "Element " << element << " enqueued successfully." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Element " << arr[front] << " dequeued successfully." << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue are: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6); // Queue is full
    cq.display();
    cq.dequeue();
    cq.enqueue(6); // Queue is full
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue(); // Queue is empty
    cq.display(); // Queue is empty
    return 0;
}
