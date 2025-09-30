#include <iostream>
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

void insertAtAnPosition(node*& tail, int element, int data) {
    if (tail == NULL) {
        node* newNode = new node(data);
        tail = newNode;
        tail->next = tail;
        return;
    }

    node* curr = tail;
    do {
        if (curr->data == element) {
            node* temp = new node(data);
            temp->next = curr->next;
            curr->next = temp;
            if (curr == tail) {
                tail = temp;  // Update tail if we insert at the tail
            }
            return;
        }
        curr = curr->next;
    } while (curr != tail);
}

int getLength(node* tail) {
    if (tail == NULL) return 0;
    node* temp = tail->next;
    int cnt = 1;
    while (temp != tail) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void print(node* tail) {
    if (tail == NULL) return;
    node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void splitFromMiddle(node*& tail, node*& tail1, node*& tail2) {
    if (tail == NULL) return;

    int len = getLength(tail);
    int mid = len / 2;
    node* temp = tail->next;
    node* prev = NULL;

    // Traverse to midpoint
    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = temp->next;
    }

    // First half will end at prev, so make it circular
    prev->next = tail->next;
    tail1 = prev;  // New tail of first half

    // Second half will start at temp, make it circular
    node* startSecond = temp;
    while (temp->next != tail->next) {
        temp = temp->next;
    }
    temp->next = startSecond;
    tail2 = temp;  // New tail of second half
}

int main() {
    node* tail = NULL;
    insertAtAnPosition(tail, 3, 5);
    insertAtAnPosition(tail, 5, 4);
    insertAtAnPosition(tail, 5, 5);
    insertAtAnPosition(tail, 5, 2);
    insertAtAnPosition(tail, 2, 8);
    insertAtAnPosition(tail, 8, 8);

    cout << "Original Circular Linked List:" << endl;
    print(tail);

    // Splitting the list into two halves
    node* tail1 = NULL;
    node* tail2 = NULL;
    splitFromMiddle(tail, tail1, tail2);

    cout << "First half after splitting:" << endl;
    print(tail1);

    cout << "Second half after splitting:" << endl;
    print(tail2);

    return 0;
}
