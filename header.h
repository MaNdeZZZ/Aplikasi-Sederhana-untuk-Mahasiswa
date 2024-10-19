#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <cstdlib>
#include <iostream>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define nextorg(P) P->nextOrg
#define nextPres(P) P->nextPres
#define nextMhs(P) P->nextMhs

//Mahasiswa(child)
struct mahasiswa {
    string nama, prodi;
    int nim, angkatan;
};

typedef struct elmMahasiswa *adr_mhs;
typedef mahasiswa infotyope_mhs;

struct elmMahasiswa {
    infotyope_mhs info;
    adr_mhs next;
};

struct ListMhs {
    adr_mhs first, last;
};

//Prestasi(Relasi)
typedef struct elmPrestasi *adr_pres;

struct elmPrestasi{
    adr_pres next;
    adr_mhs nextMhs;
};

//Organisasi(parent)
struct organisasi {
    string namaorg, lokasi;
    int id;
};

typedef struct elmOrganisasi *adr_org;
typedef organisasi infotyope_org;

struct elmOrganisasi {
    infotyope_org info;
    adr_org next;
    adr_pres nextPres;
};

struct ListOrg {
    adr_org first, last;
};


//Organisasi(parent)
void createListParent(ListOrg &LP);
adr_org alokasiParent(infotyope_org XP);
void insertLastParent(ListOrg &LP, adr_org P);
void deleteFirstParent(ListOrg &LP, adr_org &P);
void deleteAfterParent(ListOrg &LP, adr_org &P);
void deleteLastParent(ListOrg &LP, adr_org &P);
void printInfoParent(ListOrg LP);
adr_org findElementParent(ListOrg LP, string nama);

//Organisasi(child)
void createListChild(ListMhs &LC);
adr_mhs alokasiChild(infotyope_mhs XC);
void insertLastChild(ListMhs &L, adr_mhs C);
void deleteFirstChild(ListMhs &LC, adr_mhs &C);
void deleteAfterChild(ListMhs &LC, adr_mhs &C);
void deleteLastChild(ListMhs &LC, adr_mhs &C);
void printInfoChild(ListMhs LC);
adr_mhs findElementChild(ListMhs LC, string nama);
adr_pres findChildFromParent(ListOrg LP, string namaMHS, string namaORG);

//Prestasi(relasi)
adr_pres alokasiRelasi(adr_mhs C);
void insertLastRelasi(ListOrg &LP, adr_pres R, string namaOrg);
void deleteFirstRelasi(adr_org P, adr_pres &R);
void deleteAfterRelasi(adr_org P, adr_pres prec, adr_pres &R);
void deleteLastRelasi(adr_org P, adr_pres &R);
void deleteRelasi(ListOrg LP);
void connectRelasiDanChild(ListOrg &LP, ListMhs LC, string organisasi, string mahasiswa);
void showAllParentWithChild(ListOrg LP);

//Tampilan Menu
int menu1(ListOrg LP, ListMhs LC);
int menu2(ListOrg LP, ListMhs LC);
int menu3(ListOrg LP, ListMhs LC);
int menu4(ListOrg LP, ListMhs LC);

#endif // HEADER_H_INCLUDED