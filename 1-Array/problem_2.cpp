#include<iostream>//largest element in array
using namespace std;
int main(){
    int arr[10];
    cout<<"enter values:"<<endl;
    for(int i=0;i<10;i++){
        cin>>arr[i];
        cout<<endl;
    }
    int largest = arr[0];
    int count = 0;
    for(int i=1;i<10;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }

    }
    cout<<"largest element in array is:"<<largest;


    
}