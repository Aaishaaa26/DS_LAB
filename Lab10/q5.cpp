#include <iostream>
using namespace std;

const int MAX = 6;
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

    void printPath(int parent[], int v){
        if(parent[v] == -1){
            cout << nodes[v];
            return;
        }

        printPath(parent, parent[v]);
        cout << " -> " << nodes[v];
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

        void addEdge(char ch1, char ch2, int weight){
            int i = findIndex(ch1);
            int j = findIndex(ch2);

            if(i == -1 || j == -1) return;

            adj[i][j] = weight;
        }

        void Dijkstra(char start){
            bool visited[MAX] = {false};
            int dist[MAX];
            int parent[MAX];

            int s = findIndex(start);

            if(s == -1) return;

            for(int i = 0; i < vertices; i++){
                dist[i] = INF;
                parent[i] = -1;
            }

            dist[s] = 0;

            for(int count = 0; count < vertices; count++){

                int min = INF;
                int u = -1;

                for(int i = 0; i < vertices; i++){
                    if(!visited[i] && dist[i] < min){
                        min = dist[i];
                        u = i;
                    }
                }

                if(u == -1) break;

                visited[u] = true;

                for(int i = 0; i < vertices; i++){
                    if(adj[u][i] != 0 && !visited[i]){
                        if(dist[u] + adj[u][i] < dist[i]){
                            dist[i] = dist[u] + adj[u][i];
                            parent[i] = u;
                        }
                    }
                }
            }

            cout << "Shortest Paths from " << start << endl;

            for(int i = 0; i < vertices; i++){

                cout << "\nDepartment " << nodes[i] << endl;

                if(dist[i] == INF){
                    cout << "Path: Unreachable" << endl;
                    cout << "Total Cost: Infinity" << endl;
                }
                else{
                    cout << "Path: ";
                    printPath(parent, i);

                    cout << endl;
                    cout << "Total Cost: " << dist[i] << endl;
                }
            }
        }
};

int main(){

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    Graph g(nodes, 6);

    g.addEdge('A', 'B', 4);
    g.addEdge('A', 'C', 2);
    g.addEdge('B', 'C', 5);
    g.addEdge('B', 'D', 10);
    g.addEdge('C', 'E', 3);
    g.addEdge('E', 'D', 4);
    g.addEdge('D', 'F', 11);

    g.Dijkstra('A');

}

