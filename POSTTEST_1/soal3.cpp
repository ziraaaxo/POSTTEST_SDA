#include <iostream>
using namespace std;

// nim genap 016
// membuat struct Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

// program utama
int main() {
    const int n = 4;
    Mahasiswa mhs[n];

    // input data mahasiswa
    cout << "Silahkan input data 4 mahasiswa ~" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }

    // mengurutkan berdasarkan IPK secara ascending
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }

    // menampilkan hasil
    cout << endl;
    cout << "Data Mahasiswa setelah diurutkan berdasarkan IPK (ascending): " << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << mhs[i].nama 
             << " | NIM: " << mhs[i].nim 
             << " | IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}