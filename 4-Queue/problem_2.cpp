//implement circular queue using array
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class circularQueue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    circularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        //queue

        //single element case-first element

        //circular queue

        //normal flow

        if((front==0) && (rear==size-1) || front==rear+1){
            cout<<"queue is full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
        
    }

    void pop()
    {
        //queue empty
        //single element pop
        //circular queue
        //normal flow
        if(front==-1){
            cout<<"queue empty"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
    
};
int main(){
}