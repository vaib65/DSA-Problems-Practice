#include <iostream> //re arrnge array element not containing equal no of pos and neg
#include <vector>
using namespace std;
void rearrangeArray(vector<int> &nums)
{
    int n=nums.size();
    vector<int>pos;
    vector<int>neg;
   
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
            
        }else{
            neg.push_back(nums[i]);

        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            nums[index]=pos[i];
            index++;
        }
    }else{
        for(int i=0;i<pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            nums[index]=neg[i];
            index++;
        }
    }
}



int main()
{
    // vector<int>nums={3,1,-2,-5,4,-4};
    vector<int>nums={-1,2,3,4,-3,1};
    rearrangeArray(nums);
    cout<<"answer="<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}