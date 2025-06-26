#include<iostream>//print subarray with maximum sum follow up question kadan algo
#include<vector>
#include<limits.h>
using namespace std;
void maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int start;
        int ansStart=-1;
        int ansEnd=-1;
        for(int i=0;i<nums.size();i++){
            if(sum==0){
                start=i;
            }
            sum=sum+nums[i];
            if(sum>maxi){
                maxi=sum;
                ansStart=start;
                ansEnd=i;

            } 
            if(sum<0){
                sum=0;
            }
        }
        // return maxi;
        cout<<"SubArray with maximum Sum=[";
        for(int i=ansStart;i<=ansEnd;i++){
            cout<<nums[i]<<",";
        }
        cout<<"]";

        
    }
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    // int maxSubArraySum= maxSubArray(nums);
    // cout<<"Max sum="<<maxSubArraySum;
    maxSubArray(nums);

}