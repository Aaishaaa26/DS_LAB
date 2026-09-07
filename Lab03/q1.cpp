#include <iostream>
#include <string>
using namespace std;


void swap(int times[], string activities[], int i, int j){
	int tempTimes = times[i];
	times[i] = times[j];
	times[j] = tempTimes;
	string tempAct = activities[i];
	activities[i] = activities[j];
	activities[j] = tempAct;
}
void activityTimes(int times[], string activities[], int n){
	char choice;
	cout<<"Do You want to know the spent on each activity too? (y/n): ";
	cin >> choice;
	if(choice == 'y'){
		for(int i = 0; i < n; i++){
			cout << "Activity Name: " << activities[i] <<"\tHours Spent: " << times[i]<<endl;
		}
	}

	cout<<endl;
}

void activityOnly(string activities[], int n){
		for(int i = 0; i < n; i++){
		cout << "Activity Name: " << activities[i] <<endl;
	}
	cout<<endl;
}
void bubbleSort(int time[], string activities[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(time[j] > time[j+1]){
				swap(time, activities, j, j+1);
			}
		}
	}
	activityOnly(activities,n); 
	activityTimes(time, activities, n);
}

void selectionSort(int time[], string activities[], int n){
	for(int i = 0;  i < n-1; i++){
		int min_index= i;
		for(int j = i+1; j < n; j++){
			if(time[min_index] > time[j]){
				min_index =j;
			}
		}
		swap(time, activities, min_index, i);
	}
	activityOnly(activities,n);
	activityTimes(time, activities, n);
}

void insertionSort(int times[], string activities[], int n){
	for(int i = 1; i < n; i++){
		int key = times[i];
		string temp = activities[i];
		int j = i-1;
		while(j >= 0 && times[j] > key){
			times[j+1] = times[j];
			activities[j+1] = activities[j];
			j--;
		}
		times[j+1] = key;
		activities[j+1] = temp;
	}
	activityOnly(activities,n);
	activityTimes(times, activities, n);
}

void shellSort(int times[], string activities[], int n){
	for(int gap = n/2; gap > 0; gap/=2){
		for(int i = gap; i < n; i++){
			int key = times[i];
			string temp = activities[i];
			int j = i;
			while(j >=gap && times[j - gap] > key){
				times[j] = times[j-gap];
				activities[j] = activities[j-gap];
				j-= gap;
			}
			times[j] = key;
			activities[j] = temp;
		}
	}
	activityOnly(activities,n);
	activityTimes(times, activities, n);
}

void combSort(int times[], string activities[], int n){
	int gap = n;
	bool swapping = true;
	
	while(gap!=1 || swapping){
		gap /=1.7;
		if(gap<1){
			gap = 1;
		}
		swapping = false;
		for(int i = 0; i+gap < n ; i++){
			if(times[i] > times[i+gap]){
				swap(times, activities, i, i+gap);
				swapping = true;
			}
		}
	}
	activityOnly(activities,n);
	activityTimes(times, activities, n);
}

void copy(int times[], string activities[], int orgTimes[], string orgActivites[],int n){
	for(int i = 0; i < n; i++){
		times[i] = orgTimes[i];
		activities[i]= orgActivites[i];
	}
}

void linearSearch(int times[], string activities[], int n){
	cout <<"Enter activity name to be searced: ";
	string name;
	cin.ignore();
	getline(cin, name);
	
	for(int i = 0; i < n; i++){
		if(activities[i] == name){
			char choice;
			cout << "Preference Found: " << activities[i]<< "\nWould You like to know the time spent on this activity?(y/n): ";
			cin>> choice;
			if(choice == 'y'){
				cout <<"Time spent: "<< times[i] << endl;
			}
			return;
		}
	}
	cout <<"Not Found..." <<endl;
	
}
void activitiesSort(int times[], string activities[], int n){
	for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(activities[j] > activities[j + 1]){
                swap(times, activities, j, j + 1);
            }
        }
    }

}
void binarySearch(int times[], string activities[], int n){
	cout <<"Enter activity name to be searced: ";
	string name;
	cin.ignore();
	getline(cin, name);
	activitiesSort(times, activities, n);
	int left = 0, right = n-1;
	while(left<= right){
		int mid = (left+right)/2;
		if(activities[mid] == name){
			char choice;
			cout << "Preference Found: " << activities[mid]<< "\nWould You like to know the time spent on this activity?(y/n): ";
			cin>> choice;
			if(choice == 'y'){
				cout <<"Time spent: "<< times[mid] << endl;
			}
			return;		
		}
		else if(activities[mid] < name){
			left = mid+1;
		}
		else{
			right = mid -1;
		}
	}
}

void interpolationSearch(int times[], string activities[], int n){
    cout <<"Enter activity name to be searced: ";
	string name;
	cin.ignore();
	getline(cin, name);
	activitiesSort(times, activities, n);
    int left = 0;
    int right = n - 1;

    while (left <= right){
        if (activities[left][0] == activities[right][0]){
            for (int i = left; i <= right; i++){
                if (activities[i] == name){
                    char choice;
                    cout << "Preference Found: " << activities[i] << endl;
                    cout << "Would you like to know the time spent on this activity? (y/n): ";
                    cin >> choice;

                    if (choice == 'y'){
                        cout << "Time spent: " << times[i] << " hours" << endl;
                    }

                    return;
                }
            }
            break;
        }
        int position = left + ((name[0] - activities[left][0]) * (right - left)) / (activities[right][0] - activities[left][0]);

        if (position < left || position > right){
            break;
        }

        if (activities[position] == name){
            char choice;
            cout << "Preference Found: " << activities[position] << endl;
            cout << "Would you like to know the time spent on this activity? (y/n): ";
            cin >> choice;

            if (choice == 'y'){
                cout << "Time spent: " << times[position] << " hours" << endl;
            }
            return;
        }
        if (activities[position] < name){
            left = position + 1;
        }
        else{
            right = position - 1;
        }
    }

    cout << "Not Found..." << endl;
}
void highestTime(int times[], string activities[], int n){
	int j = 0;
	for(int i = 1; i < n; i++){
		if(times[j] < times[i]){
			j = i;
		}
	}
	char choice;
	cout << "Most Time Spent On : " << activities[j]<< "\nWould You like to know the time spent on this activity?(y/n): ";
	cin>> choice;
	if(choice == 'y'){
		cout <<"Time spent: "<< times[j] << endl;
	}
}

int main(){
	
	int n;
	do{
		cout << "Enter Number of activities (Should be greater than = 7 and less than= 40): ";
		cin >> n;
	}while(n < 7 || n >40);

	cin.ignore();
	int orgTimes[n], times[n];
	string orgActivities[n], activities[n];
	for(int i = 0; i < n; i++){
		cout<<"Enter Activity #"<<i+1<<": ";
		getline(cin, orgActivities[i]);
		cout<<"Enter Hours Spent: ";
		cin>> orgTimes[i];
		cin.ignore();
	}
	cout<< endl;

	int choice;
	do{
		cout<< "\t_Sorting Menu_\n"<<"1. Bubble Sort\n"<<"2.selection Sort\n"<< "3. Insertion Sort\n"<<"4. Shell Sort\n"<<"5. Comb Sort\n" << "0. exit(any other index will result in exiting)\n"<< "Enter Index Choice: ";
		cin>> choice;
		copy(times, activities, orgTimes, orgActivities, n);
		switch (choice){
			case 1: bubbleSort(times, activities, n); break;
			case 2: selectionSort(times, activities, n); break;
			case 3: insertionSort(times, activities, n); break;
			case 4: shellSort(times, activities, n); break;
			case 5: combSort(times, activities, n); break;
			default: choice = 0;
		}
	
	}while(choice != 0);
	highestTime(orgTimes, orgActivities, n);	
	do{
		copy(times, activities, orgTimes, orgActivities, n);
		cout <<"\t_Searching Menu_\n1.Linear Search\n2.Binary Search\n3.Interpolation Search\n0.exit(any other index will result in exiting)\nENter Coice: ";
		cin>> choice;
		switch(choice){
			case 1: linearSearch(times, activities, n); break;
			case 2: binarySearch(times, activities, n); break;
			case 3: interpolationSearch(times, activities, n); break;
			default: choice = 0; break;
		}	
	}while(choice != 0);
	
}

