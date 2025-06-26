// reverse queue methoud 1 using stack
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
using namespace std;
void reverseQueue(queue<int> &q)
{
    stack<int>st;
    while(!q.empty()){
        int el=q.front();
        q.pop();
        st.push(el);
    }
    while(!st.empty()){
        int el=st.top();
        st.pop();
        q.push(el);

    }
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    q.push(9);
    q.push(8);
    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}