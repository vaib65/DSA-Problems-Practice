#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
bool palindrome(int i,string s){
    if(i>=s.size()/2){
        return true;}
    
    if(s[i]!=s[s.size()-i-1]){
        return false;}
    
    return palindrome(i+1,s);
   
}
int main(){
    //palindrome using recursion
    string s="madao";
//     bool Ans=palindrome(0,s);
//     cout<<"string is palindrome or not:"<<Ans;
    cout<<"string is palindrome or not:"<<palindrome(0,s);
}