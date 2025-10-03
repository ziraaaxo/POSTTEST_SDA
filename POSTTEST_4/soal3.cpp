#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;     
};

// fungsi enqueue, untuk menambahkan dokumen ke antrian (belakang)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // jika queue kosong
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode; // hubungkan rear lama ke node baru
        rear = newNode;       // geser rear ke node baru
    }
}

// fungsi dequeue, untuk mengeluarkan dokumen dari antrian (depan)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    Node* temp = front;             // simpan node depan
    string doc = temp->document;    // ambil nama dokumen
    front = front->next;            // geser front ke elemen berikutnya

    // jika setelah dequeue queue kosong, rear juga harus null
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp; // hapus node lama
    return doc;  // kembalikan nama dokumen
}

// fungsi untuk memproses semua dokumen dalam queue
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
