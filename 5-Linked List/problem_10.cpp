#include<iostream>// reverse ll in k groups
#include<vector>
#include<limits.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"node deleted with value"<<this->data<<endl;
    }
};

int findLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// inser at start or head
void InsertAtHead(Node *&head, Node *&tail, int data)
{
    // if empty list
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step 1 create node
    Node *newNode = new Node(data);
    // step 2 attach newnode to head
    newNode->next = head;
    // step 3 point head to newnode
    head = newNode;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverseKgroups(Node* &head,int k){
    //ll is empty
    if(head==NULL){
        cout<<"ll is empty"<<endl;
        return head;
    }
    //k greater than len of ll
    int len=findLength(head);
    if(k>len){
        return head;
    }
    //if no of nodes greateer than k
    Node* prev=NULL;
    Node* curr=head;
    Node*forward=curr->next;
    int count=0;
    while(count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }

    if(forward!=NULL){
        head->next=reverseKgroups(forward,k);
    }
    return prev;

}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 70);
    InsertAtHead(head, tail, 80);
    print(head);
    head=reverseKgroups(head,6);
    print(head);
}