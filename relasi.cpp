#include "relasi.h"
#include "matkull.h"
#include "mahasiswa.h"


void createList_relasi(List_relasi &L)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    first_relasi(L)=NULL;
    last_relasi(L)=NULL;
    }

address_relasi alokasi_relasi(address_maha LM, address_matkul LA)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_relasi P = new elmList_relasi;
    tomaha(P)= LM;
    tomatkul(P) = LA;
    next_relasi(P)= NULL;
    prev_relasi(P) = NULL;
    return P;
}
void dealokasi_relasi(address_relasi &P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    delete P;
}

void insertFirst_relasi(List_relasi &L, address_relasi &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    if(first_relasi(L) == NULL){

        first_relasi(L) = P;
        last_relasi(L) = P;
        next_relasi(first_relasi(L)) = first_relasi(L);
        prev_relasi(first_relasi(L)) = first_relasi(L);
    }
    else{
    	//address_relasi Q = prev_relasi(first_relasi(L));
        next_relasi(P) = first_relasi(L);
        prev_relasi(P) = last_relasi(L);
        prev_relasi(first_relasi(L)) = P;
        next_relasi(last_relasi(L)) = P;
        first_relasi(L) = P;
    }
}

void insertLast_relasi(List_relasi &L, address_relasi P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if(first_relasi(L) == NULL){
        first_relasi(L) = P;
        next_relasi(first_relasi(L)) = first_relasi(L);
        prev_relasi(first_relasi(L)) = first_relasi(L);
    }
    else{
        address_relasi Q = prev_relasi(first_relasi(L));
        prev_relasi(P) = Q;
        prev_relasi(first_relasi(L)) = P;
        next_relasi(P) = first_relasi(L);
        next_relasi(Q) = P;
    }
}
void deleteFirst_relasi(List_relasi &L, address_relasi &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    if(first_relasi(L)!=NULL){
        P=first_relasi(L);
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
    		first_relasi(L)=NULL;
		}
		else{
            //address_relasi Q=prev_relasi(first_relasi(L));
	        first_relasi(L)=next_relasi(P);
	        prev_relasi(first_relasi(L))=last_relasi(L);
	        next_relasi(last_relasi(L))=first_relasi(L);
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
        }
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}
void deleteLast_relasi(List_relasi &L, address_relasi &P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    if(first_relasi(L)!=NULL){
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
            first_relasi(L) = NULL;
            last_relasi(L) = NULL;
		}else{
            last_relasi(L) = prev_relasi(P);
	        next_relasi(last_relasi(L))=first_relasi(L);
	        prev_relasi(first_relasi(L))=last_relasi(L);
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
    	}
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}

void deleteAfter_relasi (List_relasi &L,address_relasi Prec, address_relasi &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    if (first_relasi(L) != NULL) {
            next_relasi(Prec)=next_relasi(P);
            prev_relasi(next_relasi(P))=Prec;
            next_relasi(P)=NULL;
            prev_relasi(P)=NULL;
    }
}


void insertAfter_relasi (List_relasi &L, address_relasi Prec, address_relasi P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
 {
        next_relasi(P)=next_relasi(Prec);
        prev_relasi(next_relasi(Prec))=P;
        next_relasi(Prec)=P;
        prev_relasi(P)=Prec;
}

void input_relasi(list_matkul LA, List_maha LM, List_relasi &LR)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    string cariMaha;
    string cariMatkul;
    address_maha PM;
    address_matkul PA;

    cin.ignore();
    cout<<"ID Mahasiswa: ";
    getline(cin, cariMaha);

    cout<<"Nama Mata Kuliah: ";
    getline(cin, cariMatkul);

    PM = findElm_maha(LM, cariMaha);
    PA = findElm_matkul(LA, cariMatkul);
    if(PM!=NULL && PA!=NULL){
        address_relasi PW = search_relasi(LR,PM,PA);
        if (PW == NULL){
             address_relasi PR;
             PR = alokasi_relasi(PM, PA);
             insertFirst_relasi(LR, PR);
        }
        else{
            cout <<" Data Duplikat "<<endl;
        }
    }

}

void print_relasi(List_relasi L)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_relasi PR;
    if(first_relasi(L) != NULL){
        PR = first_relasi(L);
        do{
            cout<<info_maha(tomaha(PR)).nama<<" - "<<info_matkul(tomatkul(PR)).nama<<endl;
            PR = next_relasi(PR);
        }while(PR!=first_relasi(L));
    }
}

address_relasi search_relasi(List_relasi L, address_maha PM, address_matkul PA)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_relasi P = first_relasi(L);
    if (P!= NULL){
        while (next_relasi(P) != first_relasi(L) && (PM != tomaha(P)) && (PA != tomatkul(P)))
        {
            P = next_relasi(P);
        }
        if (PM == tomaha(P) && PA == tomatkul(P)){
            return P;
        }else{
            return NULL;
        }
    }
}
address_relasi searchrelasi_matkul(List_relasi L, address_matkul PA)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
 {
    address_relasi P = first_relasi(L);
    if (P!= NULL){
        while (next_relasi(P) != first_relasi(L) && (PA != tomatkul(P)))
        {
            P = next_relasi(P);
        }
        if (PA == tomatkul(P)){
            return P;
        }else{
            return NULL;
        }
    }
}
void deleteSearch_relasi(List_relasi &L, address_relasi &P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_relasi Q, Prec;
    Q=first_relasi(L);
    do{
        Q=next_relasi(Q);
    }while (next_relasi(Q)!=first_relasi(L));
    if(P!=NULL){
        if(P==first_relasi(L)){
            cout<<"Masuk First Relasi"<<endl;
            system("pause");
            deleteFirst_relasi(L, P);
        }else if(P==Q){
            cout<<"Masuk Last Relasi"<<endl;
            system("pause");
            deleteLast_relasi(L, P);
        }else{
            cout<<"Masuk After Relasi"<<endl;
            system("pause");
            Prec = prev_relasi(P);
            deleteAfter_relasi(L, Prec, P);
        }
        cout<<"Berhasil"<<endl;
        system("Pause");
    }
}


void delete_maha (List_maha &LM, List_relasi &LR, address_maha P)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */
{
    address_relasi PR, Prec, R;
    if (first_relasi(LR) != NULL){
        PR = first_relasi(LR);
        do {
            if (tomaha(PR) == P) {
                R = PR;
                if (PR == first_relasi(LR)) {
                    PR = next_relasi(PR);
                    deleteFirst_relasi(LR,R);
                }
                else if (PR == last_relasi(LR)) {
                    PR = next_relasi(PR);
                    deleteLast_relasi(LR,R);
                }
                else {
                    Prec = prev_relasi(PR);
                    PR = next_relasi(PR);
                    deleteAfter_relasi(LR,Prec,R);
                }
            }
            else{
                PR = next_relasi(PR);
            }
        }while (PR != first_relasi(LR) && first_relasi(LR) != NULL);
    }
    deleteSearch_maha(LM, P);
}
void delete_matkul(list_matkul &LA, List_relasi &LR, address_matkul P)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_relasi Prec;
    address_relasi R;
    if (first_relasi(LR) != NULL){
        address_relasi PR = first_relasi(LR);
        do{
            if (tomatkul(PR) == P) {
                R = PR;
                if (PR == first_relasi(LR)) {
                    cout<<"Masuk First";
                    system("pause");
                    PR = next_relasi(PR);
                    deleteFirst_relasi(LR,R);
                }
                else if (PR == last_relasi(LR)) {
                    PR = next_relasi(PR);
                    deleteLast_relasi(LR,R);
                }else {
                    Prec = prev_relasi(PR);
                    PR = next_relasi(PR);
                    deleteAfter_relasi(LR,Prec,R);
                }
            }else{
                PR = next_relasi(PR);
            }
        }while(PR != first_relasi(LR) && first_relasi(LR) != NULL);
    }
    deleteSearch_matkul(LA, info_matkul(P).nama);
}



void menu(List_maha LM, List_relasi LR,list_matkul LA)
/**
    Nama : Aanisah Rifda
    Nim : 1301174057
    */

{
    int pil;
    maha x;
    matkul a;
    address_matkul PA;
    address_maha PM;
    string cari;
    address_maha b;
    address_matkul y;
    address_relasi ar;
    string nm;
    string nl;
    do{
        system("cls");
        cout<<endl;
        cout<<"Aplikasi Pemilihan Mata Kuliah"<<endl;
        cout<<endl;
        cout<<"\tParent "<<endl;
        cout<<"1.  Tambah Mahasiswa "<<endl;
        cout<<"2.  Hapus Mahasiswa "<<endl;
        cout<<"3.  Pencarian Mahasiswa "<<endl;
        cout<<"4.  Lihat Data Mahasiswa "<<endl;
        cout<<endl;
        cout<<"\tChild "<<endl;
        cout<<"5.  Tambah Mata Kuliah "<<endl;
        cout<<"6.  Hapus Mata Kuliah "<<endl;
        cout<<"7.  Pencarian Mata Kuliah "<<endl;
        cout<<"8.  Lihat Data Mata Kuliah "<<endl;
        cout<<endl;
        cout<<"\tRelation "<<endl;
        cout<<"9.  Pemilihan Mata Kuliah "<<endl;
        cout<<"10. Penghapusan Relasi "<<endl;
        cout<<"11. Lihat Data Relasi "<<endl;
        cout<<endl;
        cout<<"0.  Exit "<<endl;
        cout<<endl;
        cout<<"Masukkan Pilihan: ";
        cin>>pil;
        cout<<endl;
        switch(pil){
        case 1:
            system("cls");
            cout<<endl;
            x = input_maha();
            PM = findElm_maha(LM, x.id);
            if(PM == NULL){
                PM = alokasi_maha(x);
                insertFirst_maha(LM, PM);
            } else{
                cout<<"Data Duplikat"<<endl;
            }

            system("pause");
            break;
        case 2:
            system("cls");
            cout<<endl;
            cout<<"\tHapus Mahasiswa"<<endl;
            cout<<endl;
            x = input_maha();
            PM = findElm_maha(LM,x.id);
            if (PM != NULL){
                delete_maha(LM,LR,PM);
            }else{
                cout<<"Data Tidak Ditemukan"<<endl;
            }

            system("pause");
            break;
        case 3:
            system("cls");
            cout<<endl;
            cout<<"\tPencarian Mahasiswa"<<endl;
            cout<<endl;
            cout<<" Masukkan ID mahasiswa :";
            cin>>cari;
            b = findElm_maha(LM,cari);
            if(b != NULL){
                cout<<" Mahasiswa ditemukan"<<endl;
                cout<<"\n Data Mahasiswa"<<endl;
                cout << " Nama: "<<info_maha(b).nama<<endl;
                cout << " NIM : "<<info_maha(b).id<<endl;
            }else{
                cout<<"Mahasiswa tidak ditemukan"<<endl;
            }

            system("pause");
            break;
        case 4:
            system("cls");
            cout<<endl;
            cout<<"\tLihat Data Mahasiswa"<<endl;
            cout<<endl;

            printInfo_maha(LM);


            system("pause");
            break;
       case 5:
            system("cls");
            cout<<endl;
            cout<<"\tTambah Mata Kuliah"<<endl;
            cout<<endl;
            cin.ignore();
            cout<<"Nama : ";
            getline(cin,a.nama);
            cout<<"Kode : ";
            cin>>a.kode;
            PA = findElm_matkul(LA,a.nama);
            if (PA == NULL){
                PA = alokasi_matkul(a);
                insertAndSort(LA,PA);
            }
            else{
                cout<<"Data Duplikat"<<endl;
            }

            system("pause");
            break;
        case 6:
            system("cls");
            cout<<endl;
            cout<<"\tHapus Mata Kuliah"<<endl;
            cout<<endl;
            cout<<"Masukkan MataKuliah yang ingin dihapus :";
            cin>>cari;
            PA = findElm_matkul(LA, cari);
            if(PA!=NULL){
                delete_matkul(LA, LR, PA);
            }else{
                cout<<"Mata Kuliah tidak ditemukan"<<endl;
            }

            system("pause");
            break;
        case 7:
            system("cls");
            cout<<endl;
            cout<<"\tPencarian Mata Kuliah"<<endl;
            cout<<endl;
            cout<<" Matakuliah yang dicari :";
            cin>>cari;
            y = findElm_matkul(LA,cari);
            if(y!= NULL){
                cout << info_matkul(y).nama<<" ditemukkan" <<endl;
            }else{
                cout<<"Matkul Tidak Ditemukan"<<endl;
            }

            system("pause");
            break;
        case 8:
            system("cls");
            cout<<endl;
            cout<<"\tLihat Data Mata Kuliah"<<endl;
            cout<<endl;
            Printinfo_matkul(LA);
            system("pause");
            break;
        case 9:
            system("cls");
            cout<<endl;
            cout<<"\tPemilihan Mata Kuliah"<<endl;
            cout<<endl;

            input_relasi(LA, LM, LR);

            system("pause");
            break;
        case 10:
            system("cls");
            cout<<endl;
            cout<<"\tPenghapusan Relasi"<<endl;
            cout<<endl;
            cout<< "\nMasukkan ID Mahasiswa : ";
            cin>> nm;
            cout<< "\nMasukkan Mata Kuliah : ";
            cin >> nl;
            address_relasi PR;
            PA = findElm_matkul(LA, nl);
            PM = findElm_maha(LM, nm);
            PR = search_relasi(LR,PM,PA);
            if ( PR != NULL){
                deleteSearch_relasi(LR,PR);
            }else{
                cout<<"Relasi belum di buat";
            }

            system("pause");
            break;
        case 11:
            system("cls");
            cout<<endl;
            cout<<"\tLihat Data Relasi"<<endl;
            cout<<endl;
            print_relasi(LR);

            system("pause");
            break;
        case 0:
            cout<<"Terima Kasih Telah Menggunakan Aplikasi Pemilihan Mata Kuliah"<<endl;
            cout<<endl;
            system("pause");
            break;
        default:
            cout<<"Angka Pilihan Salah. Silakan Input Angka 1 - 11."<<endl;
            cout<<endl;
            system("pause");
            break;
        }
    }while(pil!=0);
}

void data_relasi(List_relasi &LR, List_maha LM, list_matkul LA)
/** Nama : Irbah Salsabila
    Nim : 1301174021*/
{
    address_matkul PA;
    address_maha PM;
    address_relasi PR;

    PM = findElm_maha(LM, "1301174021");
    PA = findElm_matkul(LA, "Fisika");
    PR = alokasi_relasi(PM, PA);
    insertFirst_relasi(LR,PR);

    PM = findElm_maha(LM, "1301174057");
    PA = findElm_matkul(LA, "Logmath");
    PR = alokasi_relasi(PM, PA);
    insertFirst_relasi(LR,PR);

}
