#include <iostream> //write a function to Add two numbers in LL
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
    cout<<endl;
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

Node *addTwoNumbers(Node *&num1, Node *&num2)
{
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum = sum + temp1->data;
        }
        if (temp2)
        {
            sum = sum + temp2->data;
        }
        Node *ansNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = ansNode;
        curr = curr->next;

        if (temp1)
        {
            temp1 = temp1->next;
        }

        if (temp2)
        {
            temp2 = temp2->next;
        }
    }
    if (carry)
    {
        Node *ansNode = new Node(carry);
        curr->next=ansNode;
    }
    return dummyNode->next;
}
int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtHead(head1, tail1, 5);
    InsertAtHead(head1, tail1, 3);
    // InsertAtHead(head1, tail1, 1);

    Node *head2 = NULL;
    Node *tail2 = NULL;

    InsertAtHead(head2, tail2, 9);
    InsertAtHead(head2, tail2, 9);
    InsertAtHead(head2, tail2, 5);
    InsertAtHead(head2, tail2, 4);

    print(head1);
    print(head2);

    // head1=reverseUsingLoop(head1);
    // head2=reverseUsingLoop(head2);
    // cout<<"after reversing no the actual no is"<<endl;
    // print(head1);
    // print(head2);

    Node* answer=addTwoNumbers(head1,head2);

    cout<<"adiition of two no is:"<<endl;
    answer=reverseUsingLoop(answer);
    print(answer);


}