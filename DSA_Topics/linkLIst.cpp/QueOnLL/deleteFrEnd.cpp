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

// Insert at the head
void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// Insert at the tail
void insertAtTail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

// Print the linked list
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at any position
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

// Reverse the linked list
node* rev(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* forward = NULL;
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Remove the nth node from the end
node* removeNthFromEnd(node* head, int n) {
    // Reverse the linked list
    node* temp = rev(head);

    // Handle edge cases
    if (temp == NULL) return NULL; // Empty list
    if (n == 1) {
        // Remove the head node of the reversed list
        head = temp->next;
        delete temp;
        return rev(head);
    }

    // Traverse the reversed list to find the (n-1)th node
    node* prev = NULL;
    node* curr = temp;
    for (int i = 1; i < n && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }

    // Remove the nth node if it exists
    if (curr != NULL && prev != NULL) {
        prev->next = curr->next;
        delete curr;
    }

    // Reverse the list back to its original order
    return rev(temp);
}

// Main function
int main() {
    // Create the linked list
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);

    cout << "Original list: ";
    print(head);

    // Remove the nth node from the end
    head = removeNthFromEnd(head, 1);

    cout << "List after removing 1st node from the end: ";
    print(head);

    return 0;
}
