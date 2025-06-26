#include<iostream>//union of sorted array
#include<vector>
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0;
        int j=0;
        vector<int>unionArray;
        while(i<n && j<m){
            if(arr1[i]<=arr2[j])
            {
             if(unionArray.size()==0 ||unionArray.back()!=arr1[i])
             {
                unionArray.push_back(arr1[i]);
             }
             i++;
            }else
            {
             if(unionArray.size()==0 ||unionArray.back()!=arr2[j])
             {
                unionArray.push_back(arr2[j]);
             }
             j++;
                
                
            }
            
        }
        while(i<n){
             if(unionArray.size()==0 ||unionArray.back()!=arr1[i])
             {
                unionArray.push_back(arr1[i]);
             }
             i++;
            
        }
        while(j<m){
              if(unionArray.size()==0 ||unionArray.back()!=arr2[j])
             {
                unionArray.push_back(arr2[j]);
             }
             j++;
            
        }
        // return unionArray;
        cout<<"union:"<<endl;
        for(int i=0;i<unionArray.size();i++){
            cout<<unionArray[i]<<" ";
        }
        
    }
int main(){
    int arr1[5]={1,1,2,2,5};
    int n=5;
    int arr2[5]={0,3,3,4,5};
    int m=5;
    findUnion(arr1,arr2,n,m);
    
}