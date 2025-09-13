#include <iostream>
using namespace std;

// nim genap 016
// fungsi untuk menukar dua variabel integer dengan operator reference (&)
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// program utama
int main() {
    int x, y;

    // menginput dua nilai
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    // menampilkan variabel sebelum pertukaran
    cout << endl;
    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // memanggil fungsi tukar
    tukar(x, y);
    // menampilkan variabel sesudah pertukaran
    cout << endl;
    cout << "Sesudah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
