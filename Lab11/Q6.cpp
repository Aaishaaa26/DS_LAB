#include <iostream>
#include <list>
using namespace std;

class Hash {
    list<int> table[10];

    int hashFunction(int key) {
        return key % 10;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteKey(int key) {
        int index = hashFunction(key);

        for (list<int>::iterator i = table[index].begin();
             i != table[index].end(); i++) {

            if (*i == key) {
                table[index].erase(i);
                cout << key << " deleted successfully!" << endl;
                return;
            }
        }

        cout << key << " not found!" << endl;
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key) {
                cout << key << " found!" << endl;
                return;
            }
        }

        cout << key << " not found!" << endl;
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << i << ": ";

            for (int value : table[i])
                cout << value << " -> ";

            cout << "NULL" << endl;
        }
    }
};

int main() {
    Hash h;

    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(12);
    h.insert(22);

    cout << "Hash Table:" << endl;
    h.display();

	cout<<"\nSearch:"<<endl;
    h.search(25);
    h.search(50);
	cout<<"\nDelete:"<<endl;
    h.deleteKey(25);

    cout << "\nUpdated Hash Table:" << endl;
    h.display();

    return 0;
}
