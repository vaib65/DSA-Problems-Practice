//interleave queue
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
void interleaveQueue(queue<int>&q){
    //step 1 sepea]rate both halves
    int n=q.size();
    if(q.empty()){
        return;
    }
    int k=n/2;
    int count=0;
    queue<int>q2;
    while(!q.empty()){
        int el=q.front();
        q.pop();
        q2.push(el);
        count++;
        if(count==k){
            break;
        }
    }

    //step 2 even size k liye interleaving start kardo 
    while(!q.empty() && !q2.empty()){
        int first=q2.front();
        q2.pop();
        q.push(first);

        int second=q.front();
        q.pop();
        q.push(second);

    }
    if(n&1){
        int el=q.front();
        q.pop();
        q.push(el);
    }

}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    interleaveQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}