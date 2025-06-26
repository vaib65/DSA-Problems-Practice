#include <iostream> //re arrnge array element containing equal no of pos and neg
#include <vector>
using namespace std;
void brute(vector<int>& nums){
    int n=nums.size();
    vector<int>pos;
    vector<int>neg;
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
            
        }else{
            neg.push_back(nums[i]);

        }
    }
    for(int i=0;i<pos.size();i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
    cout<<"answer="<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}
void rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n, 0);
    int posIndex = 0; // even
    int negIndex = 1; // odd
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            answer[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            answer[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    // return answer;
    cout<<"answer="<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}
int main()
{
    vector<int>nums={3,1,-2,-5,4,-4};
    rearrangeArray(nums);

    // cout<<endl;
    // brute(nums);
}