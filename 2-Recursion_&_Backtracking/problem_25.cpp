#include<iostream>//permutation recursion APPROACH 2
#include<vector>
#include<limits.h>
using namespace std;
void recurPermute(int ind,vector<int>&nums){
    if(ind == nums.size()){
        for(auto it:nums){
            cout<<it<<"";
        }
        cout<<endl;
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        recurPermute(ind+1,nums);
        swap(nums[ind],nums[i]);
    }
}
int main(){
    vector<int>nums={1,2,3};
    vector<int>ds;
    recurPermute(0,nums);
}