
#include <iostream>
using namespace std;

const int MAX = 10;

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
	
	void dfs_check(int v, bool visited[]){
		visited[v] = true;
		cout << nodes[v] << " ";
		
		for(int i = 0; i < vertices; i++){
			if(adj[v][i] == 1 && !visited[i]){
				dfs_check(i, visited);
			}
		}
	}
	
	public:
		Graph(char nodesList[], int v){
			vertices = v;
			
			for(int i = 0; i < vertices; i++){
				nodes[i] = nodesList[i];
				for(int j = 0; j < vertices; j++){
					adj[i][j] = 0;
				}
			}
		}
		
		void addEdges(char ch1, char ch2, bool directed){
			int i = findIndex(ch1);
			int j = findIndex(ch2);
			
			if(i == -1 || j == -1) return;
			
			adj[i][j] = 1;
			
			if(!directed) adj[j][i] = 1;
		}
		
		void BFS(char start){
			bool visited[MAX] = {false};
			int queue[100];
			int f = 0, r = 0;
			
			int s = findIndex(start);
			if(s == -1) return;
			
			visited[s] = true;
			queue[r++] = s;
			
			cout << "BFS: ";
			
			while(f < r){
				int current = queue[f++];
				cout << nodes[current] << " ";
				
				for(int i = 0; i < vertices; i++){
					if(adj[current][i] == 1 && !visited[i]){
						visited[i] = true;
						queue[r++] = i;
					}
				}
			}
			
			cout << endl;
		}
		
		void DFS(char start){
			bool visited[MAX] = {false};
			
			int s = findIndex(start);
			if(s == -1) return;
			
			cout << "DFS: ";
			dfs_check(s, visited);
			
			cout << endl;
		}
};

int main(){

	char a[] = {'a', 'b', 'c', 'd', 'e'};
	Graph g1(a, 5);
	
	g1.addEdges('a', 'b', true);
	g1.addEdges('a', 'c', true);
	g1.addEdges('a', 'd', true);
	g1.addEdges('a', 'e', true);
	g1.addEdges('b', 'd', true);
	g1.addEdges('c', 'd', true);
	g1.addEdges('c', 'e', true);
	g1.addEdges('d', 'e', true);
	
	cout << "\nGraph A\n";
	g1.BFS('a');
	g1.DFS('a');

	char b[] = {'1', '2', '3', '4', '5', '6', '7'};
	Graph g2(b, 7);
	
	g2.addEdges('1', '2', true);
	g2.addEdges('1', '4', true);
	g2.addEdges('2', '3', true);
	g2.addEdges('2', '5', true);
	g2.addEdges('3', '7', true);
	g2.addEdges('4', '6', true);
	g2.addEdges('6', '5', true);
	g2.addEdges('5', '7', true);
	g2.addEdges('6', '7', true);
	
	cout << "\nGraph B\n";
	g2.BFS('1');
	g2.DFS('1');

	char c[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	Graph g3(c, 6);
	
	g3.addEdges('A', 'B', true);
	g3.addEdges('A', 'C', true);
	g3.addEdges('C', 'B', true);
	g3.addEdges('C', 'D', true);
	g3.addEdges('C', 'E', true);
	g3.addEdges('D', 'E', true);
	g3.addEdges('B', 'F', true);
	g3.addEdges('E', 'F', true);
	
	cout << "\nGraph C\n";
	g3.BFS('A');
	g3.DFS('A');

	Graph g4(c, 6);
	
	g4.addEdges('A', 'B', true);
	g4.addEdges('A', 'C', true);
	g4.addEdges('C', 'B', true);
	g4.addEdges('C', 'D', true);
	g4.addEdges('C', 'E', true);
	g4.addEdges('D', 'E', true);
	g4.addEdges('B', 'F', true);
	g4.addEdges('E', 'F', true);
	
	cout << "\nGraph D\n";
	g4.BFS('A');
	g4.DFS('A');

	char e[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	Graph g5(e, 8);
	
	g5.addEdges('H', 'A', true);
	g5.addEdges('A', 'B', true);
	g5.addEdges('A', 'D', true);
	g5.addEdges('B', 'C', true);
	g5.addEdges('B', 'F', true);
	g5.addEdges('C', 'D', false);
	g5.addEdges('C', 'E', true);
	g5.addEdges('C', 'G', true);
	g5.addEdges('C', 'H', true);
	g5.addEdges('D', 'F', false);
	g5.addEdges('E', 'B', true);
	g5.addEdges('E', 'F', true);
	g5.addEdges('F', 'A', true);
	g5.addEdges('G', 'E', true);
	g5.addEdges('G', 'H', true);
	
	cout << "\nGraph E\n";
	g5.BFS('A');
	g5.DFS('A');

	char f[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
	Graph g6(f, 8);
	
	g6.addEdges('0', '1', true);
	g6.addEdges('0', '2', true);
	g6.addEdges('0', '3', true);
	g6.addEdges('1', '3', true);
	g6.addEdges('2', '4', true);
	g6.addEdges('3', '5', true);
	g6.addEdges('3', '6', true);
	g6.addEdges('4', '5', true);
	g6.addEdges('4', '7', true);
	g6.addEdges('5', '2', true);
	
	cout << "\nGraph F\n";
	g6.BFS('0');
	g6.DFS('0');

	char gg[] = {'0', '1', '3', '4', '5', '6', '7'};
	Graph g7(gg, 7);
	
	g7.addEdges('0', '1', false);
	g7.addEdges('0', '3', false);
	g7.addEdges('0', '7', true);
	g7.addEdges('1', '4', true);
	g7.addEdges('7', '4', true);
	g7.addEdges('7', '5', true);
	g7.addEdges('3', '5', true);
	g7.addEdges('4', '6', true);
	g7.addEdges('5', '6', true);
	
	cout << "\nGraph G\n";
	g7.BFS('0');
	g7.DFS('0');

	char h[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	Graph g8(h, 8);
	
	g8.addEdges('H', 'A', false);
	g8.addEdges('H', 'C', false);
	g8.addEdges('H', 'G', false);
	g8.addEdges('A', 'B', false);
	g8.addEdges('A', 'D', false);
	g8.addEdges('A', 'F', false);
	g8.addEdges('B', 'C', false);
	g8.addEdges('B', 'F', false);
	g8.addEdges('B', 'E', false);
	g8.addEdges('C', 'G', false);
	g8.addEdges('C', 'E', false);
	g8.addEdges('D', 'F', false);
	g8.addEdges('F', 'E', false);
	g8.addEdges('E', 'G', false);
	
	cout << "\nGraph H\n";
	g8.BFS('A');
	g8.DFS('A');
}

