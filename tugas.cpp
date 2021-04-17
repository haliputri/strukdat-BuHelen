/*
Kelompok : 
Hali Putri Aisyah (140810200006)
Nawang Ilmi Adzani (140810200014)
M. Nabil Fikri S. P. (140810200046)

Deskripsi :
Melengkapi Function Multi Linked List

*/

#include <iostream>

struct Anak {
    char dataAnak;
    Anak * nextAnak;
};

struct Pegawai {
    char dataPeg;
    Anak* firstAnak;
    Pegawai* nextPeg;
};

typedef Anak* pointerAnak;
typedef Pegawai* pointerPeg;

typedef pointerPeg ListPeg;

// Parent LinkedList
void createListPeg(ListPeg& First){
    First = nullptr;
}

// ElementParent yg punya anak
void createElementPeg(pointerPeg& pBaru){
    pBaru = new Pegawai;
    pBaru->nextPeg = nullptr;
    pBaru->firstAnak = nullptr;
}

// Bikin Element Anak
void createElementAnak(pointerAnak& pBaru){
    pBaru = new Anak;
    pBaru->nextAnak = nullptr;
}

// Mengakses List Pegawai (Parent)
void traversalPeg(ListPeg First){
    pointerPeg pHelp = First;
    while (pHelp != nullptr){
        std::cout << pHelp->dataPeg << " " << std::endl;
        pHelp = pHelp->nextPeg;
    }
    std::cout<<std::endl;
}

void linearSearch(ListPeg First, char key, int& status, pointerPeg& pCa){
    
}
void insertFirstPeg(ListPeg& First, pointerPeg pBaru);
void deleteFirstPeg(ListPeg& First, pointerPeg& pHapus);

void insertFirstAnak(ListPeg& First, char key,pointerAnak pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pointerPeg pOrtu;
    int ketemu;
    std::cout<<"Insert First Anak"<<std::endl;
    
    // linearSearch(First,key,ketemu,pOrtu);
    pOrtu = First;
    ketemu = 0;
    while (pOrtu != nullptr && ketemu==0) { //!ketemu
        if (pOrtu->dataPeg==key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->nextPeg;
        }
    }
    
    if (ketemu){ // (ketemu==1)
        std::cout<<"Ditemukan"<< std::endl;
        if (pOrtu->firstAnak == nullptr){
            pOrtu->firstAnak = pBaru;
        }
        else {
            pBaru->nextAnak = pOrtu->firstAnak;
            pOrtu->firstAnak = pBaru;
        }
    }
    else{
        std::cout<< "Tidak ditemukan" << std::endl;
    }
}

void deleteFirstAnak(ListPeg& First, char key,pointerAnak& pHapus){
    // I.S List First mungkin kosong
    // F.S. List anak berkurang didepan, yg dihapus dikembalikan
    pointerPeg pOrtu;
    int ketemu;
    std::cout <<"Delete First Anak"<< std::endl;
    pOrtu=First;
    ketemu=0;
    while (pOrtu != nullptr && ketemu==0) {
        if (pOrtu->dataPeg==key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->nextPeg;
        }
    }
    if (ketemu) {
        if (pOrtu->firstAnak == nullptr){ // kosong
        pHapus=NULL;
        std::cout<<"List kosong, tidak ada hapus"<< std::endl;
        }
        else if (pOrtu->firstAnak->nextAnak== nullptr){
        //isi 1 elemen
            pHapus=pOrtu->firstAnak;
            pOrtu->firstAnak = nullptr;
        }
        else { // isi > 1 elemen
            pHapus = pOrtu->firstAnak;
            pOrtu->firstAnak = pOrtu->firstAnak->nextAnak;
            pHapus->nextAnak= nullptr;
        }
    }
    else{
    std::cout<<"Tidak ditemukan"<<std::endl;
    }
}

void traversalOrtuAnak(ListPeg First){
    pointerPeg pBantuPeg;
    pointerAnak pBantuAnak;
    std::cout<<"Traversal Pegawai"<<std::endl;
    pBantuPeg=First;
    while (pBantuPeg!=NULL){ //loop ortu
        std::cout<< pBantuPeg->dataPeg <<std::endl;
        pBantuAnak=pBantuPeg->firstAnak;
        while (pBantuAnak!=NULL) { //loop anak
            std::cout<<" "<<pBantuAnak->dataAnak <<std::endl;
            pBantuAnak=pBantuAnak->nextAnak;
        }
        pBantuPeg=pBantuPeg->nextPeg;
    }
}