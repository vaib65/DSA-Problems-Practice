//zig zag trav ersal of binary tree
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

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(node* root)
{
    vector<int>result;
    if(root==NULL)return result;
    
    queue<node*>q;
    q.push(root);
    bool leftToRight=true;
    
    while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
            node* node=q.front();
            q.pop();
            
            //find pos to fill nodes value
            
            int index=(leftToRight)?i:(size-1-i);
            
            row[index]=node->data;
            if(node->left){
                q.push(node->left);
                
            }
            if(node->right){
                q.push(node->right);
                
            }
            
        }
        
        //after this level
        leftToRight=!leftToRight;
        for(auto i:row){
            result.push_back(i);
        }
    }
    return result;
}


int main(){
      node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int>ans=zigZagTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}