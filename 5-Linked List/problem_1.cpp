#include <iostream>//singly linked list  
#include <vector>//insertion at start,end ,middle
#include <limits.h>// deleton from start,end,middle
using namespace std;//find length of LL
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

// insert at end or tail
void InsertAtTail(Node *&head, Node *&tail, int data)
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
    // step 2 attach  head to newnode
    tail->next = newNode;
    // step 3 point tail to newnode
    tail = newNode;
}

void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // if empty list
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step 1 findn pos of curr and prev

    if (position == 0)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    int length = findLength(head);

    if (position >= length)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    // step 1 find prev and curr
    Node *prev = head;
    int i = 1;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step2
    Node *newNode = new Node(data);
    // step 3
    newNode->next = curr;
    // step4
    prev->next = newNode;
}

void deleteFirst(Node *&head){
    if(head==NULL||head->next==NULL){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
}

void deleteLast(Node *&head){
    if(head==NULL||head->next==NULL){
        return;
        }
        
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
       
        delete temp->next;
        temp->next=NULL;
        return;
    
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // empty ll
    if (head == NULL)
    {
        cout << "cannot delete" << endl;
        return;
    }
    
    //delete first
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    //delete last
    int length = findLength(head);
    // step 1 find prev
    if (position == length)
    {
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step 2
        prev->next = NULL;
        // step 3
        Node *temp = tail;
        // step 4
        tail = prev;
        delete temp;
        return;
    }

    

    //delete middle
    //step 1 find prev and curr
    int i=1;
    Node* prev=head;
    while(i<position-1){
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;

    //step 2
    prev->next=curr->next;
    //step 3
    curr->next=NULL;
    //step 4
    delete curr;

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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 60);
    // InsertAtHead(head, tail, 40);
    // InsertAtHead(head, tail, 50);
    // InsertAtHead(head, tail, 10);
    // InsertAtHead(head, tail, 0);
    // InsertAtTail(head, tail, 3);
    // InsertAtPosition(head, tail, 44, 3);
    // InsertAtPosition(head, tail, 22, 1);

    print(head);
    cout<<endl;

    deleteNode(head, tail, 1);
    // deleteFirst(head);
    // deleteLast(head);
    print(head);
}