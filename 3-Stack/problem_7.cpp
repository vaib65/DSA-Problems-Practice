// find middle element in
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
void findMiddle(stack<int>&s,int &totalSize){
    if(s.size()==0){
        cout<<"stack is empty"<<endl;
        return;
    }
    //bc
    if(s.size() ==totalSize/2 +1){
        cout<<"middle element is:"<<endl<<s.top()<<endl;
        return;
    }
    int temp=s.top();
    s.pop();

    //recursion
    findMiddle(s,totalSize);

    //backtrack
    s.push(temp);
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
    int totalSize=s.size();
    findMiddle(s,totalSize);
    cout<<endl;
    cout<<"stack is:"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}