//check balanced tree or not
#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
#include<cstdlib>
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

//approach 1 using height
// int height(node* root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=height(root->left);
//         int right=height(root->right);
//         int ans=max(left,right)+1;
//         return ans;
// }
//  bool isBalanced(node *root)
// {
//     //bc
//     if(root==NULL){
//         return true;
//     }
//     bool left=isBalanced(root->left);
//     bool right=isBalanced(root->right);
//     bool diff=abs(height(root->left)-height(root->right))<=1;
//     if(left&&right&&diff){
//         return true;
        
//     }
//     else{
//         return false;
//     }
// }

//approach 2

pair<bool,int>isBalancedfast(node * root)
{
    //bc
    if(root==NULL)
    {
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    
    pair<int,int>left=isBalancedfast(root->left);
    pair<int,int>right=isBalancedfast(root->right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if(leftAns&&rightAns&&diff)
    {
        ans.first= true;
    }
    else{
        ans.first=false;
    }
    return ans;
  
}
bool isBalanced(node *root)
{
    
    return isBalancedfast(root).first;
}

//approach 3
// bool height(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int left=height(root->left);
//     if(left==-1) return -1;
//     int right=height(root->right);
//     if(right==-1) return -1;
//     if(abs(left-right)>1) return -1;
//     return max(left,right)+1;
// }
// bool isBalanced(node *root){
//     return height(root)!=-1;
// }

int main(){
    node * root=NULL;
    root=buildtree(root);
    
   

    bool ans=  isBalanced(root);
    cout<<"TREE is Balanced:"<<endl;
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
}