#include <iostream> //reverse doubly linked list
#include <vector>
#include <limits.h>
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
    ~Node()
    {
        cout << "node deleted with value" << this->data << endl;
    }
};

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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverseDLLUsingLoop(Node *&head)
{
    if (head == NULL)
    {
        // empty dll
        return head;
    }
    if (head->next == NULL)
    {
        // single node dll
        return head;
    }

    // more than one node
    Node *prevNode = NULL;
    Node *currNode = head;
    while (currNode != NULL)
    {
        // prevNode=currNode;
        currNode->prev = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = currNode->prev;
    }
    return prevNode;
}

Node *reverseDLLUsingRecur(Node *&prevNode, Node *&currNode)
{
    //  if(head==NULL && head->next==NULL){
    //     //empty dll or sigle nodes
    //     return head;
    // }
    if (currNode == NULL)
    {
        return prevNode;
    }
    currNode->prev = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = currNode->prev;
    return reverseDLLUsingRecur(prevNode, currNode);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 30);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 80);
    InsertAtHead(head, tail, 70);
    print(head);
    // head = reverseDLLUsingLoop(head);
    // cout << "reverse ll is:" << endl;
    // print(head);

    Node *prevNode = NULL;
    Node *currNode = head;
    head = reverseDLLUsingRecur(prevNode, currNode);
    cout << "reverse ll is:" << endl;
    print(head);
}