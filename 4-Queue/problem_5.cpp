//reverse queue using recursion
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
void reverseQueue(queue<int>&q){
    if(q.empty()){
        return;
    }
    int temp=q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}
int main(){
     queue<int> q;
    q.push(3);
    q.push(6);
    q.push(4);
    q.push(9);
    q.push(1);
    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}