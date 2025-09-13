#include <iostream>
using namespace std;

// nim genap 016
// membuat array ukuran 3x3
int main() {
    cout << "Matriks berukuran 3x3: " << endl;
    int matriks[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriks[i][j] = i + j;
        }
    }
    // menampilkan matriks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // menghitung jumlah elemen baris genap yaitu baris 0 dan baris 2
    int jumlah = 0;
    cout << endl;
    cout << "Penjumlahan elemen baris genap (0 dan 2): " << endl;

    bool pertama = true;
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { // baris genap
            for (int j = 0; j < 3; j++) {
                if (!pertama) {
                    cout << " + ";
                }
                cout << matriks[i][j];
                jumlah += matriks[i][j];
                pertama = false;
            }
        }
    }
    cout << " = " << jumlah << endl;
    return 0;
}
