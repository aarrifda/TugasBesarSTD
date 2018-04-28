#include "relasi.h"

using namespace std;

int main()
{
    List_maha LM;
    List_relasi LR;
    list_matkul LA;
    createList_maha(LM);
    createList_relasi(LR);
    createlist_matkul(LA);
    data_maha(LM);
    data_matkul(LA);
    data_relasi(LR,LM,LA);
    menu(LM, LR,LA);
    return 0;
}




