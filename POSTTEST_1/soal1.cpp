#include <iostream>
using namespace std;

// nim genap 016
// fungsi membalik array dengan parameter pointer
void balik_array(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

// fungsi untuk mengecek bilangan prima
bool prima(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// program utama
int main() {
    const int n = 7;
    int arr[n];
    int angka = 2, index = 0;

    // mengisi array dengan bilangan prima
    while (index < n) {
        if (prima(angka)) {
            arr[index] = angka;
            index++;
        }
        angka++;
    }

    cout << "NIM Genap 016, menampilkan 7 bilangan prima dalam array:" << endl;
    // menampilkan array sebelum dibalik
    cout << endl;
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // panggil fungsi balik array
    balik_array(arr, n);
    // menampilkan array setelah dibalik
    cout << "Array setelah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
