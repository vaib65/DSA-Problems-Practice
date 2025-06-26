#include<iostream>//combination subset 1
#include<vector>
#include<limits.h>
using namespace std;
void  combinationSum(int i,vector<int >&arr,int target,vector<int>&output){
    //bc
    if(i==arr.size()){
        if(target==0){
            for(auto it:output){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //include
    if(arr[i]<=target){
        output.push_back(arr[i]);
        combinationSum(i,arr,target-arr[i],output);
        output.pop_back();
    }
    //exclude
    combinationSum(i+1,arr,target,output);
}
int main(){
    vector<int> arr={2,3,6,7};
    int i=0;
    int target=7;
    vector<int>output;
    combinationSum(i,arr,target,output);
    

}