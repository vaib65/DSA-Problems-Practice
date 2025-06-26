#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void reverse(int i,int n,int arr[]){
    //bc
    if(i>=n/2){
        return;
    }

    // 1 case solve krna 
    swap(arr[i],arr[n-i-1]);

    //baki recursion sambhal lega
    reverse(i+1,n,arr);

}
int main(){
    //reverse a array
    int n;
    cout<<"enter value of n:"<<endl;
    cin>>n;
    int arr[n];

    cout<<"enter values of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    reverse(0,n,arr);

    cout<<" reverse array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}