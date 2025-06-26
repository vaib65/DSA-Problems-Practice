//floor in BST
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};

Node* insertinBST(Node* root,int data){
    //bc
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertinBST(root->right,data);
    }
    else{
        root->left=insertinBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinBST(root,data);
        cin>>data;
    }
}

int findFloor(Node*root,int key){
    int floor=-1;
    while(root){
        if(root->data==key){
            floor=root->data;
            return floor;
        }
        if(key>root->data){
            floor=root->data;
            root=root->right;
        }
        else{
            
            root=root->left;
        }
    }
    return floor;
}

int main(){
    Node* root=NULL;
    cout<<"enter data to create BST:"<<endl;
    takeInput(root);
    int floor=findFloor(root,6);
    cout<<"floor:"<<floor;
}