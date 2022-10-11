/*
	NPM		: 140810200028
	Nama	: Ananda Shaquille Farell
	MK		: Kriptografi (Praktikum)
	Hal		: Program Vigenere Cipher
*/
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

// Untuk men-generate key
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// Untuk enkripsi
string cipherText(string str, string key)
{
	string ciphertext;

	for (int i = 0; i < str.size(); i++)
	{
		char x = (str[i] + key[i]) %26;

		x += 'A';

		ciphertext.push_back(x);
	}
	return ciphertext;
}

// Untuk dekripsi
string plainText(string ciphertext, string key)
{
	string plaintext;

	for (int i = 0 ; i < ciphertext.size(); i++)
	{
		char x = (ciphertext[i] - key[i] + 26) %26;

		x += 'A';
		plaintext.push_back(x);
	}
	return plaintext;
}

int main()
{
	int pilihan;
	char menu;
	string ciphertext, key, keyword, plaintext, str;

	menu:
	system("CLS");
	cout << "+-------------------------+" << endl;
	cout << "| PROGRAM VIGENERE CIPHER |" << endl;
	cout << "+-------------------------+" << endl;
	cout << "Pilihan:" << endl;
	cout << "1. Enkripsi" << endl;
	cout << "2. Dekripsi" << endl;
	cout << "0. Exit" << endl;
	cout << "Pilihan Anda: ";
	cin >> pilihan;
	cout << endl;

	if(pilihan == 0){
		system("CLS");
		return 0;
	}
	else if(pilihan == 1){
		cout << "= ENKRIPSI =" << endl;
		cout << "Plaintext      : ";
		cin >> str;
		cout << "Key            : ";
		cin >> keyword;

		key = generateKey(str, keyword);
		ciphertext = cipherText(str, key);

		cout << "Hasil enkripsi : " << ciphertext << endl;

		cout << endl << "Kembali ke menu? (Y/N)" << endl;
		cout << "Pilihan Anda: ";
		cin >> menu;
		if(menu == 'Y' || menu == 'y'){
			system("CLS");
			goto menu;
		}
		else if(menu == 'N' || menu == 'n'){
			system("CLS");
			return 0;
		}
	}
	else if(pilihan == 2){
		cout << "= DEKRIPSI =" << endl;
		cout << "Ciphertext     : ";
		cin >> str;
		cout << "Key            : ";
		cin >> keyword;

		key = generateKey(str, keyword);
		plaintext = plainText(str, key);

		cout << "Hasil dekripsi : " << plaintext << endl;

		cout << endl << "Kembali ke menu? (Y/N)" << endl;
		cout << "Pilihan Anda: ";
		cin >> menu;
		if(menu == 'Y' || menu == 'y'){
			system("CLS");
			goto menu;
		}
		else if(menu == 'N' || menu == 'n'){
			system("CLS");
			return 0;
		}
	}

	return 0;
}
