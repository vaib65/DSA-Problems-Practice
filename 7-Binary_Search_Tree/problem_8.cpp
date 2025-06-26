//lowest common ancestor in bst
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
//insertion using recursion

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

Node* levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            //puarana level complete hochuka hai
            cout << endl;
            if (!q.empty())
            {
                //queue still has some child
                q.push(NULL);
            }       
        }
        else{
        cout<<temp->data<<"  ";
        if(temp->left)
            {
                q.push(temp->left);
            }
        if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Node* LCA(Node*root,int n1,int n2){
   
//     if(root==NULL){
//         return NULL;
//     }
//     while(root){
//         if((root->data < n1) && (root->data < n2)){
//             return LCA(root->right,n1,n2);
//         }
//         else if((root->data > n1) && (root->data > n2)){
//             return LCA(root->left,n1,n2);
//         }
//         else{
//             return root;
//         }
//     }
//     return NULL;
// }

Node* lca(Node*root,int n1,int n2){
   
    if(root==NULL){
        return NULL;
    }
    Node* curr=root;
    if(curr->data<n1 && curr->data<n2){
        return lca(root->right,n1,n2);
    }
    if(curr->data>n2 && curr->data>n2){
        return lca(root->left,n1,n2);
    }
    return root;
 }

int main(){
    Node* root=NULL;
    cout<<"enter data to create BST:"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    // Node* ans=LCA(root,7,8);
    // cout<<"lca:"<<ans->data;

    Node* ans=lca(root,7,8);
    cout<<"lca:"<<ans->data;
} 