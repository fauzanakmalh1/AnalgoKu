/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   10 Maret 2020
Mata Kuliah     :   Analisis Algoritma
Program         :   studiKasus_4
Deskripsi       :   Studi Kasus 4 - Insertion Sort
*/

#include <iostream>

using namespace std;

int data1[100];
int data2[100];
int n;

void insertion_sort(){
	
	int temp;

	for(int i=1; i<=n; i++){
		temp = data1[i];
		int j = i-1;
		while(data1[j]>temp && j>=0){
			data1[j+1] = data1[j];
			j--;
		}
		data1[j+1] = temp;
	}
}

int main(){
	
	cout << "\n======================\n";
	cout << "Program Insertion Sort\n";
	cout << "======================\n";

	cout << "\nSilahkan Masukkan Banyak Data : "; cin >> n; cout <<endl;
	
	for(int i=1; i<=n; i++){
		cout << "Masukkan Data ke-" << i << " : "; cin >> data1[i];
		data2[i]=data1[i];
	}
	
	insertion_sort();
	cout << "\nData yang Telah di Sort : " << endl;
	for(int i=1; i<=n; i++){
		cout << data1[i] << " ";
	}
	cout << endl;

	return 0;
}