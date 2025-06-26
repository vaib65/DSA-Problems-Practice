#include <iostream> //singly ll basic insertion deletion operation incomplete code
#include <vector>
#include <limits.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data,Node* next)
    {
       this-> data = data;
       this-> next =next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "node deleted with value" << this->data << endl;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *deleteFirst(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
}

Node *deleteLast(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deleteAtPosition(Node *&head, int position)
{
    if (head == NULL)
    {
        return head;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == position)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteByValue(Node *&head, int value)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {

        if (temp->data == value)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *InsertAtHead(Node *&head, int data)
{
    // if empty list
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return newNode;
    }
    // step 1 create node
    Node *newNode = new Node(data);
    // step 2 attach newnode to head
    newNode->next = head;
    // step 3 point head to newnode
    head = newNode;
    return newNode;
}

Node *InsertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    temp->next = newNode;
    return head;
}

Node *insertAtPosition(Node *&head, int data, int position)
{
    if (head == NULL)
    {
        if (position == 1)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        else
        {
            return head;
        }
    }
    if (position == 1)
    {
         return InsertAtHead(head,  data);
        
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==(position-1)){
            Node* newNode=new Node(data);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
Node* head=NULL;
head=InsertAtHead(head,2);
head=InsertAtHead(head,1);
head=InsertAtHead(head,4);
head=InsertAtTail(head,6);
head=InsertAtTail(head,7);
head=InsertAtTail(head,9);
head=insertAtPosition(head,1,2);


print(head);
}