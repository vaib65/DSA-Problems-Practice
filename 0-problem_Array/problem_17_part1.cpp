#include<iostream>//max subarray sum or kadane algo
#include<vector>
#include<limits.h>
using namespace std;
 int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum>maxi){
                maxi=sum;
            } 
            if(sum<0){
                sum=0;
            }
        }
        // if asked to return empty subArray
        // if(maxi<0){
        //     return 0;
        // }else{
        //     return maxi;
        // }

        return maxi;
        
        
    }
int main(){
    // vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    vector<int>nums={-4,-3,-2,-1};
    int maxSubArraySum= maxSubArray(nums);
    cout<<"Max sum="<<maxSubArraySum;

}