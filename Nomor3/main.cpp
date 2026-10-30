#include <iostream>
#include "Buku.h"

using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan kode buku: "; cin >> data.kodeBuku;
    cout << "masukkan judul buku: "; cin >> data.judul;
    cout << "masukkan tahun terbit: "; cin >> data.thnTerbit;
    cout << endl;

    if (findElm(L, data) == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "kode buku sudah terdaftar" << endl << endl;
    }
}

int main() {
    List L;
    CreateList(L);
    address P;
 
    inputData(L);  
    inputData(L);  
    inputData(L); 
 
    string kodeHapus;
    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> kodeHapus;
    cout << endl;

    infotype cariHapus;
    cariHapus.kodeBuku = kodeHapus;
    P = findElm(L, cariHapus);

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << kodeHapus << " berhasil dihapus." << endl << endl;
    } else {
        cout << "Data dengan kode buku " << kodeHapus << " tidak ditemukan." << endl << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}