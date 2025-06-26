// next smaller element
#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--)
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
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    vector<int> ans=nextSmallerElement(arr);
    for(int i=0;i<arr.size();i++){
        cout<<ans[i]<<" ";

    }
}