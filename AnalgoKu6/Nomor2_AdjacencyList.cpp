/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Tanggal Buat    :   05 April 2020
Praktikum       :   Analisis Algoritma
Program         :   Adjacency List
Deskripsi       :   Nomor 2 - Program Undirected Graph for Adjacency List
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct AdjListNode{                  //Adjacency List Node
    int dest;
    struct AdjListNode* next;
};

struct AdjList{                      //Adjacency List
    struct AdjListNode *head;
};

class Graph{                        //Class Graph
    private:
        int V;
        struct AdjList* array;
    
    public:
        Graph(int V){
            this->V = V;
            array = new AdjList [V];
            for (int i=0; i<V; i++)
                array[i].head = NULL;
        }

        AdjListNode* newAdjListNode(int dest){          //Creating New Adjacency List Node
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }

        void addEdge(int src, int dest){                //Adding Edge to Graph
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        
        void printGraph(){                              //Print The Graph
            int v;
            for (v=1; v<=V; v++){
                AdjListNode* pCrawl = array[v].head;
                cout << "\n Adjacency list of vertex " << v << "\n head ";
                while (pCrawl){
                    cout << "-> " << pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout << endl;
            }
        }
};

int main(){
    Graph gh(8);

    cout << "\n===========================================\n";
	cout << "Program Undirected Graph for Adjacency List\n";
	cout << "===========================================\n";

    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
	gh.addEdge(2, 4);
    gh.addEdge(2, 5);
    gh.addEdge(2, 3);
    gh.addEdge(3, 7);
    gh.addEdge(3, 8);
    gh.addEdge(4, 5);
    gh.addEdge(5, 3);
    gh.addEdge(5, 6);
    gh.addEdge(7, 8);
    gh.printGraph();        //Print The Adjacency List Representation of The Above Graph

    return 0;
}