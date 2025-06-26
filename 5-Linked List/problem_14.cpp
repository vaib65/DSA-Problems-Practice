#include<iostream>//linked list is palindrome or not
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

Node* reverseLL(Node* &head){
    Node*prev=NULL;
    Node*curr=head;
    Node* next=curr->next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool checkpalindrome(Node* &head){
    //empty ll
    if(head==NULL){
        return true;
    }
    //single node
    if(head->next==NULL){
        return true;
    }
    //more than 1 node
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    
    }

    Node* reverseKaHead=reverseLL(slow->next);

    Node* temp1=head;
    Node* temp2=reverseKaHead;

    while(temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;


}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(30);
    Node* sixth=new Node(20);
    Node* seventh=new Node(10);
   

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    // sixth->next=NULL;
    sixth->next=seventh;
    seventh->next=NULL;
   

    cout<<endl;
    bool ispalinrome=checkpalindrome(head);
    if(ispalinrome){
        cout<<"ll is palindrome"<<endl;
    }
    else{
        cout<<"ll is not palindrome"<<endl;
    }
}