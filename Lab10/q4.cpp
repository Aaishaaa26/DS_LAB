#include <iostream>
using namespace std;

const int MAX = 6;

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
                    adj[i][j] = 0;
                }
            }
        }

        void addEdge(char ch1, char ch2, int weight){
            int i = findIndex(ch1);
            int j = findIndex(ch2);

            if(i == -1 || j == -1){
                cout << "Invalid department" << endl;
                return;
            }

            adj[i][j] = weight;

            cout << "Edge inserted successfully" << endl;
        }

        void deleteEdge(char ch1, char ch2){
            int i = findIndex(ch1);
            int j = findIndex(ch2);

            if(i == -1 || j == -1){
                cout << "Invalid department" << endl;
                return;
            }

            if(adj[i][j] == 0){
                cout << "Edge does not exist" << endl;
                return;
            }

            adj[i][j] = 0;

            cout << "Edge deleted successfully" << endl;
        }

        void displayMatrix(){
            cout << "\nAdjacency Matrix:\n\n";

            cout << "  ";

            for(int i = 0; i < vertices; i++){
                cout << nodes[i] << " ";
            }

            cout << endl;

            for(int i = 0; i < vertices; i++){
                cout << nodes[i] << " ";

                for(int j = 0; j < vertices; j++){
                    cout << adj[i][j] << " ";
                }

                cout << endl;
            }
        }

        void displayEdges(){
            for(int i = 0; i < vertices; i++){

                cout << "\nDepartment " << nodes[i] << endl;

                cout << "Outgoing Edges: ";

                bool found = false;

                for(int j = 0; j < vertices; j++){
                    if(adj[i][j] != 0){
                        cout << nodes[i] << " -> " << nodes[j];
                        cout << " (" << adj[i][j] << ") ";
                        found = true;
                    }
                }

                if(!found) cout << "None";

                cout << endl;

                cout << "Incoming Edges: ";

                found = false;

                for(int j = 0; j < vertices; j++){
                    if(adj[j][i] != 0){
                        cout << nodes[j] << " -> " << nodes[i];
                        cout << " (" << adj[j][i] << ") ";
                        found = true;
                    }
                }

                if(!found) cout << "None";

                cout << endl;
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

    int choice;
    char u, v;
    int weight;

    do{
        cout << "\n1. Insert Edge";
        cout << "\n2. Delete Edge";
        cout << "\n3. Display Adjacency Matrix";
        cout << "\n4. Display Incoming and Outgoing Edges";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter source department: ";
                cin >> u;

                cout << "Enter destination department: ";
                cin >> v;

                cout << "Enter communication cost: ";
                cin >> weight;

                g.addEdge(u, v, weight);
                break;

            case 2:
                cout << "Enter source department: ";
                cin >> u;

                cout << "Enter destination department: ";
                cin >> v;

                g.deleteEdge(u, v);
                break;

            case 3:
                g.displayMatrix();
                break;

            case 4:
                g.displayEdges();
                break;

            case 5:
                cout << "Program ended";
                break;

            default:
                cout << "Invalid choice";
        }

    }while(choice != 5);

}

