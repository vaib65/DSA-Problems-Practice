#include<iostream>//find no of ways to climb nth stair
#include<vector>
#include<limits.h>
using namespace std;
int climbStair(int n){
    //base case
    if (n==0||n==1){
        return 1;
    }

    return climbStair(n-1)+climbStair(n-2);
}
int main(){
    int n;
    cout<<"enter the  n:"<<endl;
    cin>>n;

    int ans=climbStair(n);
    cout<<"answer is:"<<ans;
}