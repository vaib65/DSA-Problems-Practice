//left view and right view of bt
#include<iostream>
#include<vector>
#include<limits.h>
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

void rightViewFast(node* root,int level,vector<int>& result){
    if(root==NULL){
        return;
    }
    if(result.size()==level){
        result.push_back(root->data);
    }
    rightViewFast(root->right,level+1,result);
    rightViewFast(root->left,level+1,result);
}
    //Function to return list containing elements of right view of binary tree.
vector<int> rightView(node *root){
    vector<int>result;
    rightViewFast(root,0,result);
    return result;
}

void leftViewFast(node* root,int level,vector<int>& result){
    if(root==NULL){
        return;
    }
    if(result.size()==level){
        result.push_back(root->data);
    }
    leftViewFast(root->left,level+1,result);
    leftViewFast(root->right,level+1,result);
}
    //Function to return list containing elements of right view of binary tree.
vector<int> leftView(node *root){
    vector<int>result;
    leftViewFast(root,0,result);
    return result;
}

int main(){

    node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    //right view
    vector<int>ans=rightView(root);
    cout<<"Right view:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    //left view
    vector<int>ans2=leftView(root);
    cout<<"Right view:"<<endl;
    for(auto i:ans2){
        cout<<i<<" ";
    }
}
