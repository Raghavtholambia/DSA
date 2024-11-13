#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory of node with value " << value << " is deleted." << endl;
    }
};

void middle(node*head)
{
    if (head==NULL||head->next==NULL)
    {
        cout<<"middle: "<<head->data<<endl;
        return;
    }
    node*slow=head;
    node*fast=head->next;

    while (fast!=NULL)
    {
        fast=fast->next;
        if (fast!=NULL)
        {
             fast=fast->next;
        }
        slow=slow->next;
        
    }
    cout<<"middle: "<<slow->data<<endl;  
}
void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;  // Link the new node to the last node
    tail = temp;        // Update the tail pointer to the new node
}

void print(node* head ,node*&tail) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        if (temp->next==NULL)
        {
            tail=temp;
        }
        temp = temp->next;
        
    }

    cout << endl;
    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;
}

void insertAtAnyPosition(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    node* nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

node* revLL(node*&head ,node*&tail)
{
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;   
       
                         
    }
    return prev;
}



node* revK(node*head,int k)
{
    node*temp=head;
    node*prev=NULL;
    node*forward=NULL;
    
    if (head==NULL)
    {
        return NULL;
    }
    int cnt=0;
    while (k>cnt && temp!=NULL)
    {
        forward=temp->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
        cnt++;
    }
    if (forward!=NULL)
    {
       head->next=revK(forward,k);
    }
    
    


return prev;
}
    
bool checkCirLL(node*head)
{
    if (head==NULL || head->next==NULL)
    {
        return true;
    }
    node*temp=head;
    while (temp!=NULL)
    {
        if (temp->next==head)
        {
            return true;
        }
        temp=temp->next;
        
    }
    return false;
    
    
}



int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 3, 32);
    insertAtAnyPosition(head, tail, 2, 39);
    insertAtAnyPosition(head, tail, 3, 12);

    cout << endl << "New List:" << endl;
    print(head,tail);


    head=revK(head,2);
    print(head,tail);


    return 0;
}