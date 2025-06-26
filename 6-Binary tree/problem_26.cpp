//check for symmmetrical binary tree
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


bool isSymmetricFast(Node* left,Node* right){
    if(left==NULL||right==NULL){
        return left==right;
    }
    if(left->data!=right->data){
        return false;
    }
    return isSymmetricFast(left->left,right->right)&&isSymmetricFast(left->right,right->left);
}
bool isSymmetric(Node* root) {
    return root==NULL||isSymmetricFast(root->left,root->right);
    
}

int main(){
    Node* root=NULL;
    root=buildtree(root);
    bool ans=isSymmetric(root);
    if(ans){
        cout<<"isSymmetric:true"<<endl;
    }else{
        cout<<"isSymmetric:false"<<endl;
    }
}