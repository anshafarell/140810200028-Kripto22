/*
    Nama    : Ananda Shaquille Farell
    NPM     : 140810200028
    MK      : Kriptografi (Praktikum)
    Hal     : Tugas Hill Cipher
*/
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

#define ma_mod(a,n) ((a%n)+n)%n // Untuk mod

int main(){
    int determinan, enkripsi1, enkripsi2, length, nilai1, nilai2, pilihan;
    string teks;
    system("CLS");
    cout << "+-------------------------+" << endl;
    cout << "|   PROGRAM HILL CIPHER   |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "| ANANDA SHAQUILLE FARELL |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "Menu: " << endl;
    cout << "1. Matriks kunci 2x2" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    cout << endl;

    if(pilihan == 0){ // Pilihan Exit - Keluar dari program
        system("CLS");
        cout << "Terima kasih telah menggunakan program ini!" << endl;
        Sleep(2000);
        system("CLS");
        return 0;
    }
    else if (pilihan == 1){ // Pilihan Matriks kunci 2x2
        int kunci[2][2];
        duakalidua:
        system("CLS");
        cout << "+-------------------+" << endl;
        cout << "| MATRIKS KUNCI 2x2 |" << endl;
        cout << "+-------------------+" << endl;
        cout << "Menu: " << endl;
        cout << "1. Enkripsi" << endl;
        cout << "2. Dekripsi" << endl;
        cout << "3. Cari kunci" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cout << endl;
    
        if(pilihan == 0){ // Pilihan Exit - Keluar dari Program
            system("CLS");
            return 0;
        }
        else if(pilihan == 1){ // Pilihan Enkripsi
            cout << "Teks   : ";
            cin >> teks;
            length = teks.length();
            if(length % 2 != 0){
                cout << "Jumlah karakter ganjil, mohon tambah 1 karakter!" << endl;
                Sleep(3000);
                goto duakalidua;
            }
            cout << "Masukkan kunci: " << endl;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    cout << "- Baris " << i+1 << ", Kolom " << j+1 << ": ";
                    cin >> kunci[i][j];
                }
            }

            // Mencari determinan
            determinan = (kunci[0][0] * kunci[1][1]) - (kunci[0][1] * kunci[1][0]);
            if(determinan == 0 || determinan == 13 || determinan % 2 == 0){
                cout << endl << "Matriks kunci tidak memenuhi syarat. Proses enkripsi tidak dapat diteruskan!" << endl;
                return 0;
            }

            // Proses enkripsi
            for(int i = 0; teks[i] != '\0'; ++i){
                if(i % 2 == 0){
                    nilai1 = int(teks[i]) - int('A');
                }
                else if(i % 2 != 0){
                    nilai2 = int(teks[i]) - int('A');
                    enkripsi1 = (kunci[0][0] * nilai1) + (kunci[0][1] * nilai2);
                    enkripsi2 = (kunci[1][0] * nilai1) + (kunci[1][1] * nilai2);
                    enkripsi1 = ma_mod(enkripsi1,26);
                    enkripsi2 = ma_mod(enkripsi2,26);
                    teks[i-1] = char(enkripsi1 + int('A'));
                    teks[i] = char(enkripsi2 + int('A'));
                }
            }
            cout << endl;
            cout << "Hasil enkripsi: " << teks << endl;
        }
        else if(pilihan == 2){ // Dekripsi
            int inverse[2][2], matrikstemp[2][2], temp;
            cout << "Teks   : ";
            cin >> teks;
            length = teks.length();
            if(length % 2 != 0){
                cout << "Jumlah karakter ganjil, mohon tambah 1 karakter!" << endl;
                Sleep(3000);
                goto duakalidua;
            }
            cout << "Masukkan kunci: " << endl;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    cout << "- Baris " << i+1 << ", Kolom " << j+1 << ": ";
                    cin >> kunci[i][j];
                }
            }

            // Mencari determinan
            determinan = (kunci[0][0] * kunci[1][1]) - (kunci[0][1] * kunci[1][0]);
            if(determinan == 0 || determinan == 13 || determinan % 2 == 0){
                cout << endl << "Matriks kunci tidak memenuhi syarat. Proses enkripsi tidak dapat diteruskan!" << endl;
                return 0;
            }

            // Mencari matriks K baru
            temp = 0;
            while((determinan * temp) % 26 != 1){
                temp = temp + 1;
            }
            matrikstemp[0][0] = kunci[1][1];
            matrikstemp[0][1] = kunci[0][1] * (-1);
            matrikstemp[1][0] = kunci[1][0] * (-1);
            matrikstemp[1][1] = kunci[0][0];
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    kunci[i][j] = ma_mod((temp*matrikstemp[i][j]),26);
                }
            }

            // Proses dekripsi
            for(int i = 0; teks[i] != '\0'; ++i){
                if(i % 2 == 0){
                    nilai1 = int(teks[i]) - int('A');
                }
                else if(i % 2 != 0){
                    nilai2 = int(teks[i]) - int('A');
                    enkripsi1 = (kunci[0][0] * nilai1) + (kunci[0][1] * nilai2);
                    enkripsi2 = (kunci[1][0] * nilai1) + (kunci[1][1] * nilai2);
                    enkripsi1 = ma_mod(enkripsi1,26);
                    enkripsi2 = ma_mod(enkripsi2,26);
                    teks[i-1] = char(enkripsi1 + int('A'));
                    teks[i] = char(enkripsi2 + int('A'));
                }
            }
            cout << endl;
            cout << "Hasil dekripsi: " << teks << endl;
        }
        else if(pilihan == 3){ // Cari kunci
            string ciphertext, plaintext;
            float pinverse[2][2], matriksc[2][2], matriksp[2][2], matrikstemp[2][2];
            // Input plaintext dan ciphertext
            cout << "Plaintext  : ";
            cin >> plaintext;
            cout << "Ciphertext : ";
            cin >> ciphertext;

            // Mengisi matriks
            for(int i = 0; i < 2; i++){
                matriksc[i][0] = ciphertext[i] - int('A');
                matriksc[i][1] = ciphertext[i+2] - int('A');
            }
            for(int i = 0; i < 2; i++){
                matriksp[i][0] = plaintext[i] - int('A');
                matriksp[i][1] = plaintext[i+2] - int('A');
            }

            // Mencari determinan matriks P (plaintext)
            determinan = (matriksp[0][0] * matriksp[1][1]) - (matriksp[0][1] * matriksp[1][0]);

            // Mencari inverse matriks P
            matrikstemp[0][0] = matriksp[1][1];
            matrikstemp[0][1] = matriksp[0][1] * (-1);
            matrikstemp[1][0] = matriksp[1][0] * (-1);
            matrikstemp[1][1] = matriksp[0][0];
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    pinverse[i][j] = matrikstemp[i][j]/determinan;
                }
            }

            // Perkalian matriks C dan P inverse (belum di-mod 26)
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    kunci[i][j] = matriksc[i][0] * pinverse[0][j] + matriksc[i][1] * pinverse[1][j];
                }
            }

            // Matriks kunci di-mod 26
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    kunci[i][j] = ma_mod(kunci[i][j],26);
                }
            }

            // Menampilkan matriks
            cout << endl << "Matriks kunci yang dicari: " << endl;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    cout << kunci[i][j] << "\t";
                }
                cout << endl;
            }
        }
    }

    return 0;
}