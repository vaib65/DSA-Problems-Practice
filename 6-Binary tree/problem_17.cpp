//k sum paths in tree
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

void solve(Node* root,int k,int &count,vector<int>path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);

    //left
    solve(root->left,k,count,path);
    //right
    solve(root->right,k,count,path);

    //check for k sum
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum=sum+path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();

}

int sumK(Node* root,int k){
    vector<int>path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main(){
    Node* root=NULL;
    root=buildtree(root);
    int count=sumK(root,5);
    cout<<"count:"<<count;
}