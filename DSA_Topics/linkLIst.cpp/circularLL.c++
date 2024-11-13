#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node()
    {
        int value=this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout << "Memory of node with value " << value << " is deleted." << endl;
  
    }
};

void insertAtAnPosition(node*&tail,int element,int data)
{
    if (tail==NULL)
    {
        node*newNode=new node(data);
        tail=newNode;
        newNode->next=newNode;
        return;
    }
    node*curr=tail;
    while (curr->data!=element)
    {
        curr=curr->next;
    }
    node*temp=new node(data);
    temp->next=curr->next;
    curr->next=temp;
}

void deleteNode(node*&tail,int value)
{
    if (tail==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    node*prev=tail;
    node*curr=prev->next;

    while (curr->data!=value)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    
    
}

void print(node*tail)
{
    node*temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (temp!=tail);
    cout<<endl;
}

int main()
{
    node*tail=NULL;
    insertAtAnPosition(tail,3,5);
    print(tail);
    insertAtAnPosition(tail,5,4);
    print(tail);
    insertAtAnPosition(tail,5,5);
    print(tail);
    
    deleteNode(tail,5);
    print(tail);

    return 0;
}