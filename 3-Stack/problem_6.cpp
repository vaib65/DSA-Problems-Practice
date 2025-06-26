// reverse string using stack
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
int main()
{
    string str = "vaibhav";
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    while(!st.empty()){
        cout<<st.top()<<"";
        st.pop();

    }
}