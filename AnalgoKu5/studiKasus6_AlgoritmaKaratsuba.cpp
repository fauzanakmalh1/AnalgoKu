/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   30 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Algoritma Karatsuba
Deskripsi       :   Studi Kasus 5 - Algoritma Karatsuba untuk Menyelesaikan Problem Fast Multiplication
*/

#include <iostream>
#include <chrono>
#include <stdio.h> 

using namespace std;
using namespace std::chrono;

int makeEqualLength(string &str1, string &str2){ 
	int len1 = str1.size(); 
	int len2 = str2.size(); 
	if (len1 < len2){ 
		for (int i=0 ; i<len2-len1 ; i++){ 
			str1 = '0' + str1;
        }
		return len2; 
	} 
	else if (len1 > len2){ 
		for (int i=0 ; i<len1-len2 ; i++){ 
			str2 = '0' + str2;
        }
	}
	return len1; // If len1 >= len2 
} 

string addBitStrings( string first, string second ){ 
	string result;

	int length = makeEqualLength(first, second); 
	int carry = 0;

	for (int i=length-1 ; i>=0 ; i--){ 
		int firstBit = first.at(i) - '0'; 
		int secondBit = second.at(i) - '0'; 

		int sum = (firstBit ^ secondBit ^ carry) + '0'; 

		result = (char)sum + result;

		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
	}

	if (carry) result = '1' + result; 

	return result; 
}

int multiplyiSingleBit(string a, string b){
    return (a[0] - '0')*(b[0] - '0');
} 

long int multiply(string X, string Y){
	int n = makeEqualLength(X, Y); 

	if (n == 0) return 0; 
	if (n == 1) return multiplyiSingleBit(X, Y); 

	int fh = n/2;
	int sh = (n-fh);

	string Xl = X.substr(0, fh); 
	string Xr = X.substr(fh, sh); 

	string Yl = Y.substr(0, fh); 
	string Yr = Y.substr(fh, sh); 

	long int P1 = multiply(Xl, Yl); 
	long int P2 = multiply(Xr, Yr); 
	long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 

	return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 

int main(){
    string string1;
	string string2;
	
	cout << "\n=========================================\n";
	cout << "    Program Algoritma Karatsuba untuk\n";
	cout << "Menyelesaikan Problem Fast Multiplication\n";
	cout << "=========================================\n";
	
	cout << "\nMasukkan String 1 (Contoh: 1100): "; cin >> string1;
	cout << "Masukkan String 2 (Contoh: 1010): "; cin >> string2;
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout << "\nHasil Kali: " << multiply(string1, string2);
	
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "\n\nDurasi Waktu: " << duration << " microseconds\n";
}