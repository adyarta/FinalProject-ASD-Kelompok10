#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//aplikasi penyimpanan data rawat inap rumah sakit

struct node //node data pasien untuk antrean
{
    string name;
    string ID;
    string critical;
    node* next;
    node* prev;
};

//deklarasi-deklarasi global - Linked List
node* HeadNormal;
node* TailNormal;
node* HeadCrit;
node* TailCrit;

//deklarasi-deklarasi global - Hashing
const char apahash[] = "!@#$%^&*()_+-=";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int size = sizeof(apahash);
int hashhash = 0; // hashlist
string hashTable[10]; // ini hashtable
string truehash[10]; // truehash


////////////////////////////////////////
void Hashing(string entry)
    {
        string NewEntry = entry;
        string notjoji;
        int bai = sizeof(NewEntry.size());
        acak :
            for (int j = 0; j < bai; j++)
                {
                    notjoji = notjoji + apahash[rand()% :: size];
                }
            for (int b = 0; b <= hashhash; b++)
                {
                    if(hashTable[b] == notjoji)
                        {
                            goto acak;
                        }
                }

                cout << entry << " -> " << notjoji << endl;

                truehash[hashhash] = entry;
                hashTable[hashhash] = notjoji;
                hashhash = hashhash + 1;
                cout << "Hash Hashuu" << endl;
        //Alexander
        //$*!@sjader
        //Jimmi Fernandes Rahman
        //^&*#sdfman
    }

void Display() //display antrean
{
    node* tempNormal;
    node* tempCrit;
    tempNormal = HeadNormal;
    int urut = 1;
    while (tempCrit != NULL)
    {
        cout << urut <<". " << tempCrit -> ID << " - "<<tempCrit -> name<< " - " << tempCrit->critical<<endl;
        tempCrit = tempCrit ->next;
        urut = urut +1;
    }
    while (tempNormal != NULL)
    {
        cout << urut <<". " << tempNormal -> ID << " - "<<tempNormal -> name<< " - " << tempNormal->critical<<endl;
        tempNormal = tempNormal ->next;
        urut = urut +1;
    }
}

bool check(string entry)
{
    int checklist = 0;
    while (checklist != hashhash)
    {
        if (entry == truehash[checklist])
        {
            return true;        
        }
        else
        {
        }
        return false;
    }
}

void InsertNormalPatient(string entry, int crit) // masukkan antrean baru untuk pasien yang tidak kritis
//pasien yang tidak kritis akan mengantri dari belakang
{
    node* temp = new node;
    temp -> name = entry;
    Hashing(entry);
    if (crit >= 2)
    {
        temp -> critical = "Rawat Inap";
    }
    else if (crit <=1)
    {
        temp -> critical = "Rawat Jalan";
    }

    if (HeadNormal == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadNormal = temp;
        TailNormal = HeadNormal;
    }

    else
    {
        TailNormal -> next = temp;
        temp -> next = NULL;
        temp -> prev = TailNormal;
        TailNormal = temp;
    }
}

void InsertEmergencyPatient(string entry, int crit)
{
    node* temp = new node;
    temp -> name = entry;
    Hashing(entry);
    if (crit == 1)
    {
        temp -> critical = "Mengkhawatirkan";
    }
    else if (crit == 2)
    {
        temp -> critical = "Gawat Darurat";
    }
    else if (crit == 3)
    {
        temp -> critical = "Kronis";
    }

    if (HeadCrit == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadCrit = temp;
        TailCrit = HeadCrit;
    }

    else
    {
        HeadCrit -> prev = temp;
        temp -> next = HeadCrit;
        temp -> prev = NULL;
        HeadCrit = temp;
    }
}


int main () //program utama; berisikan main menu
    {
        int crit;
        string entri;
        char input;
        MainMenu:
        cout << "=== Aplikasi Administrasi Rawat Inap Rumah Sakit ===" << endl;
        cout << "====================================================" << endl;
        cout << "Antrean Rawat Inap : " << endl;
        Display();
        cout << "====================================================" << endl;
        cout << "Main Menu : "<< endl;
        cout << "1. Daftarkan antrean pasien normal" << endl;
        cout << "2. Daftarkan antrean pasien darurat" << endl;
        cout << "3. Checkout Pasien" << endl;
        cout << "4. Tampilkan key ID" << endl;
        cout << "9. Help" << endl;
        cout << "0. Exit" << endl;
        cout << "====================================================" << endl;
        cout << "Entri: "; 
        cin >> input;
        switch (input)
            {            
                case '0':
                    cout << "================================ BYE BYE =====================================" << endl;
                    cout << "Thank you for running this program!"<< endl;
                    cout << "Made by SpectreOfSolitude, MrJM OF THE DARKSIDE, Ratonhnhaké:ton, and Zwinglee" << endl;
                    cout << "==============================================================================" << endl;
                    return 0;
                    break;
                    
                case '1':
                    cout << "Masukkan nama pasien yang ingin didaftarkan untuk dirujuk: "; 
                    getline(cin, entri);
                    cout << "Level Kekritisan: " << endl;
                    cout << "1. Rawat Jalan" << endl;
                    cout << "2. Rawat Inap" << endl;
                    cout << "================================" << endl;
                    cout << "Masukkan level kekritisan: "; 
                    cin >> crit;
                    if (crit == 1) // rawat jalan
                    {
                        check(entri);
                            // Ini tidak akan dimasukkan ke queue, karena ini aplikasi rawat inap.
                            // Jika pasien blom pernah mendaftar, maka hashing tetap dilakukan.
                    }
                    else if (crit == 2) // rawat inap biasa
                    {
                        InsertNormalPatient(entri, crit); //Ini masuk ke pendaftaran struktur queue
                    }
                    else 
                    {
                        cout << "Input salah. Silahkan ulangi penginputan." << endl;
                        goto MainMenu;
                    }
                    break;

                case '2':
                  cout << "Masukkan nama pasien yang ingin didaftarkan untuk dirujuk: "; 
                    getline(cin, entri);
                    cout << endl;
                    cout << "Level Kekritisan: " << endl;
                    cout << "1. Mengkhawatirkan" << endl;
                    cout << "2. Gawat Darurat" << endl;
                    cout << "3. Kronis" << endl;
                    cout << "================================" << endl;
                    cout << "Masukkan level kekritisan: "; 
                    cin >> crit;
                    if (crit < 1 || crit > 3)
                    {
                        cout << "Input salah. Silahkan ulangi penginputan." << endl;
                        goto MainMenu;
                    }
                    InsertEmergencyPatient(entri, crit); // ini struktur pendaftaran stack
                    break;

                case '3': // 
                    break;
                    
                case '4': // menampilkan Data Pasien yang di panggil dengan ID 
                    break;
                    
                case '9': // Help
                    cout <<"Ini penjelasan mengenai program simulasi inap yang udah dibuat." << endl;
                    break;

                default:
                    break;
            }
        goto MainMenu;
    }