#include <iostream>
using namespace std;

const int MAX = 10;

class Graph{
    int vertices;
    int adj[MAX][MAX];

    public:

        Graph(int v){
            vertices = v;

            for(int i = 0; i < vertices; i++){
                for(int j = 0; j < vertices; j++){
                    adj[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v){
            adj[u][v] = 1;
        }

        void topologicalSort(){
            int indegree[MAX] = {0};

            for(int i = 0; i < vertices; i++){
                for(int j = 0; j < vertices; j++){
                    if(adj[i][j] == 1){
                        indegree[j]++;
                    }
                }
            }

            cout << "Indegrees:" << endl;

            for(int i = 0; i < vertices; i++){
                cout << i << " : " << indegree[i] << endl;
            }

            int queue[MAX];
            int f = 0, r = 0;

            for(int i = 0; i < vertices; i++){
                if(indegree[i] == 0){
                    queue[r++] = i;
                }
            }

            int count = 0;

            cout << "\nTopological Order: ";

            while(f < r){
                int current = queue[f++];

                cout << current << " ";
                count++;

                for(int i = 0; i < vertices; i++){
                    if(adj[current][i] == 1){
                        indegree[i]--;

                        if(indegree[i] == 0){
                            queue[r++] = i;
                        }
                    }
                }
            }

            cout << endl;

            if(count != vertices){
                cout << "Cycle detected, No valid topological ordering exists" << endl;
            }
            else{
                cout << "Valid topological ordering generated" << endl;
            }
        }
};

int main(){

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);

    g.topologicalSort();

}

