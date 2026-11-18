#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 9999;

class Graph{
	int vertices;
	char nodes[MAX];
	int adj[MAX][MAX];
	
	int findIndex(char ch){
		for(int i = 0; i < vertices; i++){
			if(nodes[i] == ch) return i;
		}
		return -1;
	}
	
	public:
		Graph(char nodesList[], int v){
			vertices = v;
			
			for(int i = 0; i < vertices; i++){
				nodes[i] = nodesList[i];
				for(int j = 0; j < vertices; j++){
					adj[i][j] = INF;
				}
			}
		}
		
		void addEdges(char ch1, char ch2, int weight){
			int i = findIndex(ch1);
			int j = findIndex(ch2);
			
			if(i == -1 || j == -1) return;
			
			adj[i][j] = weight;
			adj[j][i] = weight;
		}
		
		void Prim(char start){
			bool visited[MAX] = {false};
			int key[MAX];
			int parent[MAX];
			int s = findIndex(start);
			
			if(s == -1) return;
			
			for(int i = 0; i < vertices; i++){
				key[i] = INF;
				parent[i] = -1;
			}
			
			key[s] = 0;
			
			int total = 0;
			
			cout << "Minimum Spanning Tree:" << endl;
			
			for(int count = 0; count < vertices; count++){
				int min = INF;
				int u = -1;
				
				for(int i = 0; i < vertices; i++){
					if(!visited[i] && key[i] < min){
						min = key[i];
						u = i;
					}
				}
				
				if(u == -1){
					cout << "Graph is not connected!" << endl;
					return;
				}
				
				visited[u] = true;
				
				if(parent[u] != -1){
					cout << nodes[parent[u]] << " - " << nodes[u];
					cout << " : " << adj[parent[u]][u] << endl;
					
					total += adj[parent[u]][u];
				}
				
				for(int i = 0; i < vertices; i++){
					if(adj[u][i] != INF && !visited[i] && adj[u][i] < key[i]){
						key[i] = adj[u][i];
						parent[i] = u;
					}
				}
			}
			
			cout << "Minimum Cost: " << total << endl;
		}
};

int main(){

	char a[] = {'0', '1', '2', '3', '4'};
	Graph g1(a, 5);
	
	g1.addEdges('0', '1', 3);
	g1.addEdges('0', '3', 7);
	g1.addEdges('0', '4', 8);
	g1.addEdges('1', '2', 1);
	g1.addEdges('1', '3', 4);
	g1.addEdges('2', '3', 2);
	g1.addEdges('3', '4', 3);
	
	cout << "Graph A\n" ;
	g1.Prim('0');

	char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	Graph g2(b, 7);
	
	g2.addEdges('A', 'B', 1);
	g2.addEdges('A', 'D', 5);
	g2.addEdges('B', 'D', 3);
	g2.addEdges('B', 'C', 4);
	g2.addEdges('C', 'E', 7);
	g2.addEdges('D', 'E', 1);
	g2.addEdges('D', 'G', 4);
	g2.addEdges('E', 'G', 2);
	g2.addEdges('E', 'F', 1);
	g2.addEdges('G', 'F', 10);
	
	cout << "\nGraph B\n";
	g2.Prim('A');
	
	return 0;
}

