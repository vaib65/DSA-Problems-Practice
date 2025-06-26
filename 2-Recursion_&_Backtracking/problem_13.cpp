#include <iostream>//printing any subsequence whoes sum is sum
#include <vector>
#include <limits.h>
using namespace std;
bool PrintSubSequenceSum(int i, int arr[], vector<int> &output, int size, int sum, int target)
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
           return true;
        }
        return false;
    }

    // include
    output.push_back(arr[i]);
    sum += arr[i];
    if(PrintSubSequenceSum(i + 1, arr, output, size, sum, target)==true) return true;
    sum -= arr[i];
    output.pop_back();

    // exclude
    if(PrintSubSequenceSum(i + 1, arr, output, size, sum, target)==true)return true;

    return false;
}
int main()
{

    int target = 4;
    // int arr[] = {1, 2, 1};
    int arr[]={3,2,1,2};
    int size = 4;
    vector<int> output;
    PrintSubSequenceSum(0, arr, output, size, 0, target);
}