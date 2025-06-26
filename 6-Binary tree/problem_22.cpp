//minimum time to burn binary tree
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildtree(Node* root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for insert in left of:"<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for insert in right of:"<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

Node* createParentMapping(Node* root, int target,map<Node*,Node*>&nodeToParent)
{
    Node* result=NULL;
    queue<Node*>q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty())
    {
        Node* front=q.front();
        q.pop();
        
        if(front->data==target)
        {
            result=front;
        }
        if(front->left)
        {
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right)
        {
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return result;
}

int burnTree(Node* root,map<Node*,Node*>&nodeToParent)
{
    map<Node*,bool>visited;
    queue<Node*>q;
    
    q.push(root);
    visited[root]=true;
    int ans=0;
    
    while(!q.empty())
    {
        bool flag=0;
        int size=q.size();
        
        for(int i=0;i<size;i++)
        {
            Node* front=q.front();
            q.pop();
            if(front->left&&!visited[front->left])
            {
                flag=1;
                q.push(front->left);
                visited[front->left]=true;
            }
            if(front->right&&!visited[front->right])
            {
                flag=1;
                q.push(front->right);
                visited[front->right]=true;
            }
            if(nodeToParent[front]&&!visited[nodeToParent[front]])
            {
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=true;
            }
            
        }
        if(flag==1)
        {
            ans++;
        }
        
    }
    return ans;
}
int minTime(Node* root, int target) 
{
    
    map<Node*,Node*>nodeToParent;
    Node* targetNode= createParentMapping(root,target,nodeToParent);
    
    int result=burnTree(targetNode,nodeToParent);
    return result;
    
}

int main(){
    Node* root=NULL;
    root=buildtree(root);

    int minTimeToBurnTree=minTime(root,5);
    cout<<"minTimeToBurnTree:"<<minTimeToBurnTree;
}