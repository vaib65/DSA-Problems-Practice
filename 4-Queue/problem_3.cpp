//implement doubly ended queue(called as DEQUEUE) and doubly ended circular queue  
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class doublyEndedQueue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    doublyEndedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        //queue

        //single element case-first element

        //circular queue

        //normal flow

        if((front==0) && (rear==size-1) || front==rear+1){
            cout<<"queue is full"<<endl;
            return;
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

    void pushfront(int data){

        if((front==0) && (rear==size-1) || front==rear+1){
            cout<<"queue is full"<<endl;
            return;
        }
        else if(front==-1){
            front=rear=0;
            
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
            
        }
        else{
            front--;
            
        }
        arr[front]=data;

    }

    void popFront()
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

    void popRear(){
           if(front==-1){
            cout<<"queue empty"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(rear=0){
            rear=rear-1;
        }
        else{
            rear--;
        }

    }
    
};
int main(){
}