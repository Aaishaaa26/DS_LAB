#include <iostream>
using namespace std;

int count = 1, start = 1;

void sequence(int n, int count, int start){
	if(count> n){
		cout<< start<< endl;
		return;
	}
 	cout << start<<", ";
 	count++;
 	sequence(n, count, start+count);
}

int main(){
	sequence(6,count,start);
}
