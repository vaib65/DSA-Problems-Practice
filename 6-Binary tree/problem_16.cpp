//lca(least common ancestor) in binary tree
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
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

node* lca(node* root ,int n1 ,int n2 ){
    if((root==NULL)||(root->data==n1)||(root->data==n2)){
        return root;
    } 
    node* left=lca(root->left,n1,n2);
    node* right=lca(root->right,n1,n2);

    //result
    if(left==NULL){
        return right;
    }
    else if(right==NULL) {
        return left;
    }
    else{
        return root;
    }
}

int main(){
     node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* ans=lca(root,11,17);
    cout<<"ans:"<<ans->data;
}