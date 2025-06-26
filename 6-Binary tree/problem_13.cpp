//top view and bttom view of BT
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

vector<int> topView(node *root){
    
    vector<int>result;
    if(root==NULL){
    return result;
    }
    
    map<int,int>ds;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;
        
        //if one value of hd is present then do nothing
        if(ds.find(hd)==ds.end()){
            ds[hd]=frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
        
    }
    for(auto i:ds){
        result.push_back(i.second);
    }
    return result;
}

vector<int> bottomView(node *root){
    
    vector<int>result;
    if(root==NULL){
    return result;
    }
    
    map<int,int>ds;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;
        
        
        ds[hd]=frontNode->data;
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
        
    }
    for(auto i:ds){
        result.push_back(i.second);
    }
    return result;
}

int main(){
    
      node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int>ans=topView(root);
    cout<<"TopView:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

    vector<int>ans2=bottomView(root);
    cout<<"BottomView:"<<endl;
    for(auto i:ans2){
        cout<<i<<" ";
    }

}