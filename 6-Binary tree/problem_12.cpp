//vertical order traversal of binary tree
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


//Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(node *root)
{
    map<int,map<int,vector<int> > > nodes;
    queue<pair<node*,pair<int,int> > > q;
    vector<int>ans;
     
    if(root==NULL)return ans;
    
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        pair<node*,pair<int,int> >temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        
        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
            if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i : nodes ) {//i -><int=hd,map->int,vector<int>>
        for(auto j : i.second) {//j-><int,vector<int>> bascically a map
            for(auto k : j.second) {//k is j.second which we have to push
                ans.push_back(k);
            }
        }
    }
    return ans;
    
}


int main(){

      node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int>ans=verticalOrder(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}