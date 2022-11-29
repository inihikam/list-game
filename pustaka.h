#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>

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
    if (isEmpty() == true){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    } else {
        //KONDISI JIKA DATA TIDAK KOSONG
        bantu = head;
        do{
            //JIKA DATA LEBIH KECIL DARI HEAD
            if (baru->rilis < head->rilis){
                baru->next = head;
                baru->prev = tail;
                tail->next = baru;
                head->prev = baru;
                head = baru;
            }

            //PENGECEKAN DATA BARU LEBIH KECIL DARI NODE BANTU
            if (baru->rilis < bantu->rilis && baru->rilis > head->rilis){
                baru->next = bantu;
                baru->prev = bantu->prev;
                bantu->prev->next = baru;
                bantu->prev = baru;
            }
        
            bantu = bantu->next;
        } while (bantu != head);
    }
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
        }
        
        //MENGHAPUS DATA JIKA BERADA DI DEPAN
        if (cariGame == head->nama){
            hapus = head;
            tail->next = head->next;
            head = head->next;
            head->prev = tail;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
        }

        //MENGHAPUS JIKA DATA LEBIH DARI 1 DAN DI TENGAH
        if (cariGame == bantu->nama){
            hapus = bantu;
            bantu->next->prev = bantu->prev;
            bantu->prev->next = bantu->next;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
        }

        //MENGHAPUS DATA JIKA BERADA DI BELAKANG
        if (cariGame == tail->nama){
            hapus = tail;
            head->prev = tail->prev;
            tail = tail->prev;
            tail->next = head;
            ketemu = true;
            cout << hapus->nama << " berhasil dihapus!\n";
            delete hapus;
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