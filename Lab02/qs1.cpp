#include <iostream>
using namespace std;

int main(){
	int marks[10], highest = 0, lowest = 100, aboveAverage, total =0;
	cout<<"Enter Marks for 10 std: "<< endl;
	
	for(int i = 0; i < 10; i++){
		cin>> marks[i];
		total += marks[i];
		if(marks[i]> highest){
			highest = marks[i];
		}
		else if(marks[i] < lowest){
			lowest = marks[i];
		}
	}
	double avg = total/10.0;
	cout << "All marks: "<< endl;
	for (int i = 0; i < 10; i++){
		cout << "Student " << i+1 << " Marks: " << marks[i] << endl;
		if( marks[i] > avg){
			aboveAverage++;
		}
	}
	
	cout<< "Class avg: " << avg << endl << "Student count above avg: " << aboveAverage << endl << "Highest Marks: " << highest << endl << "lowest Marks: " << lowest << endl;
	
}
