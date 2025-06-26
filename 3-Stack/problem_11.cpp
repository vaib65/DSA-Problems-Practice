//sort a stack
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>

using namespace std;
void inserSorted(stack<int>&s,int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>target){
        s.push(target);
        return;
    }
    // step 1
    int topElement=s.top();
    s.pop();
    // step 2 recur
    inserSorted(s,target);
    //step3
    s.push(topElement);
}

void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
       // step 1
    int topElement=s.top();
    s.pop();
    // step 2 recur
    sortStack(s);
    //call insert sorted 
    inserSorted(s,topElement);
    
}
int main(){
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(220);
    s.push(0);
    s.push(10);
    s.push(2);
    
    sortStack(s);
    cout<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}