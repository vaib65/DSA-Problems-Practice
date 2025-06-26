//maximum sum of non adjacent node

#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildtree(Node* root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for insert in left of:"<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for insert in right of:"<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

pair<int,int>solve(Node* root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    pair<int,int>result;//first int include and second int for exclude
    result.first=root->data+left.second+right.second;
    result.second=max(left.first,left.second)+max(right.first,right.second);
    return result;
}

int getMaxSum(Node* root){
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}
int main(){
    Node* root=NULL;
    root=buildtree(root);
    int ans=getMaxSum(root);
    cout<<"maximum sum of non adjacent node:"<<ans;
}