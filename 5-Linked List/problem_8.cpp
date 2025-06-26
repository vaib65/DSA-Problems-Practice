#include<iostream>//segrregate odd and even node in LL optimal approach
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

Node* segregateOddAndEvenLL(Node* &head){
    Node* odd=head;
    Node* even=head->next;
    Node* temp=head->next;
    while(even!=NULL&& even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=temp;
    return head;
   
    

}

int main(){
  
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 77);
    InsertAtHead(head, tail, 60);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 10);
    print(head);
    head=segregateOddAndEvenLL(head);
    
    cout<<"answer is:";
    print(head);
}