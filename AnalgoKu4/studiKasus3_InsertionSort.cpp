/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   23 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Insertion Sort
Deskripsi       :   Studi Kasus 3 - Insertion Sort
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct list {
	int data;
	list *next;
};

list* InsertinList(list *head, int n){
	list *newnode = new list;
	list *temp = new list;

	newnode->data = n;
	newnode->next = NULL;

	if(head == NULL){
		head = newnode;
		return head;
	}
	else {
		temp = head;

		if(newnode->data < head->data){
			newnode->next = head;
			head = newnode;
			return head;
		}

		while(temp->next != NULL){
			if(newnode->data < (temp->next)->data) {
				break;
			}
			temp=temp->next;
		}

		newnode->next = temp->next;
		temp->next = newnode;
		return head;
	}	
}	

int main(){
	int n;
	int i;
	int num;
	list *head = new list;
	head = NULL;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	cout << "\n======================\n";
	cout << "Program Insertion Sort\n";
	cout << "======================\n";
	
	cout << "\nSilahkan Masukkan Jumlah Elemen Data yang Ingin Diurutkan: "; cin >> n; cout << "\n";

	for(i=0; i<n; i++){
		cout<<"Masukkan Elemen ke-" << i+1 << ": "; cin>>num;
		head = InsertinList(head, num);
	}

	cout<<"\nArray yang Telah Diurutkan: ";
	while(head != NULL){
		cout << " " << head->data;
		head = head->next;
	}
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "\n\nDurasi Waktu: " << duration << " microseconds\n";
}