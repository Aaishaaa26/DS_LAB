#include <iostream>
using namespace std;

int main(){
	int std, subj;
	
	cout<<"Enter Number Of Students: ";
	cin>> std;
	cout << "Enter Number Of subjects: ";
	cin >> subj;
	
	int **marks = new int*[std];
	for(int i = 0; i < std; i++){
		marks[i] = new int[subj];
	}
	
	for (int i = 0; i < std; i++){
		for (int j = 0; j < subj; j++){
			cout << "Enter Marks for student " << i+1 << ", subject " << j+1<< ": ";
			cin>> marks[i][j];
		}
	}
	
	int newStd, newSubj;
	
	cout<<"Enter Number Of Students now (new+old):";
	cin>> newStd;
	cout << "Enter Number Of subjects now (new+old)";
	cin >> newSubj;	
	
	int **newMarks = new int*[newStd];
	for(int i = 0; i < newStd; i++){
		newMarks[i] = new int[newSubj];
	}
	
	for(int i = 0; i < std; i++){
   		 for(int j = 0; j < subj; j++){
    	    newMarks[i][j] = marks[i][j];
    	}
	}
	for(int i = 0; i < newStd; i++){
    	for(int j = 0; j < newSubj; j++){

        	if(i < std && j < subj)
            	continue;

        	cout << "Enter marks for student " << i+1
            	 << ", subject " << j+1<< ": ";

        	cin >> newMarks[i][j];
    	}
	}
	
	
	for (int i = 0; i < std; i++){
        delete[] marks[i];
    }

    delete[] marks;

    marks = newMarks;
    std = newStd;
    subj = newSubj;

   for (int i = 0; i < std; i++){
        for (int j = 0; j < subj; j++){
            cout << marks[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < std; i++){
        delete[] marks[i];
    }

    delete[] marks;

}
