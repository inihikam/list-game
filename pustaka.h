#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>

using namespace std;

//INISIALISASI STRUCT GAME
struct game {
    string nama;
    int rilis;
    game *next;
    game *prev;
};

//INISIALISASI HEAD DAN TAIL
game *head, *tail;

//FUNGSI UNTUK MENGECEK DATA KOSONG ATAU TIDAK
bool isEmpty(){
    if (head == NULL && tail == NULL){
        return true;
    } else {
        return false;
    }
}

//FUNGSI INSERT DATA
void insertData(string nama, int rilis){
    game *baru;
    game *bantu;
    baru = new game;
    
    //MENGISI DATA KE DALAM NODE
    baru->nama = nama;
    baru->rilis = rilis;
    baru->next = NULL;
    baru->prev = NULL;

    //KONDISI JIKA DATA KOSONG
    if (head == NULL && tail == NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    } else {
        //KONDISI JIKA DATA TIDAK KOSONG
        bantu = head;

        //PARSE STRING KE DALAM CHAR ARRAY
        int sizeBaru = baru->nama.length();
        int sizeHead = head->nama.length();
        int sizeTail = tail->nama.length();
        char namaBaru[sizeBaru + 1];
        char namaHead[sizeHead + 1];
        char namaTail[sizeTail + 1];
        strcpy(namaBaru, baru->nama.c_str());
        strcpy(namaHead, head->nama.c_str());
        strcpy(namaTail, tail->nama.c_str());
        do{
            int sizeBantu = bantu->nama.length();
            int sizeBantuNext = bantu->next->nama.length();
            char bantuNama[sizeBantu + 1];
            char bantuNextNama[sizeBantuNext + 1];
            strcpy(bantuNama, bantu->nama.c_str());
            strcpy(bantuNextNama, bantu->next->nama.c_str());

            // JIKA DATA LEBIH KECIL DARI HEAD
            if (namaBaru[0] < namaHead[0]){
                baru->next = head;
                head->prev = baru;
                head = baru;
                tail->next = head;
                head->prev = tail;
                break;
            }
            
            // JIKA SAMA DENGAN HEAD TETAPI SETELAHNYA TIDAK SAMA
            if (namaBaru[0] == namaHead[0]){
                int kode = 0;
                int i = 1;
                do{
                    if (namaBaru[i] < namaHead[i]){
                        kode = 1;
                        break;
                    }
                    if (namaBaru[i] > namaHead[i]){
                        kode = 2;
                        break;
                    }
                    i++;
                } while (namaHead[i] != '\0');
                
                if (kode == 1){
                    baru->next = head;
                    head->prev = baru;
                    head = baru;
                    tail->next = head;
                    head->prev = tail;
                }

                if (kode == 2){
                    if (head == tail){
                        tail->next = baru;
                        baru->prev = tail;
                        tail = baru;
                        tail->next = head;
                        head->prev = tail;
                    } else {
                        baru->next = bantu->next;
                        bantu->next->prev = baru;
                        bantu->next = baru;
                        baru->prev = bantu;
                    }
                }
                break;
            }

            // PENGECEKAN DATA BARU LEBIH BESAR DARI TAIL
            if (namaBaru[0] > namaTail[0]){
                tail->next = baru;
                baru->prev = tail;
                tail = baru;
                tail->next = head;
                head->prev = tail;
                break;
            }

            // PENGECEKAN JIKA HURUF PERTAMA BARU SAMA DENGAN TAIL DAN SETELAHNYA TIDAK
            if (namaBaru[0] == namaTail[0]){
                int kode = 0;
                int i = 1;
                do{
                    if (namaBaru[i] < namaTail[i]){
                        kode = 1;
                        break;
                    }
                    if (namaBaru[i] > namaTail[i]){
                        kode = 2;
                        break;
                    }
                    i++;
                } while (namaTail[i] != '\0');
                
                if (kode == 1){
                    if (head == tail){
                        baru->next = tail;
                        tail->prev = baru;
                        head = baru;
                        tail->next = head;
                        head->prev = tail;
                    } else {
                        baru->next = tail;
                        baru->prev = tail->prev;
                        tail->prev->next = baru;
                        tail->prev = baru;
                    }
                }

                if (kode == 2){
                    tail->next = baru;
                    baru->prev = tail;
                    tail = baru;
                    tail->next = head;
                    head->prev = tail;    
                }
                
                break;
            }
             
            // PENGECEKAN DATA BARU LEBIH BESAR DARI NODE BANTU
            if (namaBaru[0] > bantuNama[0] && namaBaru[0] < bantuNextNama[0]){
                baru->next = bantu->next;
                bantu->next->prev = baru;
                bantu->next = baru;
                baru->prev = bantu;
                break;
            }

            // PENGECEKAN DATA JIKA HURUF PERTAMA SAMA DENGAN BANTU TAPI SETELAHNYA TIDAK
            if (namaBaru[0] == bantuNama[0] && namaBaru[0] > namaHead[0] && namaBaru[0] < namaTail[0]){
                int kode = 0;
                int i = 1;
                do{
                    if (namaBaru[i] < bantuNama[i]){
                        kode = 1;
                        break;
                    }
                    if (namaBaru[i] > bantuNama[i]){
                        kode = 2;
                        break;
                    }
                    i++;
                } while (bantuNama[i] != '\0');
                
                if (kode == 1){
                    baru->next = bantu;
                    baru->prev = bantu->prev;
                    bantu->prev->next = baru;
                    bantu->prev = baru;
                }

                if (kode == 2){
                    baru->next = bantu->next;
                    bantu->next->prev = baru;
                    bantu->next = baru;
                    baru->prev = bantu;
                }
                break;
            }
            
            memset(bantuNama, 0, sizeBantu);
            memset(bantuNextNama, 0, sizeBantuNext);
            sizeBantu = 0;
            bantu = bantu->next;
        } while (bantu != head);
    }

    //OUTPUT DATA YANG DIMASUKAN
    cout << "Game " << baru->nama << " " << baru->rilis << " berhasil dimasukan!\n";
}

void delData(){
    game *bantu;
    game *hapus;
    string cariGame;
    bool ketemu = false;
    bantu = head;
    cout << "Masukkan nama game yang ingin dihapus : ";
    cin.ignore();
    getline(cin, cariGame);
    do{
        //MENGHAPUS JIKA DATA HANYA ADA 1
        if (cariGame == bantu->nama && head == tail){
            hapus = head;
            head = NULL;
            tail = NULL;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
            break;
        }
        
        //MENGHAPUS DATA JIKA BERADA DI DEPAN
        if (cariGame == head->nama){
            hapus = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
            break;
        }

        //MENGHAPUS JIKA DATA LEBIH DARI 1 DAN DI TENGAH
        if (cariGame == bantu->nama && cariGame != head->nama){
            hapus = bantu;
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
            break;
        }

        //MENGHAPUS DATA JIKA BERADA DI BELAKANG
        if (cariGame == tail->nama){
            hapus = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
            break;
        }
        
        bantu = bantu->next;
    } while (bantu != head);
    
    if (ketemu == false){
        cout << "Data tidak ditemukan!\n";
    }
}

//FUNGSI UNTUK MENAMPILKAN DATA
void showData(){
    game *bantu;
    if (isEmpty() == true){
        cout << "List masih kosong!\n";
    } else {
        bantu = head;
        cout << "List Game : \n";
        do{
            cout << bantu->nama << " | " << bantu->rilis << "\n";
            bantu = bantu->next;
        } while (bantu != head);   
    }
}