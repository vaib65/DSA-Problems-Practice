//print root to node path
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
bool getPath(node * root,vector<int>&arr,int x){
    if(!root){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==x){
        return true;
    }
    if(getPath(root->left,arr,x)||getPath(root->right,arr,x)){
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int>Solution(node* root,int B){
    vector<int>arr;
    if(root==NULL){
        return arr;
    }
    getPath(root,arr,B);
    return arr;
}
int main(){
     node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int>ans=Solution(root,5);
    cout<<"Ans:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}