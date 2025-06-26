//diameter of binary tree(width of bt)
//longest path  between any two nodes (root /left)

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

//APPROACH 1st usinf height function
// class solution{
//     private:
//     int height(node* root){
//         if(root==NULL){
//             return 0;
//         }
//         int left=height(root->left);
//         int right=height(root->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }
//     public:
//     int diameterOfBinaryTree(node* root) {
//          if(root==NULL){
//             return 0;
//         }
//         int op1=diameterOfBinaryTree(root->left);
//         int op2=diameterOfBinaryTree(root->right);
//         int op3=height(root->left)+height(root->right)+1;// remove +1 if counting from 0

//         int diameter=max(op1,max(op2,op3));
//         return diameter;
        
        
//     }
// };
//APPROACH TWO using pair calculating at a same time
// pair<int,int>diameterFast(node* root){
//     if(root==NULL){
//         pair<int,int>p=make_pair(0,0);
//         return p;
//     }
//     pair<int,int>left=diameterFast(root->left);
//     pair<int,int>right=diameterFast(root->right);
//     int opt1=left.first;
//     int opt2=right.first;
//     int opt3=left.second +right.second +1;// remove +1 if counting from 0
//     pair<int,int>ans;
//     ans.first=max(opt1,max(opt2,opt3));
//     ans.second=max(left.second,right.second)+1;
//     return ans;

// }
// int diameterOfBinaryTree(node* root) {
//     pair<int,int>ans=diameterFast(root);
//     // return diameterFast(root).first;
//     cout<<"height:"<<ans.second<<endl;
//     return ans.first;

    
// }

// approach 3
int height(node* root,int &diameter){
    if(root==NULL){
        return 0;
    }
    int leftHt=height(root->left,diameter);
    int rightHt=height(root->right,diameter);
    diameter=max(diameter,leftHt+rightHt);
    return 1+ max(leftHt , rightHt);

}
int diameter(node* root){
    int diameter=0;
    height(root,diameter);
    return diameter;
}

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
int main(){
    node* root=NULL;
    //creating tree
    root=buildtree(root);

    levelOrderTraversal(root);
    // int diameter=diameterOfBinaryTree(root);
    // cout<<"diameter:"<<diameter;
    int ans=diameter(root);
    cout<<"diameter:"<<ans;
}