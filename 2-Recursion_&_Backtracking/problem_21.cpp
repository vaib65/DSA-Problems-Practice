// #include<iostream>//combination sum 2 same index cannot be used more than once
#include<bits/stdc++.h>
#include<vector>
#include<limits.h>
using namespace std;
void findCombination(int ind,int target,vector<int>& arr,vector<int>&output){

    //bc
    if(target==0){
        for(auto it:output){
            cout<<it<<" ";

        }
        cout<<endl;
        return;
    }

    //

    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        output.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,output);
        output.pop_back();
    }
}
int main(){
    vector<int>arr={1,2,1,2};
    sort(arr.begin(),arr.end());
    vector<int>output;
    int target=4;
    findCombination(0,target,arr,output);

}