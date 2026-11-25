#include <iostream>
using namespace std;

class StudentHashTable {
    struct Student {
        int rollNumber;
        char name[50];
        bool occupied;
    };

    Student table[15];

    int hashFunction(int rollNumber) {
        return rollNumber % 15;
    }

public:
    StudentHashTable() {
        for (int i = 0; i < 15; i++)
            table[i].occupied = false;
    }

    void InsertRecord(int rollNumber, char name[]) {
        int index = hashFunction(rollNumber);

        for (int attempt = 0; attempt < 15; attempt++) {
            int position = (index + attempt * attempt) % 15;

            if (table[position].occupied &&
                table[position].rollNumber == rollNumber) {

                int i = 0;
                while (name[i] != '\0') {
                    table[position].name[i] = name[i];
                    i++;
                }
                table[position].name[i] = '\0';

                cout << "Record updated!" << endl;
                return;
            }

            if (!table[position].occupied) {
                table[position].rollNumber = rollNumber;

                int i = 0;
                while (name[i] != '\0') {
                    table[position].name[i] = name[i];
                    i++;
                }
                table[position].name[i] = '\0';

                table[position].occupied = true;

                cout << "Record inserted!" << endl;
                return;
            }
        }

        cout << "No available position!" << endl;
    }

    void SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);

        for (int attempt = 0; attempt < 15; attempt++) {
            int position = (index + attempt * attempt) % 15;

            if (!table[position].occupied) {
                cout << "Record not found!" << endl;
                return;
            }

            if (table[position].rollNumber == rollNumber) {
                cout << "Student Name: "
                     << table[position].name << endl;
                return;
            }
        }

        cout << "Record not found!" << endl;
    }
};

int main() {
    StudentHashTable students;
	
	cout<<"Inseration :"<<endl;
    students.InsertRecord(101, (char*)"Aaisha");
    students.InsertRecord(116, (char*)"Repanzul");
    students.InsertRecord(131, (char*)"Elsa");
    students.InsertRecord(102, (char*)"Anna");
	
	cout<<"\nSearch :"<<endl;
    students.SearchRecord(101);
    students.SearchRecord(131);
    students.SearchRecord(200);

    return 0;
}
