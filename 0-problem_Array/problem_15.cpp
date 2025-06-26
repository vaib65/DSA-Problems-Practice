#include <iostream> //sort an array of 0,1,2
#include<vector>
using namespace std;
void sortColors(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> nums = {2, 0, 2, 1,1, 0};
    // vector<int>& nums={2,0,1};
    sortColors(nums);
    cout<<"Answer"<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}