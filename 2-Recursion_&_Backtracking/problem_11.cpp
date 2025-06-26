#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void PrintSubSequence(int i, int arr[], vector<int> &output ,int size)
{
    // bc
    if (i == size)
    {
       for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
        
       }
       cout<<endl;
        return;
    }
   
   
    //include
    output.push_back(arr[i]);
    PrintSubSequence(i+1,arr,output,size);
    output.pop_back();

    //exclude
    PrintSubSequence(i+1,arr,output,size);

    
}
int main()
{
    int i = 0;
    int arr[] = {3, 1,2};
    int size = 3;
    vector<int> output;
    PrintSubSequence(i, arr, output,size);
}