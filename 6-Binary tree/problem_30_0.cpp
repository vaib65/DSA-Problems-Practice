//node at distance k in binary tree
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

void markParents(node* root, map<node*,node*>&parent_track,node* target){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* current=q.front();
        q.pop();
        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);

        }
        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
            
        }
    }
}

vector<int>distanceK(node * root,node* target,int k){
    map <node*,node*>parent_track;//node->parent
    markParents(root,parent_track,target);

    map<node*,bool>visited;
    queue<node*>queue;
    queue.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!queue.empty()){
        int size=queue.size();
        if(curr_level++ == k)break;
        for(int i=0;i<size;i++){
            node* current=queue.front();
            queue.pop();
            if(current->left&& !visited[current->left]){
                queue.push(current->left);
            }
            if(current->right&& !visited[current->right]){
                queue.push(current->right);
            }
            if(parent_track[current]&& !visited[parent_track[current]]){
                queue.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
    }
    vector<int>result;
    while(!queue.empty()){
        node* current=queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    return result;
}

int main(){
    node* root=NULL;
    root=buildtree(root);
    

}