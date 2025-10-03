#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // kasus 1: list masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // kasus 2: data baru lebih kecil dari head -> masukkan sebelum head
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;  // tail adalah node sebelum head (karena circular)
        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode; // update head karena data baru jadi terkecil
        return;
    }

    // kasus 3: cari posisi yang tepat di tengah/akhir
    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // sisipkan setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // expected output: 10 20 30 40
    printList(head);

    return 0;
}
