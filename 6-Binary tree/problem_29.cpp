//maximum width of binary tree
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

int widthOfBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int width=0;
    queue<pair<node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        int size=q.size();
        int min=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            long curr_id=q.front().second-min;
            node* node=q.front().first;
            q.pop();
            if(i==0){
                first=curr_id;
            }
            if(i==size-1){
                last=curr_id;
            }
            if(node->left){
                q.push(make_pair (node->left,curr_id*2+1));
            }
             if(node->right){
                q.push(make_pair (node->right,curr_id*2+2));
            }
        }
        width=max(width,last-first+1);
    }
    return width;

}

int main(){
     node *root = NULL;
    // creating tree
    root = buildtree(root);
    int width=widthOfBinaryTree(root);
    cout<<"width is:"<<width;
}

