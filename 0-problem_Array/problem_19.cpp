#include<iostream>//buy and sell stock
#include<vector>
#include<limits.h>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int miniCP=prices[0];//minimum cost price of stock
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            int sellingCost=prices[i]-miniCP;//profit after selling
            maxProfit=max(sellingCost,maxProfit);
            miniCP=min(miniCP,prices[i]);
        }
        return maxProfit;
        
    }
int main(){
    // vector<int>nums={7,1,5,3,6,4};
      vector<int>nums={7,6,3,2,1};
    int ans=maxProfit(nums);
    cout<<"answer="<<ans;
    
}