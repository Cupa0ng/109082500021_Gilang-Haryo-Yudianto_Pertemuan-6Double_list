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
 
    infotype cariData;
    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> cariData.kodeBuku;
    cout << endl;

    P = findElm(L, cariData);
    if (P != Nil) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << cariData.kodeBuku << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}