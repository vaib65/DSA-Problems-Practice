#include<iostream>//check if array is sorted
#include<vector>

using namespace std;
bool sorted(vector<int> arr,int size){
 for(int i=1;i<=size;i++){
    if(arr[i]>arr[i-1]){

    }else{
        return false;
    }
 }
 return true;
}
int main(){
    vector<int> arr={1,2,3,4,5,0};
    int size=arr.size()-1;
    bool ans=sorted(arr,size);
    if(ans){
        cout<<"sorted"<<endl;
    }else{
        cout<<"not sorted"<<endl;
    }
}