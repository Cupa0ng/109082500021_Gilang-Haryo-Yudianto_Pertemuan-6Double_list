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
 
    if (findElm(L, data.kodeBuku) == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "kode buku sudah terdaftar" << endl << endl;
    }
}

int main() {
    List L;
    CreateList(L);
 
    inputData(L);  
    inputData(L);  
    inputData(L);  
    inputData(L);  

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}