#include<iostream>//move all the zero to end of array
#include<vector>
#include<limits.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
        // vector<int>temp;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         temp.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<temp.size();i++){
        //     nums[i]=temp[i];
        // }
        // for(int i=temp.size();i<nums.size();i++){
        //     nums[i]=0;
        // }
        int j=INT_MIN;;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
int main(){
    vector<int>nums={3,5,0,0,4,0,0,6,7,5};
    moveZeroes(nums);
    cout<<"answer:"<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";

    }
    
}