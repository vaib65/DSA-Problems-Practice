#include<iostream>//segrregate odd and even node in LL Basic approach
#include<vector>
#include<limits.h>
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
    ~Node(){
        cout<<"node deleted with value"<<this->data<<endl;
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

Node* segregateOddAndEvenLL(Node* &head,  vector<int>&arr){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    Node* temp2=head->next;
    while(temp2!=NULL && temp2->next!=NULL){
        arr.push_back(temp2->data);
        temp2=temp2->next->next;
    }
    if(temp2){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }

    Node* temp3=head;
    int i=0;
    while(temp3!=NULL){
        temp3->data=arr[i];
        i++;
        temp3=temp3->next;
    }
    return head;
    

}

int main(){
    vector<int>arr;
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 77);
    InsertAtHead(head, tail, 60);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 50);
    // InsertAtHead(head, tail, 10);
    print(head);
    head=segregateOddAndEvenLL(head,arr);
    
    cout<<"answer is:";
    print(head);
}