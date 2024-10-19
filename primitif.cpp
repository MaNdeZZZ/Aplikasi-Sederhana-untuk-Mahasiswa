#include "header.h"

//Primitif Parent
void createListParent(ListOrg &LP){
    first(LP) = NULL;
}

adr_org alokasiParent(infotyope_org XP){

    adr_org P = new elmOrganisasi;
    info(P) = XP;
    next(P) = NULL;
    nextPres(P) = NULL;
    return P;
}

void insertLastParent(ListOrg &LP, adr_org P){
    adr_org Q;

    Q = first(LP);
    if (first(LP) == NULL) {
        first(LP) = P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        nextPres(P) = NULL;
    }
}

void deleteFirstParent(ListOrg &LP, adr_org &P) {
    adr_pres R, prec;

    P = first(LP);
    first(LP) = next(P);
    next(P) = NULL;
}

void deleteAfterParent(ListOrg &LP, adr_org &P) {
    adr_org prec;
    prec = first(LP);
    while (next(prec) != P){
        prec = next(prec);
    }
    next(prec) = next(P);
    next(P) = NULL;
}

void deleteLastParent(ListOrg &LP, adr_org &P) {
    adr_org Q;

    Q = first(LP);
    if (first(LP) == NULL) {
        cout << "List Organisasi Kosong" << endl;
    } else if (next(Q) == NULL) {
        P = first(LP);
        first(LP) = NULL;
        next(P) = NULL;
    } else {
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
    P = next(Q);
    next(Q) = NULL;
    }
}

void printInfoParent(ListOrg LP){
    adr_org P;

    P = first(LP);
    if (P == NULL) {
        cout << "List Organisasi Kosong" << endl;
    } else {
        while (P != NULL) {
            cout << "ID             : " << info(P).id << endl;
            cout << "Nama Organisasi: " << info(P).namaorg << endl;
            cout << "Lokasi         : " << info(P).lokasi << endl;
            cout << " " << endl;
            P = next(P);
        }
    }
}

adr_org findElementParent(ListOrg LP, string nama) {
    adr_org P;

    P = first(LP);
    while (P != NULL) {
        if (info(P).namaorg == nama) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

//Primitif Child
void createListChild(ListMhs &LC){
    first(LC) = NULL;
}

adr_mhs alokasiChild(infotyope_mhs XC){
    adr_mhs P;

    P = new elmMahasiswa;
    info(P) = XC;
    next(P) = NULL;
    return P;
}

void insertLastChild(ListMhs &L, adr_mhs C){
    adr_mhs Q;

    Q = first(L);
    if (first(L) == NULL) {
        first(L) = C;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = C;
    }
}

void deleteFirstChild(ListMhs &LC, adr_mhs &C) {
    C = first(LC);
    first(LC) = next(C);
    next(C) = NULL;
}

void deleteAfterChild(ListMhs &LC, adr_mhs &C) {
    adr_mhs prec;
    prec = first(LC);
    while (next(prec) != C){
        prec = next(prec);
    }
    next(prec) = next(C);
    next(C) = NULL;
}

void deleteLastChild(ListMhs &LC, adr_mhs &C){
    adr_mhs Q;

    Q = first(LC);
    if (first(LC) == NULL) {
        cout << "List Mahasiswa Kosong" << endl;
    } else if (next(first(LC)) == NULL) {
        C = first(LC);
        first(LC) = NULL;
    } else {
        while (next(next(Q)) == NULL) {
            Q = next(Q);
        }
    }
    C = next(Q);
    next(Q) = NULL;
}

void printInfoChild(ListMhs LC){
    adr_mhs C;

    C = first(LC);
    while (C != NULL) {
        cout << "NIM              : " << info(C).nim << endl;
        cout << "Nama             : " << info(C).nama << endl;
        cout << "Prodi            : " << info(C).prodi << endl;
        cout << "Angkatan         : " << info(C).angkatan << endl;
        cout << "" << endl;
        C = next(C);
    }
}

adr_mhs findElementChild(ListMhs LC, string nama) {
    adr_mhs C;

    C = first(LC);
    while (C != NULL) {
        if (info(C).nama == nama) {
            return C;
        }
        C = next(C);
    }
    return NULL;
}

adr_pres findChildFromParent(ListOrg LP, string namaMHS, string namaORG) {
    adr_org P;
    adr_pres R;

    P = findElementParent(LP, namaORG);
    R = nextPres(P);
    while (R != NULL) {
        if (info(nextMhs(R)).nama == namaMHS) {
           return R;
        }
        R = next(R);
    }
    return NULL;
}

//Primitif Relasi
adr_pres alokasiRelasi(adr_mhs C){
    adr_pres R = new elmPrestasi;
    next(R) = NULL;
    nextMhs(R) = C;
    return R;
}

void insertLastRelasi(ListOrg &LP, adr_pres R, string namaOrg){
    adr_org P;
    adr_pres Q;

    P = findElementParent(LP, namaOrg);
    Q = nextPres(P);
    if (Q == NULL) {
        nextPres(P) = R;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = R;
    }
}

void deleteFirstRelasi(adr_org P, adr_pres &R) {
    R = nextPres(P);

    if (next(R) == NULL) {
        nextMhs(R) = NULL;
        nextPres(P) = NULL;
    } else {
        nextPres(P) = next(R);
        next(R) = NULL;
        nextMhs(R) = NULL;
    }
}

void deleteAfterRelasi(adr_org P, adr_pres prec, adr_pres &R) {
    R = next(prec);
    next(prec) = R;
    next(R) = NULL;
    nextMhs(R) = NULL;
}

void deleteLastRelasi(adr_org P, adr_pres &R) {
    adr_pres Q;

    while (next(next(Q)) == NULL) {
        Q = next(Q);
    }
    R = next(Q);
    next(Q) = NULL;
    nextMhs(R) = NULL;
    
}

void connectRelasiDanChild(ListOrg &LP, ListMhs LC, string organisasi, string mahasiswa){
    adr_mhs C = findElementChild(LC, mahasiswa);
    adr_pres R = alokasiRelasi(C);

    insertLastRelasi(LP, R, organisasi);
}

void showAllParentWithChild(ListOrg LP){
    adr_org P = first(LP);
    int i = 1;
    if (P==NULL){
        cout<<"Organisasi belum ada"<<endl;
    } else {
        while (P !=NULL){
            cout << i<<". "<<info(P).namaorg << endl; 
            // showParent(P);
            cout << "=================================" << endl;
            adr_pres Q = nextPres(P);
            while (Q != NULL){
                cout << "NIM              : " << info(nextMhs(Q)).nim << endl;
                cout << "Nama             : " << info(nextMhs(Q)).nama << endl;
                cout << "Prodi            : " << info(nextMhs(Q)).prodi << endl;
                cout << "Angkatan         : " << info(nextMhs(Q)).angkatan << endl;
                cout << "" << endl;
                Q = next(Q);
            }
            cout << "=================================" << endl;
            i++;
            cout<<endl;
            P=next(P);
        }
    }
}


//Tampilan Menu
int menu2(ListOrg LP, ListMhs LC){
    int n1;
    string opsi, anything;
    adr_org P;
    infotyope_org XP;
    cout << "" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|   Organisasi Mahasiswa  |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|      MENU ORGANISASI    |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<=| 1. Masukkan Data Organisasi                |=>" << endl;
	cout << "<=| 2. Menghapus Data Organisasi dan Prestasi  |=>" << endl;
	cout << "<=| 3. Menampilkan Seluruh Data Organisasi     |=>" << endl;
	cout << "<=| 4. Mencari Data Organisasi                 |=>" << endl;
	cout << "<=| 5. Mencari Data Mahasiswa Berprestasi      |=>" << endl;
    cout << "<=|    dari Organisasi                         |=>" << endl;
	cout << "<=| 6. Menampilkan Seluruh Data Organisasi     |=>" << endl;
	cout << "<=|    Beserta Data Mahasiswa Berprestasi      |=>" << endl;
	cout << "<=| 7. Menghapus Data Mahasiswa Berprestasi    |=>" << endl;
	cout << "<=|    dari Organisasi                         |=>" << endl;
	cout << "<=| 8. Menghitung Total Data Mahasiswa         |=>" << endl;
	cout << "<=|    Berprestasi dari Organisasi             |=>" << endl;
	cout << "<=| 0. Exit                                    |=>" << endl;
	cout << "<================================================>" << endl;
	cout << "Pilih Opsi Anda: ";
    cin >> opsi;
    if (opsi == "1"){
        system("cls");
        cout << "Berapa Organisasi yang ingin anda masukkan: ";
        cin >> n1;
        for (int i = 0; i < n1; i++) {
            cout << "ID             : ";
            cin >> XP.id;
            cout << "Nama Organisasi: ";
            cin >> XP.namaorg;
            cout << "Lokasi         : ";
            cin >> XP.lokasi;
            cout << endl;
            P = alokasiParent(XP);
            insertLastParent(LP, P);
        }
        anything = cin.get();
        menu2(LP, LC);
    } else if (opsi == "2"){
        system("cls");
        string organisasi;
        adr_org P;
        cout << "Input nama organisasi yang ingin dihapus: ";
        cin >> organisasi;
        P = findElementParent(LP, organisasi);
        if (P == NULL) {
            cout << "Data Organisasi yang ingin anda hapus tidak ditemukan" << endl;
        } else {
            if (first(LP) == P){
                deleteFirstParent(LP, P);
            } else if (next(P) == NULL){
                deleteLastParent(LP, P);
            } else {
                deleteAfterParent(LP, P);
            }
            cout << "Data berhasil dihapus" << endl;
        }
        menu2(LP, LC);
    } else if (opsi == "3"){
        system("cls");
        cout << "===DATA ORGANISASI===" << endl;
        printInfoParent(LP);
        menu2(LP, LC);
    } else if (opsi == "4"){
        system("cls");
        string organisasi;
        adr_org P;
        cout << "Input nama organisasi: ";
        cin >> organisasi;
        P = findElementParent(LP, organisasi);
        if (P == NULL) {
            cout << "Nama Organisasi yang anda cari tidak ditemukan" << endl;
        } else {
            cout << "== Organisasi Ditemukan ==" << endl;
            cout << "Id Organisasi     : "<<info(P).id << endl;
            cout << "Nama Organisasi   : "<<info(P).namaorg << endl;
            cout << "Lokasi Organisasi : "<<info(P).lokasi << endl;
        }
        menu2(LP, LC);
    } else if (opsi == "5"){
        system("cls");
        string namaOrganisasi;
        string namaMahasiswa;
        adr_pres R;
        cout << "Masukkan nama Organisasi: ";
        cin >> namaOrganisasi;
        cout << "Masukkan nama Mahasiswa yang ingin anda cari: ";
        cin >> namaMahasiswa;
        R = findChildFromParent(LP, namaMahasiswa, namaOrganisasi);
        if (R == NULL){
            cout << "Mahasiswa tidak terdaftar";
        } else {
            cout << "Mahasiswa terdaftar";
        }
        menu2(LP, LC);
    } else if (opsi == "6"){
        system("cls");
        cout << "===NAMA ORGANISASI DAN  LIST MAHASISWA BERPRESTASI===" << endl << endl;
        showAllParentWithChild(LP);
        menu2(LP, LC);
    } else if (opsi == "7"){
        //Menghapus data child dari parent tertentu beserta relasinya
        system("cls");
        string organisasi, mahasiswa;
        adr_org Q;
        adr_pres prec, P;
        cout << "Input nama organisasi                   : ";
        cin >> organisasi;
        cout << "Input nama mahasiswa yang ingin dihapus : ";
        cin >> mahasiswa;
        Q = findElementParent(LP, organisasi);
        P = findChildFromParent(LP, mahasiswa, organisasi);
        if (P == nextPres(Q)){
            nextPres(Q) = next(P);
            next(P) = NULL;
        } else if(next(P) == NULL){
            prec = nextPres(Q);
            while (next(prec) != P){
                prec = next(prec);
            }
            next(prec) = NULL;
        } else {
            prec = nextPres(Q);
            while (next(prec) != P){
                prec = next(prec);
            }
            next(prec) = next(P);
            next(P) = NULL; 
        }
        menu2(LP, LC);
    } else if (opsi == "8"){
        //Menghitung jumlah child dari parent tertentu
        system("cls");
        string organisasi;
        adr_org P;
        adr_pres Q;
        int i = 0;
        cout << "Input nama organisasi: ";
        cin >> organisasi;
        P = findElementParent(LP, organisasi);
        if (P == NULL) {
            cout << "Nama Organisasi yang anda masukkan tidak ditemukan" << endl;
        } else {
            Q = nextPres(P);
            while (Q != NULL){
                i++;
                Q = next(Q);
            }
            cout << i;
        }
        menu2(LP, LC);
    } else if (opsi == "0"){
        system("cls");
        menu1(LP, LC);
    } else {
        system("cls");
        cout << "Opsi tidak valid, silahkan pilih ulang";
        menu2(LP, LC);
    }
    return 0;
}

int menu3(ListOrg LP, ListMhs LC){
    int opsi;
    cout << "" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|  Organisasi, Mahasiswa  |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|      MENU MAHASISWA     |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<=| 1. Masukkan Data Mahasiswa                 |=>" << endl;
	cout << "<=| 2. Mencari Data Mahasiswa                  |=>" << endl;
    cout << "<=| 3. Menghapus Data Mahasiswa                |=>" << endl;
    cout << "<=| 4. Show Data Mahasiswa                     |=>" << endl;
	cout << "<=| 0. Exit                                    |=>" << endl;
	cout << "<================================================>" << endl;
	cout << "Pilih Opsi Anda: ";
    cin >> opsi;
    if (opsi == 1){
        system("cls");
        infotyope_mhs XC;
        adr_mhs C;
        int n2;
        createListChild(LC);
        cout << "Berapa Mahasiswa yang ingin anda masukkan: ";
        cin >> n2;
        for (int i = 0; i < n2; i++) {
            cout << "Nama Mahasiswa : ";
            cin >> XC.nama;
            cout << "NIM Mahasiswa  : ";
            cin >> XC.nim;
            cout << "Prodi          : ";
            cin >> XC.prodi;
            cout << "Angkatan       : ";
            cin >> XC.angkatan;
            cout << endl;
            C = alokasiChild(XC);
            insertLastChild(LC, C);
        }
        menu3(LP, LC);
    } else if (opsi == 2){
        system("cls");
        string mahasiswa;
        adr_mhs Q;
        cout << "Input nama mahasiswa: ";
        cin >> mahasiswa;
        Q = findElementChild(LC, mahasiswa);
        if (Q == NULL) {
            cout << "Nama Mahasiswa yang anda cari tidak ditemukan" << endl;
        } else {
            cout << "NIM     : " << info(Q).nim << endl;
            cout << "Nama    : " << info(Q).nama << endl;
            cout << "Prodi   : " << info(Q).prodi << endl;
            cout << "Angkatan: " << info(Q).angkatan << endl;
        }
        menu3(LP, LC);
    } else if(opsi == 3) {
        system("cls");
        string mahasiswa;
        adr_mhs P;
        cout << "Input nama mahasiswa yang ingin dihapus: ";
        cin >> mahasiswa;
        P = findElementChild(LC, mahasiswa);
        if (P == NULL) {
            cout << "Nama Mahasiswa yang ingin dihapus tidak ada" << endl;
        } else {
            if (first(LC) == P){
                deleteFirstChild(LC, P);
            } else if (next(P) == NULL){
                deleteLastChild(LC, P);
            } else {
                deleteAfterChild(LC, P);
            }
            cout << "Data berhasil dihapus" << endl;
        }
        menu3(LP, LC);
    } else if(opsi == 4) {
        system("cls");
        cout << "===DATA MAHASISWA===" << endl;
        printInfoChild(LC);
        menu3(LP, LC);
    } else if(opsi == 0){
        system("cls");
        menu1(LP, LC);
    } else {
        system("cls");
        cout << "Opsi tidak valid, silahkan pilih ulang";
        menu3(LP, LC);
    }
    return 0;
}

int menu4(ListOrg LP, ListMhs LC){
    int opsi;
    cout << "" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|  Organisasi, Mahasiswa  |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|       MENU UTAMA        |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|       1. Connect List   |==========>" << endl;
	cout << "<===========|       0. Exit           |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "Pilih Opsi Anda: ";
    cin >> opsi;
    if(opsi == 1){
        system("cls");
        string namaMHS, namaORG;
        cout << "Mahasiswa yang berprestasi: ";
        cin >> namaMHS;
        cout << "Organisasi asal mahasiswa : ";
        cin >> namaORG;
        connectRelasiDanChild(LP, LC, namaORG, namaMHS);
        menu4(LP, LC);
    } else if (opsi == 0){
        system("cls");
        menu1(LP, LC);
    } else {
        system("cls");
        cout << "Opsi tidak valid, silahkan pilih ulang";
        menu4(LP, LC);
    }
    return 0;
}

int menu1(ListOrg LP, ListMhs LC){
    int opsi;
    cout << "" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|  Organisasi, Mahasiswa  |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|       MENU UTAMA        |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "<===========|       1. Organisasi     |==========>" << endl;
	cout << "<===========|       2. Mahasiswa      |==========>" << endl;
    cout << "<===========|       3. Prestasi       |==========>" << endl;
	cout << "<===========|       0. Exit           |==========>" << endl;
	cout << "<================================================>" << endl;
	cout << "Pilih Opsi Anda: ";
    cin >> opsi;
    if (opsi == 1){
        system("cls");
        menu2(LP, LC);
    } else if (opsi == 2){
        system("cls");
        menu3(LP, LC);
    } else if(opsi == 3){
        system("cls");
        menu4(LP, LC);
    } else if(opsi == 0){
        system("cls");
        exit(0);
    }
    return 0;
};