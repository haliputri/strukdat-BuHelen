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
    int dataAnak;
    Anak * nextAnak;
};

struct Pegawai {
    std::string dataPeg;
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
    std::cout<<"Masukkan Divisi Pegawai : " ; std::cin>>pBaru->dataPeg;
    pBaru->nextPeg = nullptr;
    pBaru->firstAnak = nullptr;
}

// Bikin Element Anak
void createElementAnak(pointerAnak& pBaru){
    pBaru = new Anak;
    std::cout<<"Masukkan ID Anggota : " ; std::cin>>pBaru->dataAnak;
    pBaru->nextAnak = nullptr;
}

// Mengakses List Pegawai (Parent)
void traversalPeg(ListPeg First){
    pointerPeg pBantu;
	std::cout<<"\nData Divisi Pegawai"<<std::endl<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"No.\tNama Divisi Pegawai"<<std::endl;
	std::cout<<"-----------------------------------"<<std::endl;
	if (First == nullptr){
		std::cout<<"Tidak Terdapat Pegawai"<<std::endl;
	}
	else{
		int i=1;
		pBantu= First;
		while (pBantu!= nullptr){
            std::cout<<i++<<". "<<"\t"<<pBantu->dataPeg<<std::endl;
            pBantu=pBantu->nextPeg;
		}
	}
}
//koreksi guys kalo ada salah :)
void linearSearch(ListPeg First, std::string& key, pointerPeg& pCari){
    pCari = First;
    int ketemu;
    ketemu = 0;

    while (pCari->firstAnak == nullptr && ketemu == 0){
        if (pCari->dataPeg == key){
            ketemu = 1;
        } else{
            pCari = pCari->nextPeg;
        }
    }
    if (ketemu = 1){
        std::cout << "data ditemukan";
    } else {
        std::cout << "data tidak ditemukan";
    }
}

void insertFirstPeg(ListPeg& First, pointerPeg pBaru){
if (First== nullptr) {
		First=pBaru; 
        } else { 
		pBaru->nextPeg=First;
		First=pBaru;
	}
	std::cout<<"Data berhasil dimasukkan"<<'\n';
}

void deleteFirstPeg(ListPeg& First, pointerPeg& pHapus){
    if (First == nullptr){
        pHapus = nullptr;
        std::cout << "List Kosong" << '\n';
    } else {
        pHapus = First;
        First = First->nextPeg;
        pHapus->nextPeg = nullptr;
    }
    delete(pHapus);
}

void insertFirstAnak(ListPeg& First, std::string key,pointerAnak pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pointerPeg pOrtu, pCari;
    int ketemu;
    int id;

    // linearSearch(First,key,pCari);
    std::cout << "masukan data divisi pegawai yang akan dicari: "; // ini nabil yang nambah, koreksi aja kalau salah
    std::cin >> key; //ini nabil yang nambah
    linearSearch(First, key, pCari);
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
        if (pOrtu->firstAnak == nullptr){
            pOrtu->firstAnak = pBaru;
        }
        else {
            pBaru->nextAnak = pOrtu->firstAnak;
            pOrtu->firstAnak = pBaru;
        }
    }
}

void deleteFirstAnak(ListPeg& First, std::string key,pointerAnak& pHapus){
    // I.S List First mungkin kosong
    // F.S. List anak berkurang didepan, yg dihapus dikembalikan
    pointerPeg pOrtu;
    int ketemu;
    std::cout <<"Delete First Anak"<< std::endl;
    pOrtu=First;
    ketemu=0;
    while (pOrtu != nullptr && ketemu==0) {
        if (pOrtu->dataPeg == key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->nextPeg;
        }
    }
    if (ketemu) {
        if (pOrtu->firstAnak == nullptr){ // kosong
        pHapus= nullptr;
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
    std::cout<<"\nData Divisi Pegawai dan Anggota"<<std::endl<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
    pBantuPeg=First;
    while (pBantuPeg!= nullptr){ //loop ortu
        std::cout<< pBantuPeg->dataPeg <<std::endl;
        pBantuAnak=pBantuPeg->firstAnak;
        while (pBantuAnak!= nullptr) { //loop anak
            std::cout<<" "<<pBantuAnak->dataAnak <<std::endl;
            pBantuAnak=pBantuAnak->nextAnak;
        }
        pBantuPeg=pBantuPeg->nextPeg;
    }
}

int main(){
    pointerPeg peg;
	pointerAnak anak;
	ListPeg head;
	std::string data;
	std::string cari;
    int id;
	
	createListPeg(head);
	int pilih;
	do{
		system("cls");
		std::cout<<"================================================="<<'\n';
		std::cout<<"  Daftar Divisi dan Karyawan PT Informatika Unpad "<<'\n';
		std::cout<<"================================================="<<'\n';
	 	std::cout<<"1. Insert First Divisi Pegawai      "<<'\n';
		std::cout<<"2. Insert First Anggota             "<<'\n';
		std::cout<<"3. Delete First Divisi Pegawai      "<<'\n';
		std::cout<<"4. Delete First Anggota             "<<'\n';
		std::cout<<"5. Cetak Data Divisi Pegawai        "<<'\n';
		std::cout<<"6. Cetak Data Divisi dan Anggota    "<<'\n';
        std::cout<<"7. Mencari Divisi                   "<<'\n';
		std::cout<<"8. Keluar                           "<<'\n';
		std::cout<<"================================================="<<'\n';
		
		std::cout<<'\n'<<"Masukkan pilihan: ";
		std::cin>>pilih;
		
		switch(pilih){
		case 1:
			createElementPeg(peg);
			insertFirstPeg(head, peg);
			std::cout <<"\nDivisi baru berhasil ditambah." <<'\n';
			break;
		case 2:
			createElementAnak(anak);
			insertFirstAnak(head, data, anak);
			std::cout<<"\nAnggota baru berhasil ditambah."<<'\n';
			break;
		case 3:
			deleteFirstPeg(head, peg);
			std::cout<< "\nDivisi terakhir berhasil dihapus."<<'\n';
			break;
		case 4:
			std::cout << "masukan data divisi pegawai yang akan dicari: ";
			std::cin >> cari;
			deleteFirstAnak(head, data, anak);
			std::cout << "\nAnggota pertama berhasil dihapus." <<'\n';
		case 5:
			traversalPeg(head);
			break;
		case 6:
			traversalOrtuAnak(head);
			break;
		case 7:
            std::cout << "masukan data divisi pegawai yang akan dicari: "; // ini nabil yang nambah, koreksi aja kalau salah
            std::cin >> cari; //ini nabil yang nambah
			linearSearch(head, cari, peg);
			break;	
		}
		std::cout<<std::endl;
		system("pause");
	}
	while(pilih!=8);
}