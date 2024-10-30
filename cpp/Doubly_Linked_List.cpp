#include <iostream>
#include <cstdlib>

using namespace std;

// Structure for doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Head and tail pointers
Node* head = nullptr;
Node* tail = nullptr;

// Function declarations
void insert(int val, int k);
void del(int k);
void print();

int main() {
    int val;
    int k;
    // Insert nodes
    insert(11, 1);
    insert(22, 2);
    insert(33, 3);
    print(); // Print list
    cout << endl;
    del(1);  // Delete node
    print();  \// Print list
    cout << endl;

    return 0;
}

// Print the linked list
void print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Insert a node at position k
void insert(int val, int k) {
    Node* p = new Node();
    p->data = val;

    if (head == nullptr) {
        // Insert at the beginning if list is empty
        p->next = nullptr;
        p->prev = nullptr;
        head = p;
    } else if (k == 1) {
        // Insert at the beginning
        head->prev = p;
        p->next = head;
        p->prev = nullptr;
        head = p;
    } else {
        // Insert at position k
        Node* temp = head;
        while ((k - 2) > 0 && temp->next != nullptr) {
            temp = temp->next;
            k--;
        }
        if (temp->next == nullptr) {
            // Insert at the end
            temp->next = p;
            p->prev = temp;
            p->next = nullptr;
        } else {
            // Insert in the middle
            p->next = temp->next;
            p->prev = temp;
            temp->next->prev = p;
            temp->next = p;
        }
    }
}

// Delete a node at position k
void del(int k) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    if (k == 1) {
        // Deletion at the beginning
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    } else {
        // Deletion at position k
        while ((k - 1) > 0 && temp->next != nullptr) {
            temp = temp->next;
            k--;
        }
        if (temp->next != nullptr) {
            // Delete in the middle
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        } else {
            // Delete at the end
            temp->prev->next = nullptr;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }
}
