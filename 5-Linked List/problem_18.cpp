#include <iostream> //remove nth node from end basic approach
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
    ~Node()
    {
        cout << "node deleted with value:" << this->data << endl;
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
    cout << endl;
}

Node *deleteKthNode(Node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    // delete head or single node
    if (count == k)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    int result=count-k;
    Node *temp2 = head;
    while (temp2 != NULL)
    {
        result--;
        if (result == 0)
        {
            break;
        }
        temp2 = temp2->next;
    }
    Node *deleteNode = temp2->next;
    temp2->next = temp2->next->next;
    delete deleteNode;

    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 0);
    
    print(head);
   
    head = deleteKthNode(head, 4);
    cout<<"after delete ll is:"<<endl;
    print(head);
}