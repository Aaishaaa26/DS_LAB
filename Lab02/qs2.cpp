#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter number of product prices u wanna add: ";
	cin >> n;
	
	int* prices = new int[n];
	
	for(int i = 0; i < n; i++){
		cout << "Enter price for product " << i +1<< " : ";
		cin >> prices[i];
	}
	
	int newSize;
	cout << "Enter new Size : ";
	cin >> newSize;
	
	int * newPrices = new int[newSize];

	for (int i = 0; i< n; i ++){
		newPrices[i] = prices[i];
	}
	
	for(int i = n; i < newSize; i++){
		cout <<"Enter price for product " << i +1<< " : ";
		cin >> newPrices[i];
	}
	delete [] prices;
	prices = newPrices;
	
	cout<<"\n_______Displaying Product Prices______"<< endl;
	for(int i = 0; i < newSize; i++){
		cout << "Product " << i+1 << " prices: " << prices[i] << endl;
	}
}
