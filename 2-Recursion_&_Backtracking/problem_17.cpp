#include<iostream>//find key/element in string
#include<vector>
#include<limits.h>
using namespace std;
bool checkKey(int i,string str,int n,char key,int& count){
    //bc
    if(i>=n){
        return false;
    }

    // 1 case krna hai
    if(str[i]==key){
        // return true;   //to find exist or not

        cout<<"fount at:"<<i<<endl;   // to find every position

        count++;//to find count
    }

    //baki rec sambhal lega
    return checkKey(i+1,str,n,key,count);
}
int main(){
    string str="vaibhav";
    int n=str.length();
    char key='a';
    int i=0;
    int count=0;
    // bool ans=checkKey(i,str,n,key);
    // cout<<ans;

    checkKey(i,str,n,key,count);

    cout<<"no of times key present in string is:"<<count<<endl;

}