//search and deletion in BST
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

//approach 1=searching using recursion
// bool searchInBst(Node* root,int x){
//     if(root==NULL){
//         return false;
//     }
//     if(root->data==x){
//         return true;
//     }
//     if(root->data>x){
//         return searchInBst(root->left,x);
//     }else{
//         return searchInBst(root->right,x);
//     }
// }

// approach 2 = searching using iterative
// bool searchInBst(Node* root,int x){
//     Node* node=root;
//     while(root!=NULL){
//         if(node->data==x){
//             return true;
//         }else if(node->data>x){
//             node=node->left;
//         }else{
//             node=node->right;
//         }
//     }
//     return false;
// }

//approach 3
bool searchInBst(Node* root,int data){
    while(root!=NULL&&root->data!=data){
        root=data<root->data?root->left:root->right;
    }
    return root;
}

int main(){
    Node* root=NULL;
    cout<<"enter data to create BST:"<<endl;
    takeInput(root);
    
    bool ans=searchInBst(root,55);
    if(ans){
        cout<<"true";
    }else{
        cout<<"false";
    }
} 