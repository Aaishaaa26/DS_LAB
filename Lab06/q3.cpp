#include <iostream>
using namespace std;
void funcB(int n,int limit);
void funcA(int n,int limit){
	if(n >  limit) return;
	cout <<n<< endl;
	funcB(n+1, limit);
}
void funcB(int n,int limit){
	if(n > limit) return;
	cout <<n<< endl;
	funcA(n+1, limit);
}

int main(){
	int limit;
	do{
		cout<<"Number starting from 0 u want to print(only positive): ";
		cin>>limit;
	}while(limit <= 0);

	funcA(0, limit);
}
