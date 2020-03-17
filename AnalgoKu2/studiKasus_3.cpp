/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   10 Maret 2020
Mata Kuliah     :   Analisis Algoritma
Program         :   studiKasus_3
Deskripsi       :   Studi Kasus 3 - Binary Search
*/

#include <iostream>

using namespace std;

int main(){
	
	int n;
	int arr[100]; 
	int cari;
	int awal;
	int akhir; 
	int tengah;

	cout << "\n=====================\n";
	cout << "Program Binary Search\n";
	cout << "=====================\n";

	cout << "\nSilahkan Masukkan Banyak Data : "; cin >> n; cout << endl;
	for (int i=0; i<n; i++){
		cout << "Masukkan Data ke-" << i+1 << " : "; cin >> arr[i];
	}

	cout << "\nMasukkan Data yang Dicari : "; cin >> cari; cout << endl;
	
	awal = 0;
	akhir = n-1;
	while (awal <= akhir){
		tengah = (awal+akhir)/2;
		if(arr[tengah] < cari){
			awal = tengah + 1;
		}
		else if(arr[tengah] == cari){
			cout << "Data Ditemukan Pada Data ke-" << tengah+1 << endl;
			break;
		}
		else{
			akhir = tengah - 1;
		}
		tengah = (awal + akhir)/2;
	}
	if(awal > akhir){
		cout << "Maaf, Data yang Anda Cari Tidak Ditemukan!\n";
	}
	
	return 0;
}