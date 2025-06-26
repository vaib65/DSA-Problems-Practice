#include <iostream> //reverse linked list
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
        cout << "node deleted with value" << this->data << endl;
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
}

Node *reverseLinkedList(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        // reverse hochukinhai
        return prev;
    }
    // case 1 solve then recur will takecare
    Node *forward = curr->next;
    curr->next = prev;
    reverseLinkedList(curr, forward);
}

Node *reverseUsingLoop(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *reverseUsingRecur(Node *&prev, Node *&curr)
{
    // bc
    if (curr == NULL)
    {
        return prev;
    }
    // 1 case solve then recur
    Node *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    return reverseUsingRecur(prev,curr);
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 330);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 80);

    print(head);
    cout << endl;
    Node *prev = NULL;
    Node *curr = head;
    // head=reverseLinkedList(prev,curr);
    // head = reverseUsingLoop(head);
    head=reverseUsingRecur(prev,curr);

    cout << "Reverse LL is:" << endl;
    print(head);
    cout << endl;
}