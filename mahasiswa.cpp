#include "mahasiswa.h"

void createList_maha(List_maha &L)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    first_maha(L)=NULL;
}

address_maha alokasi_maha(maha x)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha P = new elmList_maha;
    info_maha(P)=x;
    next_maha(P)=NULL;
    prev_maha(P)=NULL;
    return P;
}

void dealokasi_maha(address_maha &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    delete P;
}

void insertFirst_maha(List_maha &L, address_maha P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha Q;
    if(first_maha(L)==NULL){
        first_maha(L)=P;
        next_maha(P)=first_maha(L);
    }
    else{
        Q=first_maha(L);
        while(next_maha(Q)!=first_maha(L)){
            Q=next_maha(Q);
        }
        next_maha(P)=first_maha(L);
        prev_maha(P)=Q;
        next_maha(Q)=P;
        prev_maha(first_maha(L))=P;
        first_maha(L)=P;
    }
}

void insertLast_maha(List_maha &L, address_maha P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha Q;
    if(first_maha(L)==NULL){
        first_maha(L)=P;
        next_maha(P)=first_maha(L);
    }
    else{
        Q=first_maha(L);
        while(next_maha(Q)!=first_maha(L)){
            Q=next_maha(Q);
        }
        next_maha(Q)=P;
        next_maha(P)=first_maha(L);
        prev_maha(P)=Q;
        prev_maha(first_maha(L))=P;
    }
}

address_maha findElm_maha(List_maha L, string x)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha P = NULL;
    if(first_maha(L) != NULL){
        P = first_maha(L);
        do{
            if(info_maha(P).id == x){
                return P;
            }
            P = next_maha(P);
        }while(P!=first_maha(L));
    }
    return NULL;
}

void deleteFirst_maha(List_maha &L, address_maha &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha Q;
    if(first_maha(L)!=NULL){
        Q=first_maha(L);
        while(next_maha(Q)!=first_maha(L)){
            Q=next_maha(Q);
        }
        P=first_maha(L);
        first_maha(L)=next_maha(first_maha(L));
        next_maha(P)=NULL;
        prev_maha(first_maha(L))=Q;
        next_maha(Q)=first_maha(L);
    }
}

void deleteLast_maba(List_maha &L, address_maha &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha Prec;
    if(first_maha(L)!=NULL){
        P=first_maha(L);
        do{
            Prec=P;
            P=next_maha(P);
        }while(next_maha(P)!=first_maha(L));
        next_maha(Prec)=first_maha(L);
        prev_maha(first_maha(L))=Prec;
    }
}

void printInfo_maha(List_maha L)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha P;
    if(first_maha(L)==NULL){
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Matakuliah Mahasiswa Jurusan Informatika" << endl;
        cout << "========================================================================================================================" << endl;
        cout<<endl;
        cout<<"\t\t\t\t\tBelum Ada Mahasiswa Baru yang Terdaftar\n"<<endl;
    }
    else{
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Matakuliah Mahasiswa Jurusan Informatika" << endl;
        cout << "========================================================================================================================" << endl;
        cout << "ID \t| Nama \t\t| NIM" << endl;
        cout << "========================================================================================================================" << endl;
        P=first_maha(L);
        do{
            cout<<info_maha(P).nama<<" - ";
            cout<<info_maha(P).id<<" - ";
            cout<<endl;
            P=next_maha(P);

        }while(P!=first_maha(L));
        cout<<endl;
    }
}

void insertAfter_maha(address_maha Prec, address_maha P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
        next_maha(P)=next_maha(Prec);
        prev_maha(next_maha(Prec))=P;
        next_maha(Prec)=P;
        prev_maha(P)=Prec;
}

void deleteAfter_maha(List_maha &L, address_maha Prec, address_maha &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
        if(first_maha(L)!=NULL){
            next_maha(Prec)=next_maha(P);
            prev_maha(next_maha(P))=Prec;
            next_maha(P)=NULL;
            prev_maha(P)=NULL;
        }
}

void deleteSearch_maha(List_maha &LM, address_maha &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_maha Q, Prec;
    Q=first_maha(LM);
    do{
        Q=next_maha(Q);
    }while (next_maha(Q)!=first_maha(LM));
    if(P!=NULL){
        if(P==first_maha(LM)){
            deleteFirst_maha(LM, P);
        }else if(P==Q){
            deleteLast_maba(LM, P);
        }else{
            Prec = prev_maha(P);
            deleteAfter_maha(LM, Prec, P);
        }
    }
}


maha input_maha()
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    maha x;
    cin.ignore();
    cout<<"Nama\t: ";
    getline(cin,x.nama);
    cout<<"NIM\t: ";
    cin>>x.id;
    return x;
}

void data_maha(List_maha &L)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    maha mh;
    address_maha P;

    mh.nama = "Irbah Salsabila";
    mh.id = "1301174021";
    P = alokasi_maha(mh);
    insertFirst_maha(L, P);

    mh.nama = "Aanisah Rifda";
    mh.id = "1301174057";
    P = alokasi_maha(mh);
    insertFirst_maha(L, P);

    mh.nama="aa";
    mh.id = "1";
    P = alokasi_maha(mh);
    insertFirst_maha(L, P);
}
