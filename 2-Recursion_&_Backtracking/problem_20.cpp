#include <iostream> // print subsequence/subset same as 10-11 problem
#include <vector>
#include <limits.h>
using namespace std;
void printPowerSet(int index, vector<int> nums, vector<int> &output)//vector<vector<int>>&ans)
{
    // bc
    if (index >= nums.size())
    {
        // ans.push_back(output);
         for(auto it:output){
                cout<<it<<" ";
            }
            cout<<endl;

        // for(int j=0;j<ans.size();j++){
        //     for(auto it=ans[j].begin();it!=ans[j].end();it++){
        //         cout<<*it<<" ";
        //     }
        //     cout<<endl;
        // }
        return;
    }

    // exclude
    printPowerSet(index + 1, nums, output);
    // include
    output.push_back(nums[index]);
    printPowerSet(index + 1, nums, output);
    output.pop_back();
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    printPowerSet(index, nums, output);
    // for (int j = 0; j < ans.size(); j++)
    // {
    //     for (auto it = ans[j].begin(); it != ans[j].end(); it++)
    //     {
    //         cout << *it << " ";
    //     }
    //     cout << endl;
    // }
}