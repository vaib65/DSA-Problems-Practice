// implement queue using array
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    int getFront()
    {
        if (front == rear)
        {
            cout << "queue empty" << endl;
        }
        else
        {
            return arr[front];
        }
    }

    int getSize()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Queue q(10);
    q.push(10);
    q.push(220);
    q.push(30);
    q.push(1);
    q.push(10);
    q.push(220);
    q.push(30);
    q.push(1);
    q.push(10);
    q.push(220);
    q.push(30);
    q.push(1);

    cout<<"size of queue:"<<q.getSize()<<endl;

    q.pop();
    cout<<"size of queue:"<<q.getSize()<<endl;

    cout<<"front element:"<<q.getFront()<<endl;

    cout<<"is empty:"<<q.isEmpty()<<endl;
}