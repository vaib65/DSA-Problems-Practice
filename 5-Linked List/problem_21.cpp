#include <iostream> //intersection point of ll optimal approach not working on vs code
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
    cout << endl;
}


Node *findIntersectonPoint(Node *&head1, Node *&head2)
{
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2){
            return t1;
        }
        if(t1==NULL){
            t1=head2;
        }
         if(t2==NULL){
            t2=head1;
        }
    }
    return t1;
    
}
int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtHead(head1, tail1, 2);
    InsertAtHead(head1, tail1, 6);
    InsertAtHead(head1, tail1, 4);
    InsertAtHead(head1, tail1, 1);
    InsertAtHead(head1, tail1, 3);
    // InsertAtHead(head1, tail1, 1);

    Node *head2 = NULL;
    Node *tail2 = NULL;
    InsertAtHead(head2, tail2, 2);
    InsertAtHead(head2, tail2, 6);
    InsertAtHead(head2, tail2, 4);
    InsertAtHead(head2, tail2, 5);
    InsertAtHead(head2, tail2, 9);
    InsertAtHead(head2, tail2, 7);
    InsertAtHead(head2, tail2, 8);

    print(head1);
    print(head2);

    Node *ans = findIntersectonPoint(head1, head2);
    print(ans);
}