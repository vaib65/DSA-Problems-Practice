//two sum in BST
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

void inorder(Node* root,vector<int>&inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}

bool twoSumInBST(Node* root,int target){
    vector<int>inorderVal;
    inorder(root,inorderVal);
    int i=0;
    int j=inorderVal.size()-1;

    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    Node* root=NULL;
    cout<<"enter data to construct BST:"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    bool ans=twoSumInBST(root,18);
    if(ans){
        cout<<"twoSumInBST:TRUE"<<endl;
    }else{
        cout<<"twoSumInBST:FALSE"<<endl;
    }

    

}