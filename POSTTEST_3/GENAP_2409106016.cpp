#include <iostream>
#include <string>
using namespace std;

// deklarasi fungsi
void addLast();
void addSpecific();
void deleteFirst();
void deleteLast();
void deleteSpecific();
void updateStatus();
void display();          // menampilkan data dari depan (head -> tail)
void displayReverse();   // menampilkan data dari belakang (tail -> head)
void cariDetail();

// untuk mengubah warna pada teks
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

// struct node
struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
    Flight* prev;
};

// variabel global
Flight* head = nullptr;
Flight* tail = nullptr;
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

// menambah data di akhir
void addLast() {
    Flight* newNode = new Flight;
    newNode->kodePenerbangan = buatKode();
    cout << "Masukkan Tujuan: "; getline(cin, newNode->tujuan);
    cout << "Masukkan Status (ontime/delayed/boarding): "; getline(cin, newNode->status);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << GREEN << "Jadwal ditambahkan dengan kode: " 
         << newNode->kodePenerbangan << RESET << endl;
}

// menambah data di posisi ke-7
void addSpecific() {
    int pos = 7;
    if (head == nullptr) {
        cout << RED << ">> List masih kosong <<" << RESET << endl;
        return;
    }
    Flight* newNode = new Flight;
    newNode->kodePenerbangan = buatKode();
    cout << "Masukkan Tujuan: "; getline(cin, newNode->tujuan);
    cout << "Masukkan Status (ontime/delayed/boarding): "; getline(cin, newNode->status);

    Flight* temp = head;
    int idx = 1;
    while (temp != nullptr && idx < pos - 1) {
        temp = temp->next;
        idx++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << RED << ">> Posisi tidak valid <<" << RESET << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    cout << GREEN << "Jadwal disisipkan di posisi ke-7 dengan kode: "
         << newNode->kodePenerbangan << RESET << endl;
}

// menghapus data pertama
void deleteFirst() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    
    display();
    Flight* del = head;
    cout << YELLOW << "Menghapus Jadwal dengan Kode: " << del->kodePenerbangan << RESET << endl;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete del;    
}

// menghapus data terakhir
void deleteLast() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    \
    display();
    Flight* del = tail;
    cout << YELLOW << "Menghapus Jadwal dengan Kode: " << del->kodePenerbangan << RESET << endl;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete del;
}

// menghapus data pada posisi tertentu
void deleteSpecific() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    
    display();
    int pos;
    cout << "Masukkan posisi yang dihapus: ";
    cin >> pos; cin.ignore();

    if (pos == 1) {
        deleteFirst();
        return;
    }

    Flight* temp = head;
    int idx = 1;
    while (temp != nullptr && idx < pos) {
        temp = temp->next;
        idx++;
    }
    if (temp == nullptr) {
        cout << RED << ">> Posisi tidak valid <<" << RESET << endl;
        return;
    }
    cout << YELLOW << "Menghapus Jadwal dengan Kode: " << temp->kodePenerbangan << RESET << endl;
    if (temp == tail) {
        deleteLast();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

// memperbarui data
void updateStatus() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }

    display();
    string kode;
    cout << "Masukkan kode penerbangan: ";
    getline(cin, kode);

    Flight* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status lama: " << temp->status << endl;
            cout << "Masukkan Status Baru: ";
            string s; getline(cin, s);
            temp->status = s;
            cout << GREEN << "Status diperbarui!" << RESET << endl;
            return;
        }
        temp = temp->next;
    }
    cout << RED << ">> Data tidak ditemukan <<" << RESET << endl;
}

// menampilkan semua data dari depan
void display() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    cout << endl;
    cout << CYAN << "=== Jadwal ditampilkan dari depan ===" << RESET << endl;
    Flight* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->kodePenerbangan
             << " | " << temp->tujuan
             << " | " << temp->status << endl;
        temp = temp->next;
    }
}

// menampilkan semua data dari belakang
void displayReverse() {
    if (tail == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    
    cout << endl;
    cout << CYAN << "=== Jadwal ditampilkan dari belakang ===" << RESET << endl;
    Flight* temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->kodePenerbangan
             << " | " << temp->tujuan
             << " | " << temp->status << endl;
        temp = temp->prev;
    }
}

// mencari detail penerbangan
void cariDetail() {
    if (head == nullptr) {
        cout << RED << ">> List kosong <<" << RESET << endl;
        return;
    }
    string key;
    cout << "Masukkan kode atau tujuan penerbangan: ";
    getline(cin, key);

    Flight* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == key || temp->tujuan == key) {
            cout << endl;
            cout << CYAN << "=== Detail Penerbangan ===" << RESET << endl;
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            return;
        }
        temp = temp->next;
    }
    cout << RED << ">> Data tidak ditemukan <<" << RESET << endl;
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
        cout << CYAN << "|" << RESET << "         7. Tampilkan Jadwal dari Depan           " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         8. Tampilkan Jadwal dari Belakang        " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         9. Cari Detail Penerbangan               " << CYAN << "|" << RESET << endl;
        cout << CYAN << "|" << RESET << "         0. Keluar                                " << CYAN << "|" << RESET << endl;
        cout << CYAN << "====================================================" << RESET << endl;
        cout << "Pilih menu: "; 
        cin >> pilihan; cin.ignore();       

        switch (pilihan) {
            case 1: addLast(); break;
            case 2: addSpecific(); break;
            case 3: deleteFirst(); break;
            case 4: deleteLast(); break;
            case 5: deleteSpecific(); break;
            case 6: updateStatus(); break;
            case 7: display(); break;
            case 8: displayReverse(); break;
            case 9: cariDetail(); break;
            case 0: cout << GREEN << "Terima kasih!" << RESET << endl; break;
            default: cout << RED << "Pilihan tidak valid!" << RESET << endl;
        }
    } while (pilihan != 0);

    return 0;
}
