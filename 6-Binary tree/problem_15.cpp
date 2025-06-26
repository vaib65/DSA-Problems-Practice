//sum of longest bloodline of tree
#include<iostream>
#include<vector>
#include<limits.h>
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
void solve(node* root,int sum,int &maxsum,int len,int &maxlen){
    //bc
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len,maxlen);
    solve(root->right,sum,maxsum,len,maxlen);
    

}
int sumOfLongestRootToLeafPath(node* root){
    int len=0;
    int maxlen=0;
    int sum =0;
    int maxsum=INT_MIN;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}
int main(){
     node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    int ans=sumOfLongestRootToLeafPath(root);
    cout<<"sum of longest root to leaf path:"<<ans;
}