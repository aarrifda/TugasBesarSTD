#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "mahasiswa.h"
#include "matkull.h"
using namespace std;

#define tomatkul(P) (P)->tomatkul
#define tomaha(P) (P)->tomaha
#define next_relasi(P) (P)->next_relasi
#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi
#define last_relasi(L) (L).last_relasi


typedef struct elmList_relasi *address_relasi;

struct elmList_relasi{
    address_relasi next_relasi;
    address_relasi prev_relasi;
    address_maha tomaha;
    address_matkul tomatkul;
};

struct List_relasi{
    address_relasi first_relasi;
    address_relasi last_relasi;
};

void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi(address_maha LM, address_matkul LA);
void dealokasi_relasi(address_relasi &P);
void insertFirst_relasi(List_relasi &L, address_relasi &P);
void insertLast_relasi(List_relasi &L, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void insertAfter_relasi (List_relasi &L, address_relasi Prec, address_relasi P);
void deleteAfter_relasi(List_relasi &L, address_relasi Prec, address_relasi &P);
address_relasi search_relasi(List_relasi L, address_maha x, address_matkul y);
void print_relasi(List_relasi L);
void menu(List_maha LM, List_relasi LR,list_matkul LA);
void input_relasi(list_matkul LA, List_maha LM, List_relasi &LR);
void delete_maha (List_maha &LM, List_relasi &LR, address_maha P);
void delete_matkul (list_matkul &LA, List_relasi &LR, address_matkul P);
address_relasi searchrelasi_matkul(List_relasi L, address_matkul PA);
void data_relasi(List_relasi &LR, List_maha LM, list_matkul LA);
#endif // RELASI_H_INCLUDED
