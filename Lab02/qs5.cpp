#include <iostream>
using namespace std;

int main(){
	int classes;
	cout << "Enter Num of classes: ";
	cin >> classes;
	
	int** marks = new int* [classes];
	int*  std = new int[classes];
	
	for(int i = 0; i< classes; i++){
		cout << "Enter Num of students in class "<< i+1 << ": ";
		cin >> std[i];
		
		marks[i] = new int[std[i]];
	}
	for(int i = 0; i < classes; i++){
		for (int j = 0; j < std[i]; j ++){
			cout << "class " << i+1 << ", student " << j +1 << ": ";
			cin >> marks[i][j];
		}
	}
	int sum;
	double avg; 
	
	cout << "\n_______________MARKS__________" << endl;
	for(int  i = 0; i < classes; i++){
		sum = 0;
		
		for(int j = 0; j < std[i]; j++){
			cout << "class " << i+1 << ", student " << j +1 << ": " << marks[i][j] << endl;
			sum = marks[i][j];
		}
		avg  = (double)sum / std[i];
		
		cout << "\nAvg: " << avg << endl; 
	}
	
	for( int i = 0; i < classes; i++){
		delete[] marks[i];
	}
	delete[] marks;
	delete[] std;
}
