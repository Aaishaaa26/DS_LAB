#include <iostream>
#include <string>
using namespace std;

void linearSearch(int ranks[], string position[], int n){
	cout<<"Enter rank: ";
	int key;
	cin >> key;
	for(int i = 0; i < n; i++){
		if(ranks[i] == key){
			cout<<"Position: " << position[i]<< endl;
			return;
		}
	}
	cout <<"Invalid."<< endl;
}
void binarySearch(int ranks[], string position[], int n){
	
	cout<<"Enter rank: ";
	int key;
	cin >> key;
	
	int low = 0, high = n-1;
	while(low <=high){
		int mid = (high+low)/2;
		if(ranks[mid] == key){
			cout<<"Position: " << position[mid] << endl;
			return;			
		}
		else if(ranks[mid] < key){
			low = mid+1;
		}
		else{
			high = mid -1;
		}
	}
	cout << "Invalid." << endl;
}
void interpolationSearch(int ranks[], string position[], int n) {

	cout<<"Enter rank: ";
	int key;
	cin >> key;
	    
	int low = 0, high = n - 1;
    while (low <= high && key >= ranks[low] && key <= ranks[high]) {
        if (low == high) {
            if (ranks[low] == key) cout<<"Position: " << position[low] << endl;
        return;
        }
        int pos = low + (((double)(high - low) / (ranks[high] - ranks[low])) * (key - ranks[low]));
        if (ranks[pos] == key){
        	cout<<"Position: " << position[pos] << endl; return;
		} 
        else if (ranks[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    cout << "Invalid."<< endl;
}	
int main() {
    int ranks[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    string positions[9] = {
        "AI Engineer",
        "Machine Learning Engineer",
        "Software Engineer",
        "Data Scientist",
        "Data Engineer",
        "Cloud Engineer",
        "Cybersecurity Engineer",
        "DevOps Engineer",
        "Project Manager"
    };
	//im in 3rd sem
	cout <<"Industry. do u want to know the rzn? (y/n): ";
	char choice;
	cin>> choice;
	if(choice == 'y'){
		cout<<"How would ik, its js a lab task (ps. leave me alone)"<< endl;
	}
	int opt;
	do{

		cout<<"1.Linear Search\n2.Binary Search\n3.Interpolation Search\n0.exit\nENter choice index (any other key will lead to exiting.. btw they are 9 ranks): ";
		cin >> opt;
		switch(opt){
			case 1: linearSearch(ranks,positions, 9); break;
			case 2: binarySearch(ranks, positions, 9); break;
			case 3: interpolationSearch(ranks, positions, 9); break;
			default: opt = 0; break;
		} 
	}while(opt != 0);
}
