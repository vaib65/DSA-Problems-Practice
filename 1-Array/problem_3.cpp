#include <iostream> //second largeat element in array
#include<vector>
#include <limits.h>

using namespace std;
int thirdLargest(vector<int>&arr,int size){
    int largest=arr[0];
    int slargest=INT_MIN;
    int tlargest=INT_MIN;
    for(int i=1;i<=size;i++){
        if(arr[i]>largest){
            tlargest=slargest;
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest)//removes duplicate
        {
            tlargest=slargest;
            slargest=arr[i];
        }
        else if(arr[i]<largest && arr[i]<slargest && arr[i]>tlargest){
            tlargest=arr[i];
        }
    }
    cout<<"third largst is:"<<tlargest<<endl;
}
int secondLargest(vector<int>&arr,int size){
    int largest=arr[0];
    int slargest=INT_MIN;
    for(int i=1;i<=size;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest)//removes duplicate
        {
            slargest=arr[i];
        }
    }
    cout<<"second largst is:"<<slargest<<endl;
}

int secondSmallest(vector<int>&arr,int size){
    int smallest=arr[0];
    int ssmallest=INT_MAX;
    for(int i=1;i<=size;i++){
        if(arr[i]<smallest){
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<ssmallest && arr[i]!=smallest)//removes duplicate
        {
            ssmallest=arr[i];
        }
    }
    cout<<"second smallest is:"<<ssmallest<<endl;
}
int main()
{
    // brute sol method

    // better sol
    // int arr[10];
    // cout << "enter values:" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> arr[i];
    //     cout << endl;
    // }
    // int largest = arr[0];
    // for (int i = 1; i < 10; i++)
    // {
    //     if (arr[i] > largest)
    //     {
    //         largest = arr[i];
    //     }
    // }
    // int secondLargest=-1;
    // for(int i=0;i<10;i++){
    //     if(arr[i]>secondLargest && arr[i]!=largest){
    //         secondLargest=arr[i];
    //     }
    // }
    // cout<<"second largest elemengt is:"<<secondLargest;

    //optimal solution

    vector<int> arr={2,4,1,3,5};
    int size=arr.size()-1;
    int sLargest=secondLargest(arr,size);
    int sSmallest=secondSmallest(arr,size);
    int tLargest=thirdLargest(arr,size);

}