//level ordr traversal
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

//without pressing enter
node* levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        
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

//with enter

// node* levelOrderTraversal(node* root){
//     queue<node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty())
//     {
//         node* temp=q.front();
//         q.pop();
//         if(temp==NULL)
//         {
//             //puarana level complete hochuka hai
//             cout<<endl;
//             if (!q.empty())
//             {
//                 //queue still has some child
//                 q.push(NULL);
//             }       
//         }
//         else{
//         cout<<temp->data<<" ";
//         if(temp->left)
//             {
//                 q.push(temp->left);
//             }
//         if(temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

int main(){
     node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order traversal
    levelOrderTraversal(root);
}