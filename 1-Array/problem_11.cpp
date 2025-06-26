#include<iostream>//max consecutive 1
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive=0;
        int count=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==1){
             count++;
             maxConsecutive=max(maxConsecutive,count);
            }else{
                count=0;
            }
        }
        return maxConsecutive;
        
    }
int main(){
    // vector<int>nums={1,1,0,1,1,1};
    vector<int>nums={1,0,1,1,0,1};

    int ans=findMaxConsecutiveOnes(nums);
    cout<<"no of consecutive 1's are:"<<endl<<ans;
    
}