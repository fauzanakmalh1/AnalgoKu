/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   30 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Tilling Problem
Deskripsi       :   Studi Kasus 5 - Tilling Problem - Permasalahan Tata Letak Keramik Lantai
*/

// C++ implementation to count number of ways to 
// tile a floor of size n x m using 1 x m tiles 
#include <bits/stdc++.h> 

using namespace std; 

// function to count the total number of ways 
int countWays(int n, int m){ 
	// table to store values 
	// of subproblems 
	int count[n + 1]; 
	count[0] = 0; 

	// Fill the table upto value n 
	for (int i=1; i<=n; i++){ 
		// recurrence relation 
		if (i > m){ 
			count[i] = count[i - 1] + count[i - m]; 
		}
		// base cases 
		else if (i < m){ 
			count[i] = 1; 
		}
		// i = = m 
		else{
			count[i] = 2; 
		}
	} 
	// required number of ways 
	return count[n]; 
} 

// Driver program to test above 
int main(){
	int n;
	int m;

	cout << "\n=======================\n";
	cout << "Program Tilling Problem\n";
	cout << "=======================\n\n";

	cout << "Masukkan Angka 1 (Contoh: 2): "; cin >> n;
	cout << "Masukkan Angka 2 (Contoh: 2): "; cin >> m;

	cout << "\nNumber of Ways = " << countWays(n, m) << endl;
	return 0; 
}