//implement 2 stack in one array
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1= -1;
        top2=size;
    }
    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
              // space not available
            cout << "stack overflow" << endl;
           
        }
        else
        {
             // space available
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            //stack empty
            cout<<"stack  1 underflow"<<endl;
        }
        else{
            top1--;
        }
    }

    void push2(int data){
        if (top2 - top1 == 1)
        {
              // space not available
            cout << "stack overflow in stack 2" << endl;
           
        }
        else
        {
             // space available
            top2--;
            arr[top2] = data;
        }

    }

    void pop2()
    {
        if (top2 == size)
        {
            //stack empty
            cout<<"stack 2 underflow"<<endl;
        }
        else{
            top2++;
        }
    }
};
int main(){
}