#include <iostream>

using namespace std;

/*
aku mau coba push dulu ya
*/
// halo hali
// hm bgt
// halo guys ini nabil

struct Mahasiswa {
    char NPM[14];
    char nama[30];
    int nilai;
};

typedef Mahasiswa* pointer;

int main(){
    pointer p, q;
    p = new Mahasiswa;
    cout << "Nama   : " ; cin >> p->nama;
    cout << "NPM    : " ; cin >> p->NPM;
    cout << "Nilai  : " ; cin >> p->nilai;
    cout << endl;
    q = new Mahasiswa;
    cout << "Nama   : " ; cin >> q->nama;
    cout << "NPM    : " ; cin >> q->NPM;
    cout << "Nilai  : " ; cin >> q->nilai;
    cout << endl;

    cout << "Mahasiswa" << endl;
    cout << p->NPM << " " << p->nama << " " << p->nilai << endl;
    cout << q->NPM << " " << q->nama << " " << q->nilai << endl;

    delete(p);
    delete(q);
}