#include "matkull.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void createlist_matkul(list_matkul &L)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    first_matkul(L)= NULL;
}

address_matkul  alokasi_matkul(matkul x)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul P= new elmlist_matkul;
    info_matkul(P) = x;
    next_matkul(P) = NULL;
    return P;
}
void dealokasi_matkul(address_matkul &P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    delete P;
}

void insertFirst_matkul(list_matkul &L, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if (first_matkul(L) == NULL)
    {
        first_matkul(L) = P;
    }
    else
    {
        next_matkul(P) = first_matkul(L);
        first_matkul(L) = P;
    }
}

void insertLast_matkul(list_matkul &L,address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul Q;
    if (first_matkul(L)==NULL)
    {
        insertFirst_matkul(L,P);
    }
    else
    {
        Q = first_matkul(L);
        while(next_matkul(Q)!= NULL)
        {
            Q= next_matkul(Q);
        }
        next_matkul(Q) = P;
    }
}


void insertAfter_matkul(list_matkul &L,address_matkul Prec, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if ((first_matkul(L)!=NULL) && (Prec != NULL))
    {
        next_matkul(P) = next_matkul(Prec);
        next_matkul(Prec) = P;
    }
}

void deleteFirst_matkul(list_matkul &L, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if (first_matkul(L)==NULL)
    {
        cout<<"Tidak ada Data"<<endl;

    }
    else if (first_matkul(L) != NULL)
    {
        P = first_matkul(L);
        first_matkul(L) = next_matkul(P);
        next_matkul(P) = NULL;
    }
}

void deleteLast_matkul(list_matkul &L, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul Q;
    if(first_matkul(L)!=NULL)
    {
        Q = first_matkul(L);
        if(next_matkul(Q)==NULL)
        {
            deleteFirst_matkul(L,P);
        }
        else
        {
            while(next_matkul(next_matkul(Q))!=NULL)
            {
                Q= next_matkul(Q);
            }
            P = next_matkul(Q);
            next_matkul(Q) = NULL;
            next_matkul(P) = NULL;
        }

    }
}
void deleteAfter_matkul(list_matkul &L, address_matkul Prec, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if((first_matkul(L) != NULL)&& (Prec != NULL))
    {
        P = next_matkul(Prec);
        next_matkul(Prec) = next_matkul(P);
        next_matkul(P) = NULL;
    }
}

address_matkul findElm_matkul(list_matkul &L,string  x)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul P = first_matkul(L);
    while (P != NULL && info_matkul(P).nama!= x)
    {
        P = next_matkul(P);
    }
    if (P == NULL)
    {
        return NULL;
        cout << endl;

    }
    if (info_matkul(P).nama == x){
        return P;
        cout << endl;
    }
}

void Printinfo_matkul(list_matkul L)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul P;
    if(first_matkul(L)==NULL)
    {
        cout << "********************" << endl;
        cout << "  Daftar Mata Kuliah" << endl;
        cout << "********************" << endl;
        cout<<endl;
        cout<<"Belum Ada Matakuliah Baru yang Terdaftar"<<endl;
    }
    else
    {
        cout << "*******************" << endl;
        cout << " Daftar Mata Kuliah" << endl;
        cout << "*******************" << endl;
        cout << "kode \t| nama \t|  "<< endl;
        cout << "********************" << endl;
        P=first_matkul(L);
        while(next_matkul(P)!=NULL)
        {
            cout<<info_matkul(P).kode<<"\t| "<<info_matkul(P).nama<<"\t| ";
            cout<<endl;
            P=next_matkul(P);
        }
        cout<<info_matkul(P).kode<<"\t| "<<info_matkul(P).nama<<"\t| ";
        cout<<"\n\n";
    }
}

void deleteSearch_matkul(list_matkul &L, string x)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
address_matkul y = findElm_matkul(L,x);
address_matkul P = first_matkul(L);
if ( y != NULL ){
    if ( next_matkul(first_matkul(L)) == NULL ){
        first_matkul(L) = NULL;
    }else{
        if ( info_matkul(P).nama == x ){
            first_matkul(L) = next_matkul(P);
            next_matkul(P) = NULL;
        }else{
        while ( info_matkul(next_matkul(P)).nama != x ){
            P = next_matkul(P);
        }
        deleteAfter_matkul(L,P,next_matkul(P));
        }
    }
    }else{
        cout << "Tidak Ada";
    }
}
void insertAndSort(list_matkul &L,address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
 address_matkul Prec = first_matkul(L);
 address_matkul Q = first_matkul(L);
 if (first_matkul(L)== NULL){
    insertFirst_matkul(L,P);
 }
 else if (first_matkul(L) != NULL){
    if (info_matkul(P).kode <= info_matkul(first_matkul(L)).kode){
        insertFirst_matkul(L,P);
    }
    else{
        if (next_matkul(Q)==NULL){
            insertLast_matkul(L,P);
        }
        else{
            while ((next_matkul(Q)!=NULL)&& info_matkul(P).kode>info_matkul(next_matkul(Q)).kode){
                Q=next_matkul(Q);
            }
            insertAfter_matkul(L,Q,P);
        }
    }

 }
}



void data_matkul(list_matkul &L)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    matkul mat;
    address_matkul P;

    mat.kode = "C11";
    mat.nama = "Kalkulus";
    P = alokasi_matkul(mat);
    insertFirst_matkul(L,P);

    mat.kode = "C12";
    mat.nama = "Fisika";
    P = alokasi_matkul(mat);
    insertLast_matkul(L,P);

    mat.kode = "C13";
    mat.nama = "Mavek";
    P = alokasi_matkul(mat);
    insertLast_matkul(L,P);

    mat.kode ="C14";
    mat.nama = "Struktur Data";
    P = alokasi_matkul(mat);
    insertLast_matkul(L,P);

    mat.kode = "C15";
    mat.nama = "Agama";
    P = alokasi_matkul(mat);
    insertLast_matkul(L,P);

    mat.kode = "C16";
    mat.nama = "Logmath";
    P = alokasi_matkul(mat);
    insertLast_matkul(L,P);

}
