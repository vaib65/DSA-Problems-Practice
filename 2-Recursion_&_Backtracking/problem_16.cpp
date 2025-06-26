#include<iostream>//find max element in array using recursion
#include<vector>
#include<limits.h>
using namespace std;
void FindMax(int i,int arr[],int size,int& maxi){
    //bc
    if(i>=size){
        return;
    }
    //1case solve karna hai that is current element
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    //bali rec sambhal lega
    FindMax(i+1,arr,size,maxi);
}
int main(){
    int arr[]={12,14,16,18,19,22,66,78,10,2};
    int size=10;
    int maxi=INT_MIN;
    FindMax(0,arr,size,maxi);
    cout<<"max is:"<<maxi;
}