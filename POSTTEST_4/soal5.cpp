#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    // jika list kosong atau hanya 1 node, maka tidak ada yang ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;      // tail adalah prev dari head
    Node* head_next = head->next;     // node setelah head
    Node* tail_prev = tail->prev;     // node sebelum tail

    // kasus 2 node → cukup tukar head_ref
    if (head->next == tail && tail->next == head) {
        head_ref = tail;
        return;
    }

    // putuskan koneksi dan sambungkan ulang

    // menghubungkan tail ke head_next
    tail->next = head_next;
    head_next->prev = tail;

    // menghubungkan head ke tail_prev
    head->prev = tail_prev;
    tail_prev->next = head;

    // menghubungkan tail <-> head
    tail->prev = head;
    head->next = tail;

    // update head_ref ke tail (karena tail jadi head baru)
    head_ref = tail;
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

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // expected output: 5 2 3 4 1
    printList(head);

    return 0;
}
