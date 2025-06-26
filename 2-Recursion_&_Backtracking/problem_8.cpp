#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    int last=fibo(n-1);
    int slast=fibo(n-2);
    return last+slast;
    
}
int main(){
    //fibonnaci series
    int n;
    cout<<"enter n:"<<endl;
    cin>>n;
    cout<<"fibonnaci of "<<n<<"is:"<<fibo(n);
}