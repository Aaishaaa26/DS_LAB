#include <iostream>
using namespace std;

int count = 1, start = 1;

void sequenceB(int n, int count, int start);
void sequenceA(int n, int count, int start){
	if(count> n){
		cout<< start<< endl;
		return;
	}
 	cout << start<<", ";
 	count++;
 	sequenceB(n, count, start+count);
}
void sequenceB(int n, int count, int start){
	if(count> n){
		cout<< start<< endl;
		return;
	}
 	cout << start<<", ";
 	count++;
 	sequenceA(n, count, start+count);
}

int main(){
	sequenceA(6,count,start);
}
