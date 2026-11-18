#include <iostream>
using namespace std;

const int MAX = 10;
const int MAXE = 20;

struct Edge{
	char u, v;
	int weight;
};

class Graph{
	int vertices;
	char nodes[MAX];
	Edge edges[MAXE];
	int edgeCount;
	
	int findIndex(char ch){
		for(int i = 0; i < vertices; i++){
			if(nodes[i] == ch) return i;
		}
		return -1;
	}
	
	int findParent(int parent[], int v){
		while(parent[v] != v){
			v = parent[v];
		}
		return v;
	}
	
	public:
		Graph(char nodesList[], int v){
			vertices = v;
			edgeCount = 0;
			
			for(int i = 0; i < vertices; i++){
				nodes[i] = nodesList[i];
			}
		}
		
		void addEdges(char ch1, char ch2, int weight){
			if(findIndex(ch1) == -1 || findIndex(ch2) == -1)
				return;
			
			edges[edgeCount].u = ch1;
			edges[edgeCount].v = ch2;
			edges[edgeCount].weight = weight;
			edgeCount++;
		}
		
		void Kruskal(){
			for(int i = 0; i < edgeCount - 1; i++){
				for(int j = 0; j < edgeCount - i - 1; j++){
					if(edges[j].weight > edges[j+1].weight){
						Edge temp = edges[j];
						edges[j] = edges[j+1];
						edges[j+1] = temp;
					}
				}
			}
			
			int parent[MAX];
			
			for(int i = 0; i < vertices; i++){
				parent[i] = i;
			}
			
			int count = 0;
			int total = 0;
			
			cout << "Minimum Spanning Tree:" << endl;
			
			for(int i = 0; i < edgeCount; i++){
				int u = findIndex(edges[i].u);
				int v = findIndex(edges[i].v);
				
				int p1 = findParent(parent, u);
				int p2 = findParent(parent, v);
				
				if(p1 != p2){
					cout << edges[i].u << " - " << edges[i].v;
					cout << " : " << edges[i].weight << endl;
					
					parent[p1] = p2;
					
					total += edges[i].weight;
					count++;
				}
				
				if(count == vertices - 1){
					break;
				}
			}
			
			if(count != vertices - 1){
				cout << "Graph is not connected!" << endl;
			}
			else{
				cout << "Minimum Cost: " << total << endl;
			}
		}
};

int main(){
	

	char a[] = {'a', 'b', 'c', 'd', 'e'};
	Graph g1(a, 5);
	
	g1.addEdges('a', 'c', 10);
	g1.addEdges('c', 'a', 21);
	g1.addEdges('a', 'd', 22);
	g1.addEdges('b', 'c', 53);
	g1.addEdges('b', 'e', 45);
	g1.addEdges('c', 'e', 33);
	g1.addEdges('e', 'd', 19);
	
	cout << "Graph A" << endl;
	g1.Kruskal();
	

	char b[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	Graph g2(b, 6);
	
	g2.addEdges('A', 'B', 3);
	g2.addEdges('A', 'C', 5);
	g2.addEdges('A', 'D', 9);
	g2.addEdges('B', 'C', 3);
	g2.addEdges('B', 'D', 4);
	g2.addEdges('B', 'E', 7);
	g2.addEdges('C', 'D', 2);
	g2.addEdges('C', 'E', 6);
	g2.addEdges('C', 'F', 8);
	g2.addEdges('D', 'E', 2);
	g2.addEdges('D', 'F', 2);
	g2.addEdges('E', 'F', 5);
	
	cout << "\nGraph B" << endl;
	g2.Kruskal();

}

