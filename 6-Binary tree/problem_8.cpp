//check if tree is sum tree 
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildtree(node* root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for insert in left of:"<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for insert in right of:"<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

pair<bool,int>isSumTreeFast(node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftPart=isSumTreeFast(root->left);
    pair<bool,int> rightPart=isSumTreeFast(root->right);
    
    bool isLeftSumTree=leftPart.first;
    bool isRightSumTree=rightPart.first;
    
    int leftSum=leftPart.second;
    int rightSum=rightPart.second;
    bool condition= root->data==leftSum+rightSum;
    
    pair<bool,int>ans;
    if(isLeftSumTree && isRightSumTree&& condition){
        ans.first=true;
        ans.second=2*root->data;
    }else{
        ans.first=false;
    }
    return ans;
    
}
bool isSumTree(node* root)
{
    
    return isSumTreeFast(root).first;  
}


int main(){
    node * root=NULL;
    root=buildtree(root);
    
   

    bool ans=  isSumTree(root);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
}