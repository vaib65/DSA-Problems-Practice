#include<iostream>//remove duplicate from sorted ll
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
void removeDuplicate(Node*& head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        return ;
    }
    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL)&&(curr->data==curr->next->data)){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete temp;
        }else{
            curr=curr->next;
        }
    }
   
    return ;

}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(20);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(50);
    Node* seventh=new Node(70);
   

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    // sixth->next=NULL;
    sixth->next=seventh;
    seventh->next=NULL;

    cout<<"ll is:"<<endl;
    print(head);
    removeDuplicate(head);
    print(head);
}