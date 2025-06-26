#include <iostream>//rotate left by d places
#include <vector>
// using namespace std;
// void reverse(vector<int> &nums, int e)
// {
//     int s=0;
//     while (s <= e)
//     {
//         int temp = nums[s];
//         nums[s] = nums[e];
//         nums[e] = temp;
//         s++;
//         e--;
//     }
// }
// void rotate(vector<int> &nums, int k)
// {
//         int e=nums.size()-1;
//         reverse(nums,nums+k);
//         reverse(nums+k,nums+e);
//         reverse(nums,nums+e);
// }
// int main()
// {
//     vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//     int k = 3;
//     rotate(nums, k);
//     cout<<"rotated array is:"<<endl;
//     for(int i=0;i<=nums.size();i++){
//         cout<<nums[i]<<endl;
//     }
// }