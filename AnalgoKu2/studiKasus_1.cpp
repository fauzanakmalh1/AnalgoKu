/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   10 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   studiKasus_1
Deskripsi       :   Studi Kasus 1 - Pencarian Nilai Maksimal
*/

#include <iostream>

using namespace std;

int main(){

	int x[100];
	int n;
	int i;
    int maks;

	cout << "\n================================\n";
	cout << "Program Pencarian Nilai Maksimal\n";
	cout << "================================\n";
	
	cout << "\nSilahkan Masukkan Jumlah Angka : "; cin >> n; cout << endl;
	for(i=0; i<n; i++){
		cout << "Masukkan Bilangan ke-" << i+1 << " : "; cin >> x[i];
	}
	
	maks = x[0];
    i = 2;
	
	for(int i=0; i<n; i++){
		if(x[i] > maks)
			maks = x[i];
	}

    while (i<n){
        if(x[i] > maks){
			maks = x[i];
		}
		i=i+1;
    }

	cout << "\nNilai Maksimalnya adalah : " << maks << endl;
}