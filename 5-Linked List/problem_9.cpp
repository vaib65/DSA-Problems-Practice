#include <iostream> //find middle of LL
#include <vector>
#include <limits.h>
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
    cout << endl;
}

//find middle of ll
Node* findMiddle(Node* & head){
    //if ll is empty
    if(head==NULL){
        return head;
    }
    //if ll has single element
    if(head->next==NULL){
        return head;
    }
    //if ll has more than one element
    Node* slow=head;
    // Node* fast=head;
    Node* fast=head->next;
    while(slow!=NULL&& fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 70);
    InsertAtHead(head, tail, 80);

    print(head);
    cout<<"middle element is:"<<findMiddle(head)->data;
}

