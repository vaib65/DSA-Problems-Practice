#include <iostream> //intersection point of ll length difference  approach
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

Node *collisionPoint(Node *temp1, Node *temp2, int distance)
{
    while (distance)
    {
        distance--;
        temp2 = temp2->next;
    }

    while (temp1->data != temp2->data)
    {

        temp1 = temp1->next;

        temp2 = temp2->next;
    }
    return temp2;
}

Node *findIntersectonPoint(Node *&head1, Node *&head2)
{
    int count1 = 0;
    int count2 = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    // count first ll noddes
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    // count second ll nodes
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 < count2)
    {
        return collisionPoint(head1, head2, count2 - count1);
    }
    else
    {
        return collisionPoint(head2, head1, count1 - count2);
    }

    return NULL;
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
    InsertAtHead(head2, tail2, 2);
    InsertAtHead(head2, tail2, 2);

    print(head1);
    print(head2);

    Node *ans = findIntersectonPoint(head1, head2);
    print(ans);
}