#include<iostream>//intersection
#include<vector>
using namespace std;
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>answer;
        for(int i=0;i<nums1.size();i++)
        {
            int element=nums1[i];
            for(int j=0;j<nums2.size();j++)
            {
                if(element==nums2[j])
                {
                    nums2[j]=-1;
                    answer.push_back(element);
                }
            }
        }
        // return answer;
        cout<<"INTERSECTION OF TW SORTED ARRAY IS:"<<endl;
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<" ";
        }
    }
int main(){
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    intersection(nums1,nums2);



    
}