#include <iostream>//printing subsequence whoes sum is k
#include <vector>
#include <limits.h>
using namespace std;
void PrintSubSequenceSum(int i, int arr[], vector<int> &output, int size, int sum, int target)
{
    // bc
    if (i >= size)
    {
        if (sum == target)
        {
            for (int i = 0; i < output.size(); i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
           
        }
        return;
    }

    // include
    output.push_back(arr[i]);
    sum += arr[i];
    PrintSubSequenceSum(i + 1, arr, output, size, sum, target);
    sum -= arr[i];
    output.pop_back();

    // exclude
    PrintSubSequenceSum(i + 1, arr, output, size, sum, target);
}
int main()
{

    int target = 5;
    // int arr[]={1,1,2,1};
    int arr[] = {3, 2,1, 2};
    int size = 4;
    vector<int> output;
    PrintSubSequenceSum(0, arr, output, size, 0, target);
}