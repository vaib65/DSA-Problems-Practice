//iterative inorder preorder postorder
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
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

vector<int>preorderIterative(node* root){
    vector<int>preorder;
    if(root==NULL){
        return preorder;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data); 
        if(root->right!=NULL){//right call is first bcoz we are using stack lifo
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
       

    }
    return preorder;
}

vector<int>inorderIterative(node* root){
    vector<int>inorder;
    stack<node*>st;
    node* node=root;
    while(true)
    {
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else
        {
            if(st.empty()==true){
                break;
            }
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;   
}

int main(){
    node* root=NULL;
    //creating tree
    root=buildtree(root);
    // vector<int>inorder=inorderIterative(root);
    // cout<<"inorder iterative:"<<endl;
    // for(int i=0;i<inorder.size();i++){
    //     cout<<inorder[i]<<" ";
    // }
    // cout<<endl;
    vector<int>preorder=preorderIterative(root); //preorder printing wrong ans
    cout<<"preorder iterative:"<<endl;
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }

}