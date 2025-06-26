#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void fun_1(int i,int n){

    //base  case
    if(i>n){return;}

    // 1 case solve krna
    cout<<i<<endl;

    //baki recursion sambhal lega
    fun_1(i+1,n);

}

void fun_2(int i,int n){
    if(i<1){return;}
    cout<<i<<endl;
    fun_2(i-1,n);

}
int main(){
    //print linearly from 1 to n
    // int n;
    // cout<<"enter n:"<<endl;
    // cin>>n;
    // fun_1(1,n);


    //print reverse from n to 1
    int n;
    cout<<"enter n:"<<endl;
    cin>>n;
    fun_2(n,n);

 
}