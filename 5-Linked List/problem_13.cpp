#include<iostream>//REMOVE LOOP
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool checkLoop(Node* &head){
    if(head==NULL){
        cout<<"empty"<<endl;
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        if(slow==fast){
            return true;
        }
    }
    //
    return false;
}


Node* startingPointOfLoop(Node* &head){
    if(head==NULL){
        cout<<"empty"<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    //
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

Node* removeLoop(Node* &head){
    if(head==NULL){
        cout<<"empty"<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    Node* prev=NULL;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;
    return slow;
}

int main(){
    // Node* head=NULL;
    // Node* tail=NULL;
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    Node* seventh=new Node(70);
    Node* eight=new Node(80);
    Node* nine=new Node(90);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eight;
    eight->next=nine;
    nine->next=fifth;
    // nine->next=NULL;
    
    cout<<"loop is present or not:"<<checkLoop(head);
    cout<<endl;
    cout<<"starting point of loop is:"<<startingPointOfLoop(head)->data;
    cout<<endl;
    removeLoop(head);
    cout<<"loop is removed and ll is:"<<endl;
    print(head);


}