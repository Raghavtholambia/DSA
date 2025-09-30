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

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

                                        //merging linklist here


node* solve(node*first,node*second)
{


    if (first->next==NULL)
    {
        first->next=second;
    }
    


    node*curr1=first;
    node*curr2=second;
    node*next1=curr1->next;
    node*next2=curr2->next;

    if (curr2->data>=curr1->data && curr2->data<=next1->data)
    {
        curr1->next=curr2;
        next2=curr2->next;
        curr2->next=next1;
        curr1=curr2;
        curr2=next2;    
    }
    else{
        curr1=next1;
        next1=next1->next;

        if (next1==NULL)
        {
            next1->next=curr2;
            return first;
        }
        
    }

    return first;

}


node* mergeTwoSortedLL(node*first,node*second)
{
    if (first==NULL)    return second;

    if(second==NULL)  return first;

    if(first->data<second->data)  return solve(first,second);
    else return solve(second,first);
  
    
}





int main() {
    node* node1 = new node(10);
    
    node* head1 = node1;
    node* tail1 = node1;

    insertAtTail(tail1, 111);
    insertAtAnyPosition(head1, tail1, 2, 62);

    cout << endl << "first List:" << endl;
    print(head1);

    cout << "Head1: " << head1->data << " ";
    cout << "Tail1: " << tail1->data << endl;

    node* node2 = new node(11);
    
    node* head2 = node2;
    node* tail2 = node2;

    insertAtTail(tail2, 12);
    insertAtAnyPosition(head2, tail2, 2, 12);

    cout << endl << "secont List:" << endl;
    print(head2);

    cout << "Head2: " << head2->data << " ";
    cout << "Tail2: " << tail2->data << endl;

    node*head=mergeTwoSortedLL(head1,head2);
    print(head);

    cout << "Head2: " << head->data << " ";
  
    return 0;
}
