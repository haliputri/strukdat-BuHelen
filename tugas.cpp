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
    Anak * next;
};

struct Pegawai {
    char dataPeg;
    Anak* firstAnak;
    Pegawai* next;
};

typedef Anak* pointerAnak;
typedef Pegawai* pointerPeg;

typedef pointerPeg ListPeg;

// Parent LinkedList
void createListPeg(ListPeg& First){
    First = new Pegawai;
    First->next = nullptr;
    First->firstAnak = nullptr;
}

// ElementParent yg punya anak
void createElementPeg(pointerPeg& pBaru){
    pBaru = new Pegawai;
    pBaru->firstAnak->next = nullptr;
}

// Bikin Element Anak
void createElementAnak(pointerAnak& pBaru){
    pBaru = new Anak;
    pBaru->next = nullptr;
}

// Mengakses List Pegawai (Parent)
void traversalPeg(ListPeg First){
    pointerPeg pHelp = First;
    while (pHelp != nullptr){
        std::cout << pHelp->dataPeg << " " << std::endl;
        pHelp = pHelp->next;
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
    while (pOrtu !=NULL && ketemu==0) { //!ketemu
        if (pOrtu->dataPeg==key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->next;
        }
    }

    
    if (ketemu){ // (ketemu==1)
        std::cout<<"Ditemukan"<< std::endl;
        if (pOrtu->firstAnak == nullptr){
            pOrtu->firstAnak = pBaru;
        }
        else {
            pBaru->next = pOrtu->firstAnak;
            pOrtu->firstAnak = pBaru;
        }
    }
    else{
        std::cout<< "Tidak ditemukan" << std::endl;
    }
}
void deleteFirstAnak(ListPeg& First, char key,pointerAnak& pHapus){
    
}
void traversalOrtuAnak(ListPeg First){

}