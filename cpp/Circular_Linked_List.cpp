#include <iostream>
#include <cstdlib>

using namespace std;

// Structure for circular linked list node
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Function declarations
void linkedlist(int val, int k);
void del(int k);
void print();

int main() {
    // Insertion
    cout << "hello" << endl;
    linkedlist(111, 1);
    linkedlist(2322, 2);
    linkedlist(3333, 3);
    print();
    cout << endl;

    linkedlist(4444, 2);
    print();
    cout << endl;

    // Deletion
    del(1);
    cout << "final list: ";
    print();
    cout << endl;

    return 0;
}

// Print the circular linked list
void print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
}

// Insert a node at position k
void linkedlist(int val, int k) {
    Node* p = new Node();
    p->data = val;

    if (head == nullptr) {
        cout << "List is empty" << endl;
        head = p;
        p->next = p;
    } else if (k == 1) {
        // Insertion at the beginning
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        p->next = head;
        head = p;
        temp->next = head;
    } else {
        // Insertion at position k
        Node* t2 = head;
        while ((k - 2) > 0 && t2->next != head) {
            t2 = t2->next;
            k--;
        }
        p->next = t2->next;
        t2->next = p;
    }
}

// Delete a node at position k
void del(int k) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp;
    if (k == 1) {
        // Deletion at the beginning
        temp = head;
        Node* t1 = head;
        while (t1->next != head) {
            t1 = t1->next;
        }
        if (head->next == head) {
            head = nullptr;
        } else {
            head = head->next;
            t1->next = head;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    } else {
        // Deletion at position k
        Node* t1 = nullptr;
        temp = head;
        while ((k - 1) > 0 && temp->next != head) {
            t1 = temp;
            temp = temp->next;
            k--;
        }
        t1->next = temp->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }
}
