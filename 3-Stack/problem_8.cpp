// insert at bottom
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
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
int main()
{

    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(220);
    s.push(208);
    s.push(10);
    s.push(2);

    int target = s.top();
    s.pop();
    
    
    insertAtBottom(s,target);
    cout<<endl;

    cout<<"After insertion at bottom stack is:"<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}