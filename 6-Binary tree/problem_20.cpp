//construct binary tree from inorder and preorder
//will not run here but code is complete and valid at leetcode and gfg

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


// Node* buildtree(Node* root){
//     cout<<"enter the data:"<<endl;
//     int data;
//     cin>>data;
//     root=new Node(data);
//     if(data==-1){
//         return NULL;
//     }
//     cout<<"enter data for insert in left of:"<<data<<endl;
//     root->left=buildtree(root->left);
//     cout<<"enter data for insert in right of:"<<data<<endl;
//     root->right=buildtree(root->right);
//     return root;
// }

//+++++++++++construct binary tree from inorder and preorder traversal
int findPosition(int in[],int inorderStart,int element,int n){
    for(int i=inorderStart;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
    //bc
    if(index>=n||inorderStart>inorderEnd){
        return NULL;
    }
    int element=pre[index++];
    Node* root=new Node(element);
    int position=findPosition(in,inorderStart,element,n);
    //rec call
    root->left=solve(in,pre,index,inorderStart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderEnd,n);
    return root;
}
Node* buildBinaryTree(int in[],int pre[], int n)
{
    int preOrderIndex=0;
    Node* ans=solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
}

int main(){

}