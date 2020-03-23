/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   23 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Selection Sort
Deskripsi       :   Studi Kasus 2 - Selection Sort
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort (int arr[], int n){
	int i;
	int j;
	for (i=0; i<n; i++){
		for (j=i+1; j<n; j++){
			if (arr[i] > arr[j]){
				arr[i]=arr[i]+arr[j];
				arr[j]=arr[i]-arr[j];
				arr[i]=arr[i]-arr[j];
			}	
		}
	}	
}	

int main(){
	int n;
	int i;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

	cout << "\n======================\n";
	cout << "Program Selection Sort\n";
	cout << "======================\n";
	
	cout << "\nSilahkan Masukkan Jumlah Elemen Data yang Ingin Diurutkan: "; cin >> n; cout << "\n";

	int arr[n];
	for(i=0; i<n; i++){
		cout << "Masukkan Elemen ke-" << i+1 << ": "; cin >> arr[i];
	}

	selectionSort(arr, n);

	cout<<"\nArray yang Telah Diurutkan: ";
	for (i=0; i<n; i++){
		cout<<" "<<arr[i];
	}
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "\n\nDurasi Waktu: " << duration << " microseconds\n";
}