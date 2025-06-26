//kth smallest in bst  best approach is approach 3 using morris code
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


//approach 2
int solve(Node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }
    //left
    int left=solve(root->left,i,k);

    if(left!=-1){
        return left;
    }

    //node
    i++;
    if(i==k){
        return root->data;
    }

    //right
    solve(root->right,i,k);
}

int kSmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;

}

int main(){
    Node* root=NULL;
    cout<<"enter data to create BST:"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    int ans=kSmallest(root,3);
    cout<<"k smallest:"<<ans;
}