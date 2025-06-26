// inorder traversal,preorder traversal and postorder traversal
#include <iostream>
#include <vector>
#include <limits.h>
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
node *buildtree(node *root)
{
    cout << "enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout<< "enter data for insert in left of:" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data for insert in right of:" << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void inorder(node *root)
{
    // bc
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // bc
    if (root == NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}

void postorder(node *root)
{
    // bc
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;
    // creating tree
    root = buildtree(root);
    // data is
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "inorder traversal is:" << endl;
    inorder(root);
    cout<<endl;
    cout << "preorder traversal is:" << endl;
    preorder(root);
    cout<<endl;
    cout << "postorder traversal is:" << endl;
    postorder(root);
}       