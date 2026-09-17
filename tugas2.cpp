#include <iostream>
using namespace std;

struct Node {
    float nilai;
    Node* next;
};

Node* head = nullptr;

void tambahdepan(float nilai) {
    Node* baru = new Node();
    baru->nilai = nilai;
    baru->next = head;
    head = baru;
}

void tambahbelakang(float nilai) {
    Node* baru = new Node();
    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* bantu = head;
    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

bool tambahtengah(float nilai, int indeks) {
    if (indeks < 0) {
        return false;
    }

    if (indeks == 0) {
        tambahdepan(nilai);
        return true;
    }

    Node* bantu = head;
    for (int i = 0; i < indeks - 1; i++) {
        if (bantu == nullptr) {
            return false;
        }
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        return false;
    }

    Node* baru = new Node();
    baru->nilai = nilai;
    baru->next = bantu->next;
    bantu->next = baru;
    return true;
}

bool hapusNilai(float nilai) {
    if (head == nullptr) {
        return false; 
    }

    if (head->nilai == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* sebelum = head;
    Node* sekarang = head->next;

    while (sekarang != nullptr) {
        if (sekarang->nilai == nilai) {
            sebelum->next = sekarang->next;
            delete sekarang;
            return true;
        }
        sebelum = sekarang;
        sekarang = sekarang->next;
    }

    return false; 
}

void tampilkan() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* bantu = head;
    cout << "Isi list: ";
    while (bantu != nullptr) {
        cout << bantu->nilai;
        if (bantu->next != nullptr) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

void hapusSemua() {
    Node* bantu = head;
    while (bantu != nullptr) {
        Node* temp = bantu;
        bantu = bantu->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    cout << "=== Program Linked List Nilai Mahasiswa ===" << endl << endl;

    float dataAwal[10] = {80, 75, 90, 65, 70, 88, 92, 60, 78, 85};

    for (int i = 0; i < 10; i++) {
        tambahbelakang(dataAwal[i]);
    }

    cout << " Data awal (10 nilai mahasiswa) " << endl;
    tampilkan();

    cout << endl;

    tambahdepan(90);
    cout << "Tambah depan: 90 => ";
    tampilkan();

    if (tambahtengah(0, 4))
        cout << "Tambah di indeks ke-4: 0 => ";
    else
        cout << "Gagal menambah di indeks ke-4 => ";
    tampilkan();

    tambahbelakang(70);
    cout << "Tambah belakang: 70 => ";
    tampilkan();

    hapusSemua(); 
    return 0;
}
