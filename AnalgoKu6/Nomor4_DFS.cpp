/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   05 April 2020
Praktikum       :   Analisis Algoritma
Program         :   Depth First Search
Deskripsi       :   Nomor 4 - Program Depth First Search
*/

#include <iostream>
#include <list>

using namespace std;

class Graph{
	int N;

	list<int> *adj;

	void DFSUtil(int u, bool visited[]){
		visited[u] = true;
		cout << u << " ";

		list<int>::iterator i;
		for(i = adj[u].begin(); i != adj[u].end(); i++){
			if(!visited[*i]){
				DFSUtil(*i, visited);
            }
		}
	}

    public :
	Graph(int N){
		this->N = N;
		adj = new list<int>[N];
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
	}

	void DFS(int u){
		bool *visited = new bool[N];
		for(int i = 0; i < N; i++){
			visited[i] = false;
        }
		DFSUtil(u, visited);
	}
};

int main(){
	Graph g(8);

    cout << "\n==========================\n";
	cout << "Program Depth First Search\n";
	cout << "==========================\n";

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(3,7);
	g.addEdge(3,8);
	g.addEdge(4,5);
	g.addEdge(5,3);
	g.addEdge(5,6);
	g.addEdge(7,8);

	cout << "\nDFS Traversal Starts from Node 1" << endl;
	g.DFS(1);

	return 0;
}