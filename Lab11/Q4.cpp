#include <iostream>
using namespace std;
struct Node {
        char key[50];
        char value[50];
        Node* next;
    };
class HashTable {
    Node* table[10];

    int hashFunction(char key[]) {
        int sum = 0;

        for (int i = 0; key[i] != '\0'; i++)
            sum += key[i];

        return sum % 10;
    }

public:
    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    void insert(char key[], char value[]) {
        int index = hashFunction(key);

        Node* newNode = new Node;

        int i = 0;
        while (key[i] != '\0') {
            newNode->key[i] = key[i];
            i++;
        }
        newNode->key[i] = '\0';

        i = 0;
        while (value[i] != '\0') {
            newNode->value[i] = value[i];
            i++;
        }
        newNode->value[i] = '\0';

        newNode->next = NULL;

        if (table[index] == NULL) {
            table[index] = newNode;
        }
        else {
            Node* temp = table[index];

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";

            Node* temp = table[i];

            while (temp != NULL) {
                cout << "(" << temp->key << ", "
                     << temp->value << ") ";

                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert((char*)"A", (char*)"aaaaa");
    myhash.insert((char*)"B", (char*)"bbbbb");
    myhash.insert((char*)"C", (char*)"ccccc");
    myhash.insert((char*)"A", (char*)"zzzzz");

    myhash.display();

    return 0;
}
