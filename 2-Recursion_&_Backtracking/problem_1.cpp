#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void fun(int i,int n){   
    if(i>n){
        return;
    } 
    cout<<"vaibhav"<<endl;
    fun(i+1,n);

}

int main(){
    //print name n times
    int n;
    cout<<"enter n:"<<endl;
    cin>>n;
    fun(1,n);
  
}