#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nomorPlat;
    string jenis;
    string merk;
    string model;
    string namaPemilik;
    int tahunProduksi;
};

const int MAX_KENDARAAN = 100;
Kendaraan database[MAX_KENDARAAN];
int jumlahKendaraan = 0;

void tambahDataKendaraan() {
    if (jumlahKendaraan < MAX_KENDARAAN) {
        Kendaraan k;
        cout << "Nomor Plat: ";
        cin >> k.nomorPlat;
        cout << "Jenis Kendaraan (mobil/motor): ";
        cin >> k.jenis;
        cout << "Merk Kendaraan (contoh: Toyota, Honda): ";
        cin >> k.merk;
        cout << "Model Kendaraan (contoh: Avanza, Civic): ";
        cin >> k.model;
        cout << "Nama Pemilik: ";
        cin >> k.namaPemilik;
        cout << "Tahun Produksi: ";
        cin >> k.tahunProduksi;
        database[jumlahKendaraan++] = k;
    } else {
        cout << "Database penuh!" << endl;
    }
}

void tampilkanDataKendaraan() {
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "Nomor Plat: " << database[i].nomorPlat << endl;
        cout << "Jenis: " << database[i].jenis << endl;
        cout << "Merk: " << database[i].merk << endl;
        cout << "Model: " << database[i].model << endl;
        cout << "Nama Pemilik: " << database[i].namaPemilik << endl;
        cout << "Tahun Produksi: " << database[i].tahunProduksi << endl;
        cout << "-----------------------------" << endl;
    }
}

void bubbleSort() {
    for (int i = 0; i < jumlahKendaraan - 1; i++) {
        for (int j = 0; j < jumlahKendaraan - i - 1; j++) {
            if (database[j].tahunProduksi > database[j + 1].tahunProduksi) {
                swap(database[j], database[j + 1]);
            }
        }
    }
}

int partition(int low, int high) {
    int pivot = database[high].tahunProduksi;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (database[j].tahunProduksi < pivot) {
            i++;
            swap(database[i], database[j]);
        }
    }
    swap(database[i + 1], database[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void sequentialSearch(string key) {
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (database[i].namaPemilik == key || database[i].jenis == key) {
            cout << "Data ditemukan:" << endl;
            cout << "Nomor Plat: " << database[i].nomorPlat << endl;
            cout << "Jenis: " << database[i].jenis << endl;
            cout << "Merk: " << database[i].merk << endl;
            cout << "Model: " << database[i].model << endl;
            cout << "Nama Pemilik: " << database[i].namaPemilik << endl;
            cout << "Tahun Produksi: " << database[i].tahunProduksi << endl;
            cout << "-----------------------------" << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    string key;
    do {
        cout << "=== Menu ===" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Tampilkan Seluruh Data Kendaraan" << endl;
        cout << "3. Urutkan Data Kendaraan (Bubble Sort)" << endl;
        cout << "4. Urutkan Data Kendaraan (Quick Sort)" << endl;
        cout << "5. Cari Data Kendaraan (Sequential Search)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataKendaraan();
                break;
            case 2:
                tampilkanDataKendaraan();
                break;
            case 3:
                bubbleSort();
                tampilkanDataKendaraan();
                cout << "Data telah diurutkan berdasarkan tahun produksi (Bubble Sort)." << endl;
                break;
            case 4:
                quickSort(0, jumlahKendaraan - 1);
                tampilkanDataKendaraan();
                cout << "Data telah diurutkan berdasarkan tahun produksi (Quick Sort)." << endl;
                break;
            case 5:
                cout << "Masukkan nama pemilik atau jenis kendaraan: ";
                cin >> key;
                sequentialSearch(key);
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 6);

    return 0;
}