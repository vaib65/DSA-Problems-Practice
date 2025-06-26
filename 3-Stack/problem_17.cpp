//largest rectangle area in histogram
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
    //left to right
    for (int i=0;i<arr.size();  i++)
    {
        int el = arr[i];
        //ans in stack
        while (s.top()!=-1&& arr[s.top()]>=el)
        {
            s.pop();
        }

        //choto el mil chuka hai
        ans[i] = s.top();
        //push curr el in stack
        s.push(i);

    }
    return ans;

}

vector<int> nextSmallerElement(vector<int> &arr)
{
    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);
    //right to left
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int el = arr[i];
        //ans in stack
        while (s.top()!=-1 && arr[s.top()]>=el)
        {
            s.pop();
        }
        //chota el mil chuka hai
        ans[i] = s.top();
        //push curr el in stack
        s.push(i);

    }
    return ans;

}

int largestRectangleArea(vector<int>&heights){
    //step1 prev smaller
    vector<int>prev=previousSmallerElement(heights);
    //step2 next smller
    vector<int>next=nextSmallerElement(heights);

    int maxArea=INT_MIN;
    int size=heights.size();

    for(int i=0;i<heights.size();i++){
        int length=heights[i];
        if(next[i]==-1){
            next[i]=size;
        }

        int width=next[i]-prev[i]-1;
        int area=length*width;
        maxArea=max(area,maxArea);
    }
    return maxArea;
}
int main(){
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(10);
    // arr.push_back(2);
    // arr.push_back(3);
    int area=largestRectangleArea(arr);
    cout<<"largest rectangle area in histogram:"<<area<<endl;
}