#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "kode buku : " << P->info.kodeBuku << std::endl;
        std::cout << "judul     : " << P->info.judul << std::endl;
        std::cout << "tahun     : " << P->info.thnTerbit << std::endl;
        std::cout << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}

address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}