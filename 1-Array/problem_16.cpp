#include<iostream>//majority element
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                element=nums[i];
            } else if(nums[i]==element){
                count++;
            }else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                count1++;
            }
        }
        if(count1>(nums.size()/2)){
            return element;
        }
        return -1;
    }
int main(){
    vector<int>nums={3,1,3,2,2,2,2,2};
    int ans= majorityElement(nums);
    cout<<"ans="<<endl<<ans;

    
}