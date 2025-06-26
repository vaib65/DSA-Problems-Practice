#include <iostream> //find no that appear once and other twice
#include <vector>

using namespace std;
// brute sol
//   int singleNumber(vector<int>& nums) {
//          for(int i=0;i<nums.size();i++){
//              int num=nums[i];
//              int count=0;
//              for(int j=0;j<nums.size();j++){
//                  if(nums[j]==num){
//                      count++;
//                  }

//             }
//             if(count==1){
//                 return num;
//             }

//         }
//         return -1;

//     }

// optimal sol
int singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main()
{
    vector<int>nums={1,2,1,3,3,4,4};
    int ans=singleNumber(nums);
    cout<<"Answer:"<<endl<<ans;
}