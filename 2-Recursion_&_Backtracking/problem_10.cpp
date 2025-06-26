#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void PrintSubSequence(int i, int arr[], vector<int> &output ,int size)
{
    // bc
    
    if(i==size){
        for(auto value: output){
            cout<<value<<" ";
        }
        cout<<endl;
        return;
    }

   
    // //include
    // output.push_back(arr[i]);
    // PrintSubSequence(i+1,arr,output,size);
    // output.pop_back();

     //exclude
    PrintSubSequence(i+1,arr,output,size);

     //include
    output.push_back(arr[i]);
    PrintSubSequence(i+1,arr,output,size);
    output.pop_back();
}
int main()
{
    int i = 0;
    int arr[] = {3, 1};
    int size = 2;
    vector<int> output;
    PrintSubSequence(i, arr, output,size);
}