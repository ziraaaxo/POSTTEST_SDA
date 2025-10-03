#include <iostream>
#include <string>
using namespace std;

// struktur node untuk stack
struct Node {
    char data;
    Node* next;
};

// fungsi push untuk memasukkan elemen ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// fungsi pop untuk mengeluarkan elemen dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // stack kosong
    Node* temp = top;      
    char poppedValue = temp->data; 
    top = top->next;         
    delete temp;            
    return poppedValue;      
}

// fungsi membalik string menggunakan stack
string reverseString(string s) {
    Node* stackTop = nullptr; // inisialisasi stack kosong
    string reversed = "";

    // 1. Masukkan semua karakter string ke dalam stack
    for (char c : s) {     // loop setiap karakter dari string s
        push(stackTop, c);     // setiap karakter dipush ke stack. karena sifat stack adalah LIFO, karakter terakhir akan berada di atas stack
    }

    // 2. Keluarkan semua karakter dari stack
    while (stackTop != nullptr) {     // selama stack tidak kosong, lakukan pop
        reversed += pop(stackTop);     // tambahkan hasil pop ke string reversed. karena diambil dari belakang dulu, urutannya otomatis terbalik
    }

    return reversed; // hasil string terbalik
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    return 0;
}
