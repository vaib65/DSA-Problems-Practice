#include <iostream> // delete nth node from end optimal approach
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
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 80);
    // InsertAtHead(head, tail, 42);
    // InsertAtHead(head, tail, 88);
    // InsertAtHead(head, tail, 12);
    // InsertAtHead(head, tail, 25);
    // InsertAtHead(head, tail, 60);

    print(head);

    head = deleteKthNode(head, 1);
    cout << "after delete ll is:" << endl;
    print(head);
}