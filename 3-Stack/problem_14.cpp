//longest valid paranthesis
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
int longestValidParanthesis(string str){
    stack<int>st;
    st.push(-1);
    int maxLen=0;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);

            }
            else{
                int len=i-st.top();
                maxLen=max(len,maxLen); 
               
            }
        }
    }
    return maxLen;
}
int main(){

    // string str="(((()))"; //ans=6
    // string str=""; //ans=0
    // string str="(()()";
    string str="()())()";
    int length=longestValidParanthesis(str);
    cout<<"longest valid paranthesis is:"<<length;
}