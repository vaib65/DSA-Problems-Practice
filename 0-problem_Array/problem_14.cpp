#include <iostream> //2 sum problem
#include <vector>
#include<bits/stdc++.h>
using namespace std;
// vector<int> twoSum(vector<int> &nums, int target)
// {

    // int s = 0;
    // int e = nums.size() - 1;
    // sort(nums.begin(), nums.end());
    // while (s < e)
    // {
    //     int sum=nums[s] + nums[e];
    //     if (sum == target)
    //     {
    //         cout<<"Answer is:"<<"["<<s<<","<<e<<"]";
    //         break;
    //     }
    //     else if (sum < target)
    //     {
    //         s++;
    //     }
    //     else if (sum > target)
    //     {
    //         e--;
    //     }
    // }
// }
 vector<int> twoSum(vector<int>& nums, int target) {
     for(int i=0;i<nums.size();i++){
         for(int j=i+1;j<nums.size();j++){
             int sum=nums[i]+nums[j];
             if(sum==target){
                //  return {i,j};
                cout<<"Answer is:"<<"["<<i<<","<<j<<"]";
                break;
             }
         }
     } 
    //  return {-1,-1};  
    }
int main()
{
    vector<int> nums={3,2,4};
    int target=6;
    twoSum(nums,target);

}