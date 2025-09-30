//remove duplicate in the LL


#include <iostream>
#include <map>
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
        cout << "Memory of node with value " << data << " is deleted." << endl;
    }
};

void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
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

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, d);
    } else {
        node* nodeToInsert = new node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

void removeDuplicatesInunsortedArr(node* head) {
    if (head == NULL) return;

    map<int, bool> checked;
    node* temp = head;
    node* prev = NULL;

    while (temp != NULL) {
        if (checked[temp->data]) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            checked[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 4, 62);

    cout << "New List:" << endl;
    print(head);

    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;

    cout << "List after removing duplicates:" << endl;
    removeDuplicatesInunsortedArr(head);
    print(head);

    // Explicitly delete all remaining nodes to see correct destructor output
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
