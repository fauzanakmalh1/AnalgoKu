/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   30 Maret 2020
Praktikum       :   Analisis Algoritma
Program         :   Closest Pair of Points
Deskripsi       :   Studi Kasus 5 - Mencari Pasangan Titik Terdekat (Closest Pair of Points)
*/

#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Point{  
    public: 
    int x;
	int y;  
};  

int compareX(const void* a, const void* b){  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->x - p2->x);  
}

int compareY(const void* a, const void* b){  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->y - p2->y);  
}  

float dist(Point p1, Point p2){  
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));  
}

float bruteForce(Point P[], int n){  
    float min = FLT_MAX;  
    for (int i=0; i<n; i++){ 
        for (int j=i+1; j<n; j++){ 
            if (dist(P[i], P[j]) < min){
                min = dist(P[i], P[j]);
			}
		}
	}  
    return min;  
}  

float min(float x, float y){  
    return (x < y)? x : y;  
}  

float stripClosest(Point strip[], int size, float d){  
    float min = d; //Inisiasi jarak minimum = d 

    qsort(strip, size, sizeof(Point), compareY);
    
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size && (strip[j].y-strip[i].y)<min; j++){
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
			}
		}  
	}
    return min;  
}  

float closestUtil(Point P[], int n){  
    //Jika ada 2 atau 3 points, gunakan brute force
    if (n <= 3){
        return bruteForce(P, n);
	}
    
	int mid = n/2;  
    Point midPoint = P[mid];  

    float dl = closestUtil(P, mid);  
    float dr = closestUtil(P + mid, n - mid);
    float d = min(dl, dr);  

    Point strip[n];
    
    int j = 0;  
    for (int i=0; i<n; i++)  
        if (abs(P[i].x - midPoint.x) < d)  
            strip[j] = P[i], j++;
            
    return min(d, stripClosest(strip, j, d) );  
}  

float closest(Point P[], int n){  
    qsort(P, n, sizeof(Point), compareX);  

    return closestUtil(P, n);  
}  

int main(){
	int n;
	
	cout << "\n==============================\n";
	cout << "Program Closest Pair of Points\n";
	cout << "==============================\n";

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    n = sizeof(P) / sizeof(P[0]);
    
    cout << "\nP[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}\n\n";
    cout << "Jarak Terkecil: "<<closest(P, n);  
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "\n\nDurasi Waktu: " << duration << " microseconds\n";
}