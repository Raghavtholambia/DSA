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

void deleteAtAnyPostion(node*& head, node*& tail, int pos) {
    if (pos == 1) {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    node* prev = NULL;
    node* temp = head;
    int cnt = 1;

    while (cnt < pos) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        tail = prev;  // Update the tail if we're deleting the last node
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    print(head);

    deleteAtAnyPostion(head, tail, 2);
    cout << endl << "New List:" << endl;
    print(head);

    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;

    return 0;
}
