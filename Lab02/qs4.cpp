#include <iostream>
using namespace std;

class safeArray{
	int* array;
	int size;
	
	public:
		safeArray(int s){
			size = s;
			array = new int[size];
		}
		
		void insert(int index, int val){
			if(index >= 0 && index < size){
				array[index] = val;
			}
			else{
				cout << "Invalid Index bro" << endl;
			}
				
		}
		
		void retrieve(int index){
			if(index >= 0 && index < size){
				cout << "Value at index " << index << ": " << array[index] << endl;
			}
			else{
				cout << "Invalid Index :{" << endl;
			}	
		}
		
		~safeArray(){
			delete [] array;
		}
};

int main(){
	int size, index, val;
	cout << "Enter size: ";
	cin >> size;
	
	safeArray arr(size);
	
	cout << "Enter index to insert value: ";
	cin >> index;
	cout << "Enter value to insert at that index: ";
	cin >> val;
	arr.insert(index, val);
	
	cout << "Enter index to insert value: ";
	cin >> index;
	cout << "Enter value to insert at that index: ";
	cin >> val;
	arr.insert(index, val);
	
	cout<< "Enter index to retrieve val: ";
	cin>> index;
	arr.retrieve(index);
	
}
