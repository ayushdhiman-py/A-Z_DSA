#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class q
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    q(int n)
    {
        arr = new int[n];
        capacity = n;
        front = -1;
        rear = -1;
        count = 0;
    }

    void enqueue(int ele)
    {
        if (isFull())
        {
            cout << "Q issfull\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = ele;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Q is Empty\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        count--;
    }

    bool isEmpty() const
    {
        return (count == 0);
    }

    bool isFull() const
    {
        return (count == capacity);
    }

    int size() const
    {
        return count;
    }

    int peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

class Stack
{
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int item)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = item;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        top--;
    }

    int peek() const
    {
        if (isEmpty()==-1)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }

    int size() const
    {
        return top + 1;
    }
};

int main()
{

    fast;
    q q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(6);
    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();


    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Top element is: " << s.peek() << endl;
    s.pop();

    s.push(6);
    cout << "Top element is: " << s.peek() << endl;

    return 0;
}




// algorithm push(item){
//     if(stackisfull){
//         print("stack is full")
//         return false;
//     }
//     arr[++top] = item
//     return true
// }



// algorithm pop(){
//     if(isempty){
//         print("stack empty")
//         return false
//     }
//     return top--;
// }



//  size = 5
// FIFO    

// // jb kuch insert krna hota h to rear++
// // jb kuch delete krna hota h to front++
//               f             r
// index->  -1   0   1    2    3   4
//              --------------------
//               10  20   30  
//              --------------------


// algorithm q_Push_NORMAL(val){
//     if(rear == sizeofQ-1){
//         print("q is full")
//         return false
//     }
//     else{
//         // pehli bar insertion
//         if(rear==-1){
//             front++ 
//             rear=0
//             q[rear]=val
//         }
//         // dusri bar insertion
//         else{
//             rear++
//             q[rear] = val
//         }
//     }
// }

// // delete in normal Q

// algo delete(){
//     if(front==-1){
//         print("q is empty")
//         return false;
//     }
//     else{

//     }
// }


// -----------------------------------------



algo insertAtFront(val){
    if(front==-1){
        front++ rear++
    }
}
