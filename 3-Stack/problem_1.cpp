// implement  stack  using  array
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            // space available
            top++;
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            //stack empty
            cout<<"stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
       
        if (top == -1)
        {
            //stack empty
            cout<<"no element in stack"<<endl;
        }
        else{
            return arr[top];
        }
    }

     int getsize(){
       
        
            return top+1;
   
    }
};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(60);
    st.push(80);
    st.push(99);
    st.pop();
    cout<<st.getTop();
    cout<<endl;
    cout<<st.getsize();
}