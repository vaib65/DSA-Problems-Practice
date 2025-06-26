#include<iostream>  //find question
using namespace std;

int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    int sum=0,product=1,temp,substract;

    // while(n!=0){
    //     temp=n%10;
    //     n=n/10;
    //     sum=sum+temp;
    //     product=product*temp;
    // }
    cout<<product;
    cout<<endl<<sum;
    substract=product-sum;
    cout<<endl<<substract;
    return 0;
}