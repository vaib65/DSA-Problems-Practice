#include<iostream>//sort 0,1,2
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

Node* sortZeroOneTwo(Node*&head){
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
         else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
         else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }

    zero->next=(oneHead->next)?(oneHead->next):(twoHead->next);
    one->next=twoHead->next;
    two->next=NULL;
    Node* newHead=zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;
    
    return newHead;

}
int main(){
 
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 2);
    
    //1 not present
    // InsertAtHead(head, tail, 2);
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 2);
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 2);

    //0 not present
    // InsertAtHead(head, tail, 2);
    // InsertAtHead(head, tail, 1);
    // InsertAtHead(head, tail, 2);
    // InsertAtHead(head, tail, 1);
    // InsertAtHead(head, tail, 1);
    // InsertAtHead(head, tail, 2);

    //2 not present
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 1);
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 1);
    // InsertAtHead(head, tail, 0);
    // InsertAtHead(head, tail, 1);

    print(head);
    head=sortZeroOneTwo(head);
    cout<<"after sorting:"<<endl;
    print(head);
}