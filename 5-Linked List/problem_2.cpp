#include <iostream>//doubly linlefd list
#include <vector>//insert at start,end,middle
#include <limits.h>//delete at start ,end ,middle
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
     ~Node(){
        cout<<"node deleted with value"<<this->data<<endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void InsertAttail(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
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
    else
    {
        //insert at first position
        if (position == 1)
        {
            InsertAtHead(head, tail, data);
            return;
        }
        //insert at tail/last position
        int len=getLength(head);
        if(position>len){
            InsertAttail(head,tail,data);
            return;
        }

        //insert at kth position 
        //step1  find prev and curr node
        int i=1;
        Node* prevNode=head;
        while(i<position-1){
            prevNode=prevNode->next;
            i++;
        }
        Node* currNode=prevNode->next;
        //step 2 create node
        Node* newNode=new Node(data);
        prevNode->next=newNode;
        newNode->prev=prevNode;
        currNode->prev=newNode;
        newNode->next=currNode;
        


    }
}

void deleteNode(Node*& head,Node*&tail,int position){
    //empty ll
    if(head==NULL){
        cout<<"cannot delete ,ll is empty"<<endl;
        return;
    }
    //invalid position
    int length=getLength(head);
    if(position>length){
         cout<<"cannot delete ,enter valid position"<<endl;
        return;
    }
    //single node delete
    if(head->next==NULL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
       
    }

    //delete firsr position
    if(position==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    //delete at last position
    
    if(position==length){
        Node* temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
        delete temp;
        return;
    }

    //delete at middle
    int i=1;
    Node* leftNode=head;
    while(i<position-1){
        leftNode=leftNode->next;
        i++;
    }
    Node* currNode=leftNode->next;
    Node* rightNode=currNode->next;
    leftNode->next=rightNode;
    rightNode->prev=leftNode;
    currNode->prev=NULL;
    currNode->next=NULL;
    delete currNode;
    


}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 20);
    // InsertAtHead(head, tail, 70);
    // InsertAtHead(head, tail, 40);
    // InsertAtHead(head, tail, 10);
    // InsertAttail(head, tail, 0);

    print(head);
    cout<<endl;
    // InsertAtPosition(head,tail,44,5);
    // print(head);

    deleteNode(head,tail,1);
    print(head);
}