//height of binary tree or depth of binary tree
//longest path between root and leaf node
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
class Solution {
public:
    int maxDepth(node* root) {
        if(root==NULL){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int height=max(left,right)+1;
        return height;
        
    }
};
int main(){}

