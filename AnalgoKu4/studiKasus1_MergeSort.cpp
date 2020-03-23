/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   23 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Merge Sort
Deskripsi       :   Studi Kasus 1 - Merge Sort
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge (int *a, int low, int high, int mid){
	int i;
	int j;
	int k;
	int temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high){
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}
		else{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high){
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++){
		a[i] = temp[i-low];
	}
}

void mergeSort(int *a, int low, int high){
	int mid;
	if (low < high){
		mid=(low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low, high, mid);
	}
}

int main(){
	int n;
	int i;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	cout << "\n==================\n";
	cout << "Program Merge Sort\n";
	cout << "==================\n";
	
	cout << "\nSilahkan Masukkan Jumlah Elemen Data yang Ingin Diurutkan: "; cin >> n; cout << "\n";

	int arr[n];
	for(i=0; i<n; i++){
		cout << "Masukkan Elemen ke-" << i+1 << ": "; cin >> arr[i];
	}

	mergeSort(arr, 0, n-1);

	cout << "\nArray yang Telah Diurutkan: ";
	for (i=0; i<n; i++){
		cout << " " << arr[i];
	}
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "\n\nDurasi Waktu: " << duration << " microseconds\n";
}