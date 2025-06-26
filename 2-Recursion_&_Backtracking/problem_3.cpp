#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void fun_1(int i,int n){
    if(i<1){return;}
    fun_1(i-1,n);
    cout<<i<<endl;
}
void fun_2(int i,int n){
    if(i>n){return;}
    fun_2(i+1,n);
    cout<<i<<endl;
}
int main(){
    //print from 1 to n using backtracking
    // int n;
    // cout<<"enter n:"<<endl;
    // cin>>n;
    // fun_1(n,n);

    //print from n to 1 using backtracking
    int n;
    cout<<"enter n:"<<endl;
    cin>>n;
    fun_2(1,n);

}