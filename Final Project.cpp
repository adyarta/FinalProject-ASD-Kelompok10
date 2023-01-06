#include <iostream>
using namespace std;

struct node //node ID antrean
{
    string nama;
    string ID;
    node* next;
    node* prev;
};

//deklarasi-deklarasi global
node* head;
node* tail;

void Display() //display antrean
{

}

void InsertNormalPatient(string entry) // masukkan antrean baru untuk pasien yang tidak kritis
//pasien yang tidak kritis akan mengantri dari belakang
{
    node* temp = new node;
    temp -> ID = entry;

    if (head == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        head = temp;
        tail = head;
    }
    else
    {
        tail -> next = temp;
        temp -> next = NULL;
        temp -> prev = tail;
        tail = temp; 
    }
}

void encryption() //pengenkripsian data asli
{

}

int main () //program utama; berisikan main menu
{

string entri;
char input;
MainMenu:
cout << "=== Aplikasi Administrasi Rumah Sakit ===" << endl;
cout << "=========================================" << endl;
cout << "Main Menu:"<< endl;
cout << "1. Daftarkan Antrian pasien" << endl;
cout << "2. Daftarkan Antrean darurat" << endl;
cout << "3. Check Out Pasien" << endl;
cout << "0. Exit" << endl;
cout << "=========================================" << endl;
cout << "Entri: "; cin >> input;

switch (input)
{
    case '0':
        return 0;
        break;
    case '1':
        cout << "Masukkan data pasien yang ingin didaftarkan: "; cin >> entri;
        InsertNormalPatient(entri);
        break;
    case '2':
        break;
    case '3':
        break;
    default:
        break;
}
goto MainMenu;
}