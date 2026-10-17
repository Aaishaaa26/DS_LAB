#include <iostream>
using namespace std;

const int N = 4;

int maze[N][N] ={
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};
int solution[N][N] = {0};
int count = 0;

bool isSafe(int row, int col){
    if(row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 1) return true;
    return false;
}

void displaySolution(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << solution[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solveMaze(int row, int col){
    if(!isSafe(row, col)) return;

    solution[row][col] = 1;

    if(row == N-1 && col == N-1){
        count++;
        cout << "Path " << count << ":" << endl;
        displaySolution();
        solution[row][col] = 0;
        return;
    }

    solveMaze(row+1, col);
    solveMaze(row, col+1);

    solution[row][col] = 0;
}

int main(){
    solveMaze(0, 0);
    cout << "Total paths: " << count;

}

