//flatten BST into  sorted linked list
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

void inorder(Node* root,vector<int>& inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}

Node* flattenBstToSortedLL(Node*root){
    vector<int>inorderVal;
    inorder(root,inorderVal);
    Node* newRoot=new Node(inorderVal[0]);
    Node* curr=newRoot;
    int j=inorderVal.size();
    for(int i=1;i<j;i++){
        Node* temp=new Node(inorderVal[i]);
        
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
        //OR
        // if(i==(j-1)){
        //     curr->left=NULL;
        //     curr->right=NULL;
        //     return newRoot;
        // }
        // else{
            // curr->left=NULL;
            // curr->right=temp;
            // curr=temp;
        // }
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}

int main(){
    Node* root=NULL;
    cout<<"enter data to construct BST:"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    Node* head=flattenBstToSortedLL(root);
    Node* temp=head;
    while(head!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }

}