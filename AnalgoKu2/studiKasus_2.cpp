/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   10 Maret 2020
Mata Kuliah     :   Analisis Algoritma
Program         :   studiKasus_2
Deskripsi       :   Studi Kasus 2 - Sequential Search
*/

#include <iostream>

using namespace std;

int main(){
    
	int n;
	int A[100]; 
	int cari; 
	int index;
	bool found = false;

	cout << "\n=========================\n";
	cout << "Program Sequential Search\n";
	cout << "=========================\n";

	cout << "\nSilahkan Masukkan Banyak Data :  "; cin >> n; cout <<endl;
	
	for(int i=0; i<n; i++){
		cout << "Masukkan Data ke-" << i+1 << " : "; cin >> A[i];
	}
	
	cout << "\nMasukkan Data yang Dicari : "; cin >> cari; cout << endl;

	for(int i=0; i<n; i++){
		if(A[i] == cari){
			found = true;
			index = i;
			i = n;
		}
	}
	
	if(found == true){
		cout << "Data Ditemukan Pada Data ke-" << index+1 << endl;
	}
	else{
		cout << "Maaf, Data yang Anda Cari Tidak Ditemukan!\n";
	}

	return 0;
}