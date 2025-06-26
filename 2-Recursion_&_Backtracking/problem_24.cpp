#include<iostream>//permutation recursion APPROACH 1 uses extra space which is map
#include<vector>
#include<limits.h>
using namespace std;
void  recurPermute(vector<int>&nums,vector<int>&ds,int freq[]){
    if(ds.size()==nums.size()){
       for( auto it:ds){
        cout<<it<<" ";
       } 
       cout<<endl;
       return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            recurPermute(nums,ds,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
int main(){
    vector<int>nums={1,2,3};
    vector<int>ds;
    int freq[nums.size()]={0};
    recurPermute(nums,ds,freq);
}