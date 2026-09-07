#include <iostream>
#include <string>
using namespace std;

struct course{
	int code;
	string classNum;
	string tchName;
	string time;
};

int linearsearch(course tt[], int n){
	int comparisions = 0;
	int key;
	cout << "Enter course code to search: ";
	cin >> key;
	for(int i = 0; i < n; i++){
		comparisions++;
		if(tt[i].code == key){
			cout <<"Course Code: " << tt[i].code <<"\nClassRoom: " << tt[i].classNum <<"\nTeacher Name: " << tt[i].tchName << "\nTiming: " << tt[i].time<< endl;
			return comparisions;
		}
	}
	cout<<"not found." << endl;;
	return comparisions;
}
int binarysearch(course tt[], int n){
	int comparisions = 0;
	int key;
	cout << "Enter course code to search: ";
	cin >> key;
	int low = 0, high = n - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		comparisions++;
		if(tt[mid].code == key){
			cout <<"Course Code: " << tt[mid].code <<"\nClassRoom: " << tt[mid].classNum <<"\nTeacher Name: " << tt[mid].tchName << "\nTiming: " << tt[mid].time<< endl;
			return comparisions;
		}
		else if(tt[mid].code < key){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	cout<<"not found." << endl;;
	return comparisions;
}
int interpolationsearch(course tt[], int n){
	int comparisions = 0;
	int key;
	cout << "Enter course code to search: ";
	cin >> key;
	int low = 0, high = n - 1;
	while(low <= high && key >= tt[low].code && key <= tt[high].code){
		if(low == high){
			comparisions++;
			if(tt[low].code == key){
				cout <<"Course Code: " << tt[low].code <<"\nClassRoom: " << tt[low].classNum <<"\nTeacher Name: " << tt[low].tchName << "\nTiming: " << tt[low].time<< endl;
				return comparisions;
			}
			break;
		}
		int pos = low + (((double)(high - low) / (tt[high].code - tt[low].code)) * (key - tt[low].code));
		comparisions++;
		if(tt[pos].code == key){
			cout <<"Course Code: " << tt[pos].code <<"\nClassRoom: " << tt[pos].classNum <<"\nTeacher Name: " << tt[pos].tchName << "\nTiming: " << tt[pos].time<< endl;
			return comparisions;
		}
		else if(tt[pos].code < key){
			low = pos + 1;
		}
		else{
			high = pos - 1;
		}
	}
	cout<<"not found." << endl;;
	return comparisions;
}

int main(){
	course sortedTimetable[6]={ {101, "e32", "Sir Sameer", "9-10"}, {102, "r12", "Ms Rabia", "10-11"},{103, "d28", "Ms Mehak", "8-9"}, {104, "a5", "Sir Amjad", "12-1"},{105, "b9", "Sir Abdur Rahman", "1-2"}, {106, "lab06","sir jahanzaib", "2-4"}};
	course unsortedTimetable[6] = {{104, "a5", "Sir Amjad", "12-1"},{101, "e32", "Sir Sameer", "9-10"},{106, "lab06", "sir jahanzaib", "2-4"},{103, "d28", "Ms Mehak", "8-9"},{102, "r12", "Ms Rabia", "10-11"},{105, "b9", "Sir Abdur Rahman", "1-2"}};
    course &uniformTimetable = *sortedTimetable;
    int result;

	cout << "\tUnsorted Timetable\n";
	cout << "Linear Search:\n";
	result = linearsearch(unsortedTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "\tSorted Timetable\n";
	cout << "Linear Search:\n";
	result = linearsearch(sortedTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "Binary Search:\n";
	result = binarysearch(sortedTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "Interpolation Search:\n";
	result = interpolationsearch(sortedTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "\tUniformly Distributed Timetable\n";
	cout << "Linear Search:\n";
	result = linearsearch(&uniformTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "Binary Search:\n";
	result = binarysearch(&uniformTimetable, 6);
	cout << "Comparisions: " << result << endl;

	cout << "\nInterpolation Search:\n";
	result = interpolationsearch(&uniformTimetable, 6);
	cout << "Comparisions: " << result << endl;
    
}
