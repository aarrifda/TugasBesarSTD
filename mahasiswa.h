#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info_maha(P) (P)->info_maha
#define next_maha(P) (P)->next_maha
#define prev_maha(P) (P)->prev_maha
#define first_maha(L) (L).first_maha
#define last_maha(L) (L).last_maha
#define matkul(P) (P)->matkul
#define kemaha(P) (P)->kemaha

struct maha{
    string nama;
    string id;
};
typedef maha infotype;
typedef struct elmList_maha *address_maha;

struct elmList_maha{
    maha info_maha;
    address_maha next_maha;
    address_maha prev_maha;
};

struct List_maha{
    address_maha first_maha;
};

void createList_maha(List_maha &L);
address_maha alokasi_maha(maha x);
void dealokasi_maha(address_maha &P);
void insertFirst_maha(List_maha &L, address_maha P);
void insertLast_maha(List_maha &L, address_maha P);
address_maha findElm_maha(List_maha L, string x);
void deleteFirst_maha(List_maha &L, address_maha &P);
void deleteLast_maha(List_maha &L, address_maha &P);
void printInfo_maha(List_maha L);
void insertAfter_maha(address_maha Prec, address_maha P);
void deleteAfter_maha(List_maha &L, address_maha Prec, address_maha &P);
void editInfo_maha(List_maha L, address_maha &P);
maha input_maha();
void deleteSearch_maha(List_maha &LM, address_maha &P);
void data_maha(List_maha &L);




#endif // MAHASISWA_H_INCLUDED
