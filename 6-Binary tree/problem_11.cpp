//boundary traversal of binry tree
#include<iostream>
#include<vector>
#include<limits.h>
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

void addLeftBoundary(Node* root,vector<int>&result){

    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
    return;
    }
    result.push_back(root->data);
    if(root->left){
    addLeftBoundary(root->left,result);
    }
    else{
    addLeftBoundary(root->right,result);
    }
}

void addRightBoundary(Node* root,vector<int>&result){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
    return;
    }
    vector<int>temp;
    temp.push_back(root->data);

    if(root->right){
    addRightBoundary(root->right,result);
    }else{
    addRightBoundary(root->left,result);
    }
    for(int i=temp.size()-1;i>=0;i--){
    result.push_back(temp[i]);
    }
}

void addLeaf(Node* root,vector<int>&result){
    if(root==NULL){
    return;
    }
    if(root->left==NULL && root->right==NULL){
    result.push_back(root->data);
    return;
    }  
    if(root->left){
    addLeaf(root->left,result);
    }
    if(root->right){
    addLeaf(root->right,result);
    }
}
vector <int> boundary(Node *root)
{
    vector<int>result;
    if(!root)return result;

    result.push_back(root->data);
    addLeftBoundary(root->left,result);
    addLeaf(root->left,result);
    addLeaf(root->right,result);
    addRightBoundary(root->right,result);
    return result;

}

int main(){
    Node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int>ans=boundary(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}
