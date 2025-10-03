#include <iostream>
#include <string>
using namespace std;

// struktur node stack
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

// fungsi pengecekan keseimbangan kurung
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr; // stack kosong awalnya

    for (char c : expr) {
        // jika kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // jika kurung tutup, lakukan pengecekan
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // jika tidak ada pasangan buka
            char topChar = pop(stackTop);

            // cek pasangan apakah cocok
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // salah pasangan
            }
        }
    }

    // jika setelah loop stack kosong, berarti seimbang
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") 
         << endl;
    // expected output: Seimbang

    string expr2 = "{[(])}";
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") 
         << endl;
    // expected output: Tidak Seimbang

    string expr3 = "((())){}[]";
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") 
         << endl;
    // expected output: Seimbang

    string expr4 = "([)]";
    cout << expr4 << " -> " 
         << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") 
         << endl;
    // expected output: Tidak Seimbang

    return 0;
}
