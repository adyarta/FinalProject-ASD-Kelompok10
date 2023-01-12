#include <iostream>
#include <conio.h> //MENGGUNAKAN GETCH()
#define MAX 1000 //MAKSIMAL NOMOR ANTRIAN

using namespace std;

int nomer[MAX];
int headQueue = -1;
int tailQueue = -1;

//Deklarasi stack dengan struct dan array
struct STACK{
    string nama;

    STACK *next;
    STACK *prev;
};

STACK *headStack, *tailStack, *cur, *newNode, *del;
int maks = 5;

int countStack(){
    if(headStack == NULL){
        return 0;
    }else{
        int banyak = 0;
        cur = headStack;
        while(cur != NULL){
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

void createStack(string nama){
    headStack = new STACK();
    headStack->nama = nama;
    headStack->next = NULL;
    headStack->prev = NULL;
    tailStack = headStack;
}

//fungsi untuk menyisipkan data ke stack
void push(string data){
   if(countStack() == maks){
        cout << "stack full" << endl;
    }else{
        if(countStack() == 0){
            createStack(data);
        }else{
            newNode = new STACK();
            newNode->nama = data;
            newNode->next = NULL;
            newNode->prev = tailStack;
            tailStack = newNode;
        }
    }
}

bool IsEmptyQueue(){ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = -1
   if(tailQueue == -1){
       return true;
   }else{
       return false;
   }
}
bool IsFullQueue(){ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = MAX-1
   if(tailQueue == MAX-1){
       return true;
   }else{
       return false;
   }
}

void AntrianMasuk(int no){
    if (IsEmptyQueue()){
        headQueue = tailQueue = 0;
    }else {
        tailQueue++;
    }
    nomer[tailQueue] = no;
}

void AntrianKeluar(){
    if(IsEmptyQueue()){
        cout<<"Antrian sudah kosong ! ";
        getch();
    }else {
        for(int a=headQueue;a<tailQueue;a++){
            nomer[a]=nomer[a+1];
        }
        tailQueue--;
        if(tailQueue == -1){
            headQueue = -1;
        }
    }
}

void Clear(){
     headQueue = tailQueue = -1;
}

void viewStack(){
    if(headStack == NULL){
        cout << "Stack kosong" << endl;
    }else{
        int nomor = 1;
        cur = tailStack;
        cout << "===Tumpukan Nama Pasien===" << endl;
        while(cur != NULL){
            cout << nomor << ". " << cur->nama << endl;
            cur = cur->prev;
            nomor++;
        }
    }
}
void viewQueue(){
     if(IsEmptyQueue()){
         cout << "Antrian kosong ! ";

     }else {
         system("cls");
         for(int a=headQueue;a<=tailQueue;a++){
              cout << "==============================="
                   << "\n >> No. Antri : [" << nomer[a] << "]"
                   << "\n==============================="<< endl;
         }
     }
}


void menuAntrian();
void menuAdmin();
void menuUtama();

int main(){
    menuUtama();
}

void menuUtama(){
    int choose;
    string nama;
    system("cls");
    cout << "=====MENU MASUK=====" << endl;
    cout << "1. Pasien" << endl;
    cout << "2. Admin" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih: ";
    cin >> choose;

    switch (choose){
    case 1:
        cout << "===DAFTAR DULU===" << endl;
        cout << "Nama: ";
        cin >> nama;
        push(nama);
        menuAntrian();
        break;
    case 2:
        menuAdmin();
        break;

    case 0:
        system("cls");
        break;
    
    default:
        break;
    }
}

void menuAdmin(){
    int choose;
    do{
        system("cls");
        cout << "\n\n===== MENU ADMIN ====="
             << "\n|1. Panggil Antrian           |"
             << "\n|2. Lihat daftar pasien       |"
             << "\n|3. Lihat daftar antrian      |"
             << "\n|4. Format                    |"
             << "\n|0. Exit                      |";
        cout << "\nChoose ! "; cin >> choose;
        cout << "\n\n";

        if(choose == 1){
            cout << "=================================" << endl;
            cout << "No. Antri : [" << nomer[headQueue] << "]";
            cout << "\n=================================" << endl;
            AntrianKeluar();
            cout << "Silahkan Dipanggil !" << endl;
        }else if(choose == 2){
                viewStack();
        }else if(choose == 3){
                viewQueue();
        }else if(choose == 4){
            Clear();
            cout<<"Antrian dikosongkan ! ";
        }else if(choose == 0){
            menuUtama();
        }
         getch();
    } while (choose != 5);
    
}

void menuAntrian(){
    int choose, p=1, urut; //deklarasi untuk pilihan user dan nomer urut antrian
    do{
        system("cls");
        cout << "\n\n===== ANTRIAN PASIEN ====="
             << "\n==============================="
             << "\n|1. Tambah Antrian            |"
             << "\n|0. Exit                      |"
             << "\n===============================";
        cout << "\nChoose ! "; cin >> choose;
        cout << "\n\n";
        if(choose == 1){
            if(IsFullQueue()) {
                cout<<"Antrian sudah penuh, mohon tunggu beberapa saat lagi ";
            }
            else{
                urut=p;
                AntrianMasuk(urut);
                cout << "---------------------------------" << endl;
                cout << "|          NO. ANTRIAN          |" << endl;
                cout << "|               " << p << "              ||" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Silahkan Mengantri      |" << endl;
                cout << "|      Menunggu " << tailQueue << " Antrian      ||" << endl;
                cout << "---------------------------------" << endl;
                p++;
            }
        }else if(choose == 0){
            menuUtama();
        }
        else{
            cout << "Masukan anda salah ! \n"<< endl;
        }
        getch();
    }while(choose !=5 );
}
