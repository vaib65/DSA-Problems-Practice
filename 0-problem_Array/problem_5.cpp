#include<iostream>//remove duplicate
#include<vector>
using namespace std;
void duplicate(int arr[],int size){
    int i=0;
    for(int j=1;j<size;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
   cout<<"non duplicate no count is:"<<i+1;
}
int main(){
    int arr[7]={1,1,2,2,2,3,3};
    int size=7;
    duplicate(arr,size);
   
    
}