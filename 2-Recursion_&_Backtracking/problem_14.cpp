#include <iostream> //count subsequence whoes sum is k
#include <vector>
#include <limits.h>
using namespace std;
int PrintSubSequence(int i, int arr[], int size, int sum, int target)
{
    // bc
    if (i >= size)
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    // include
    
    sum += arr[i];
    int l=PrintSubSequence(i + 1, arr, size, sum, target);
    sum -= arr[i];
    

    // exclude
    int r=PrintSubSequence(i + 1, arr, size, sum, target);

    return l+r;
}
int main()
{

    int target = 2;
    int arr[] = {1, 1,2, 1};
    int size = 4;
    vector<int> output;
    cout<<PrintSubSequence(0, arr,size, 0, target);
}