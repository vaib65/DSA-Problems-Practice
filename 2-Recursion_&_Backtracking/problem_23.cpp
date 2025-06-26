#include<iostream>//subset sum 2
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
void  findSubsets(int ind,vector<int>&arr,vector<int>&output){
    for(auto it:output){
        cout<<it<<"";
    }
    cout<<endl;
    for(int i=ind;i<arr.size();i++){
        if(i!=ind && arr[i]==arr[i-1])continue;
        output.push_back(arr[i]);
        findSubsets(i+1,arr,output);
        output.pop_back();
    }

}
int main(){
    // vector<int>arr={1,2,2,3,2,3};
    vector<int>arr={1,2,2,2,3,3};
    sort(arr.begin(),arr.end());
    vector<int>output;
    //vector<int>ans;
    findSubsets(0,arr,output);
}