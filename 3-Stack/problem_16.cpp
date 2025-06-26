//previous smaller element
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
vector<int> previousSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);
    for (int i=0;i<arr.size();  i++)
    {
        int el = arr[i];

        while (s.top()>=el)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(el);

    }

   return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    vector<int> ans=previousSmallerElement(arr);
    for(int i=0;i<arr.size();i++){
        cout<<ans[i]<<" ";

    }
}