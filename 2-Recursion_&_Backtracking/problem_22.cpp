#include<iostream>//subset sum 1
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
void subsetSum(int i,int sum,vector<int>&arr,vector<int>&output){
    if(i>=arr.size()){
        output.push_back(sum);
      
        return;
    }
    //exclude
    subsetSum(i+1,sum,arr,output);
    //include
    subsetSum(i+1,sum+arr[i],arr,output);
    
}
int main(){
    vector<int>arr={3,1,2};
    vector<int>output;
    subsetSum(0,0,arr,output);
    sort(output.begin(),output.end());
    for(auto it:output){
            cout<<it<<" ";
    }
    cout<<endl;
}