#ifndef MATKULL_H_INCLUDED
#define MATKULL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define next_matkul(P) (P)->next_matkul
#define first_matkul(L) (L).first_matkul
#define info_matkul(P) P->info_matkul
#define tomatkul(P) (P)->tomatkul

struct matkul{
    string kode;
    string nama;
};

typedef struct elmlist_matkul *address_matkul;
struct elmlist_matkul{
    matkul info_matkul;
    address_matkul next_matkul;
};

struct list_matkul{
    address_matkul first_matkul;
};

void createlist_matkul(list_matkul &L);
address_matkul alokasi_matkul(matkul x);
void dealokasi_matkul(address_matkul &P);
void insertFirst_matkul(list_matkul &L,address_matkul P);
void insertLast_matkul(list_matkul &L, address_matkul P);
void insertAfter_matkul(list_matkul &L, address_matkul Prec, address_matkul P);
address_matkul findElm_matkul(list_matkul &L, string x);
void deleteFirst_matkul(list_matkul &L, address_matkul P);
void deleteLast_matkul(list_matkul &L, address_matkul P);
void deleteAfter_matkul(list_matkul &L, address_matkul Prec, address_matkul P);
void Printinfo_matkul(list_matkul L);
void deleteSearch_matkul(list_matkul &L, string x);
void data_matkul(list_matkul &L);
address_matkul input_matkul();
void insertAndSort(list_matkul &L,address_matkul P);

#endif // MATKULL_H_INCLUDED
