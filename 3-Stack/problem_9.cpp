//reverse a stack
#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
void insertAtBottom(stack<int>&s,int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    // rec
    insertAtBottom(s, target);
    // backtrack
    s.push(topElement);
   
}

void reverseStack(stack<int>&s){
    if(s.empty()){
        cout<<"stack empty"<<endl;
        return;
    }
    int target = s.top();
    s.pop();
    
    //rec
    reverseStack(s);
    insertAtBottom(s,target);
}
int main(){
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(220);
    s.push(208);
    s.push(10);
    s.push(2);

  
    reverseStack(s);
    cout<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}