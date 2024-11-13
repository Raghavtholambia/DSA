                                           //imp! is loop is present in LL
#include<iostream>
#include<map>
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
    cout<<"head: "<<head->data<<"tail: "<<tail->data<<endl;
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

// bool isLoopPresent(node*head)
// {
//     node*temp=head;
//     map<node*,bool> viseted;
//     if (head==NULL)
//     {
//         return true;
//     }
//     while (temp!=NULL)
//     {
//         //cycle is present
//         if (viseted[temp]==true)
//         {
//             cout<<"loop is present on: "<<temp->data<<endl;
//             return true;
//         }
//         viseted[temp]=true;
//         temp=temp->next;
//     }
//     return false;    
// }


node* floydDetectLoop(node*head)
{
    if (head==NULL)
        return NULL;
    node*fast=head;
    node*slow=head;

    while (fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if (fast==slow)
        {
            cout<<"loop detect on: "<<fast->data<<endl;
            return fast;
        }
        
    }
    return NULL;
    
}


node*startingPointLL(node*head)
{
    node*intersection=floydDetectLoop(head);
    node*slow=head;

    while (slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
    
}


void removeLoop(node*head)
{
    if (head==NULL)
    {
        return;
    }

    node* startingPointL=startingPointLL(head);
    node*temp =startingPointL;
    while (temp->next!=startingPointL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}


int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 3, 32);
    insertAtAnyPosition(head, tail, 3, 111);
    print(head,tail);
    cout<<"head: "<<head->data<<"tail: "<<tail->data<<endl;
    tail->next=head->next;

if (floydDetectLoop(head))
{
    cout<<"loop is present"<<endl;
}
else
cout<<"loop is not present"<<endl;

node*startingPoint=startingPointLL(head);

cout<<"starting point is: "<< startingPoint->data<<endl;

removeLoop(head);
cout <<"loop removed"<<endl;
    

if (floydDetectLoop(head))
{
    cout<<"loop is present"<<endl;
}
else
cout<<"loop is not present"<<endl;


print(head,tail);


return 0;
}