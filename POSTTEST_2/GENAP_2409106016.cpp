#include <iostream>
#include <string>
using namespace std;

// deklarasi fungsi
void display();
void addLast();
void addSpecific();
void deleteFirst();
void deleteLast();
void deleteSpecific();
void updateStatus();

// mengubah warna pada teks
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

// struktur node
struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status; // ontime, delayed, boarding
    Flight* next;
};

// variabel global
Flight* head = nullptr;
int counterJadwal = 0;
string namaUser = "Azira Faradina";
string nimUser = "2409106016";

// fungsi membuat kode penerbangan
string buatKode() {
    string tigaDigit = nimUser.substr(nimUser.length() - 3);
    if (counterJadwal == 0) {
        counterJadwal++;
        return "JT-" + tigaDigit;
    } else {
        counterJadwal++;
        return "JT-" + tigaDigit + "-" + to_string(counterJadwal - 1);
    }
}

// tambah jadwal di akhir
void addLast() {
    Flight* newNode = new Flight;
    newNode->kodePenerbangan = buatKode();
    cout << "Masukkan Tujuan Penerbangan: ";
    getline(cin, newNode->tujuan);
    cout << "Masukkan Status Penerbangan (ontime/delayed/boarding): ";
    getline(cin, newNode->status);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Flight* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    cout << GREEN << "Jadwal berhasil ditambahkan dengan kode: "
         << newNode->kodePenerbangan << RESET << endl;
}

// menyisipkan jadwal baru di posisi ke-7
void addSpecific() {
    int pos = 7;
    if (pos <= 1) {
        cout << RED << ">> Posisi tidak valid <<" << RESET << endl;
        return;
    }

    Flight* newNode = new Flight;
    newNode->kodePenerbangan = buatKode();
    cout << "Masukkan Tujuan Penerbangan: ";
    getline(cin, newNode->tujuan);
    cout << "Masukkan Status Penerbangan (ontime/delayed/boarding): ";
    getline(cin, newNode->status);

    Flight* temp = head;
    int hitung = 1;

    while (temp != nullptr && hitung < pos - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << RED << ">> Posisi ke-" << pos 
             << " tidak boleh melebihi panjang list <<" << RESET << endl;
        delete newNode;
        return;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << GREEN << "Jadwal berhasil disisipkan di posisi ke-" << pos << RESET << endl;
    }
}

// hapus jadwal pertama
void deleteFirst() {
    if (head == nullptr) {
        cout << RED << ">> Belum ada jadwal penerbangan <<" << RESET << endl;
        return;
    }
    Flight* temp = head;
    head = head->next;
    cout << YELLOW << "Jadwal dengan kode " << temp->kodePenerbangan 
         << " berhasil dihapus." << RESET << endl;
    delete temp;
}

// hapus jadwal terakhir
void deleteLast() {
    if (head == nullptr) {
        cout << RED << ">> Belum ada jadwal penerbangan <<" << RESET << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << YELLOW << "Jadwal dengan kode " << head->kodePenerbangan 
             << " berhasil dihapus." << RESET << endl;
        delete head;
        head = nullptr;
        return;
    }
    Flight* temp = head;
    while (temp->next->next != nullptr) temp = temp->next;
    cout << YELLOW << "Jadwal dengan kode " << temp->next->kodePenerbangan 
         << " berhasil dihapus." << RESET << endl;
    delete temp->next;
    temp->next = nullptr;
}

// hapus jadwal di posisi tertentu
void deleteSpecific() {
    if (head == nullptr) {
        cout << RED << ">> Belum ada jadwal penerbangan <<" << RESET << endl;
        return;
    }

    // menampilkan semua data
    display();

    int pos;
    cout << "\nMasukkan posisi yang ingin dihapus: ";
    cin >> pos;
    cin.ignore();

    if (pos <= 1) {
        deleteFirst();
        return;
    }

    Flight* temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < pos - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp->next == nullptr) {
        cout << RED << ">> Posisi tidak valid <<" << RESET << endl;
    } else {
        Flight* hapus = temp->next;

        // hapus node
        temp->next = hapus->next;
        cout << YELLOW << "Jadwal dengan kode " << hapus->kodePenerbangan
             << " berhasil dihapus." << RESET << endl;
        delete hapus;
    }
}

// update status
void updateStatus() {
    if (head == nullptr) {
        cout << RED << ">> Belum ada jadwal penerbangan <<" << RESET << endl;
        return;
    }

    // menampilkan semua data
    display();

    string kode;
    cout << endl;
    cout << "Masukkan Kode Penerbangan yang ingin diperbarui: ";
    getline(cin, kode);

    Flight* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status lama: " << temp->status << endl;
            cout << "Masukkan Status Baru: ";
            string newStatus;
            getline(cin, newStatus);
            temp->status = newStatus;
            cout << "Status penerbangan berhasil diperbarui!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << RED << ">> Jadwal dengan kode " << kode << " tidak ditemukan <<" << RESET << endl;
}

// tampilkan semua jadwal
void display() {
    if (head == nullptr) {
        cout << RED << ">> Belum ada jadwal penerbangan <<" << RESET << endl;
        return;
    }
    cout << "\n" << CYAN << "=== Daftar Jadwal Penerbangan ===" << RESET << endl;
    Flight* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->kodePenerbangan 
             << " | Tujuan: " << temp->tujuan 
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

// program utama
int main() {
    int pilihan;
    do {
        cout << CYAN << "\n====================================================" << RESET << endl;
        cout << CYAN << "|" << RESET << "            Sistem Jadwal Penerbangan             " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "          [" << namaUser << " - " << nimUser << "]           " << CYAN "|" << RESET << endl;
        cout << CYAN << "====================================================" << RESET << endl;
        cout << CYAN << "|" << RESET << "         1. Tambah Jadwal Penerbangan             " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         2. Sisipkan Jadwal di Posisi ke-7        " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         3. Hapus Jadwal Pertama                  " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         4. Hapus Jadwal Terakhir                 " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         5. Hapus Jadwal di Posisi Tertentu       " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         6. Update Status Penerbangan             " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         7. Tampilkan Semua Jadwal                " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         0. Keluar                                " << CYAN << "|" << RESET << endl;
        cout << CYAN << "====================================================" << RESET << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: addLast(); break;
            case 2: addSpecific(); break;
            case 3: deleteFirst(); break;
            case 4: deleteLast(); break;
            case 5: deleteSpecific(); break;
            case 6: updateStatus(); break;
            case 7: display(); break;
            case 0: cout << GREEN << "Terima kasih telah menggunakan program ini!" << RESET << endl; break;
            default: cout << RED << ">> Pilihan tidak valid, coba lagi. <<" << RESET << endl;
        }
    } while (pilihan != 0);

    return 0;
}
