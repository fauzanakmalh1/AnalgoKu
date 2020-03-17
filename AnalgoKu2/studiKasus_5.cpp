/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   10 Maret 2020
Mata Kuliah     :   Analisis Algoritma
Program         :   studiKasus_5
Deskripsi       :   Studi Kasus 5 - Selection Sort
*/

#include <iostream>

using namespace std;

int data1[100];
int data2[100];
int n;

void tukar(int a, int b){
	int t;
	t = data1[b];
	data1[b] = data1[a];
	data1[a] = t;
}

void selection_sort(){
	int pos;
	int i;
	int j;
	for(i=1; i<=n-1; i++){
		pos = i;
		for(j = i+1;j<=n;j++){
			if(data1[j] < data1[pos]){ 
				pos = j;
			}
		}
        if(pos != i){
			tukar(pos, i);
		}
    }
}

int main(){
	
	cout << "\n======================\n";
	cout << "Program Selection Sort\n";
	cout << "======================\n";

	cout << "\nSilahkan Masukkan Banyak Data : "; cin >> n; cout <<endl;

	for(int i=1; i<=n; i++){
		cout << "Masukkan Data ke-" << i << " : "; cin >> data1[i];
		data2[i]=data1[i];
	}
	
	selection_sort();
	cout << "\nData yang Telah di Sort : " << endl;
	for(int i=1; i<=n; i++){
		cout << data1[i] << " ";
	}
	cout << endl;

	return 0;
}