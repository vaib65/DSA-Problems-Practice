//build level oder trees
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildLevelOrderTree(node*root){

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
int main(){
    node* root=NULL;
    //build level oder tree
    buildLevelOrderTree(root);

    cout<<"printing level order tree:"<<endl;
    levelOrderTraversal(root);
}