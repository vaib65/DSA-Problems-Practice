//check if tree are identical or not
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
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

node* levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            //puarana level complete hochuka hai
            cout<<endl;
            if (!q.empty())
            {
                //queue still has some child
                q.push(NULL);
            }       
        }
        else{
        cout<<temp->data<<" ";
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

bool isSameTree(node* r1,node* r2){
    if(r1==NULL&&r2==NULL){
        return true;
    }
    if((r1!=NULL&&r2==NULL)||(r1==NULL&&r2!=NULL)){
        return false;
    }
    bool left=isSameTree(r1->left,r2->left);
    bool right=isSameTree(r1->right,r2->right);
    if(left && right && (r1->data==r2->data)){
        return true;
    }else{
        return false;
    }
}

int main(){
    node* r1=NULL;
    node* r2=NULL;
    r1=buildtree(r1);
    r2=buildtree(r2);
    levelOrderTraversal(r1);
    levelOrderTraversal(r2);
    bool ans=isSameTree(r1,r2);
    if(ans){
        cout<<"identical"<<endl;

    }
    else{
        cout<<"not identical"<<endl;
    }


}