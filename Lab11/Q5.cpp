#include <iostream>
using namespace std;

class Dictionary {
    struct Node {
        char key[50];
        char value[50];
        Node* next;
    };

    Node* table[100];

    int hashFunction(char key[]) {
        int sum = 0;

        for (int i = 0; key[i] != '\0'; i++)
            sum += key[i];

        return sum % 100;
    }

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    void Add_Record(char key[], char value[]) {
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

        newNode->next = table[index];
        table[index] = newNode;
    }

    void Word_Search(char key[]) {
        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp != NULL) {
            int i = 0;

            while (key[i] == temp->key[i] && key[i] != '\0')
                i++;

            if (key[i] == '\0' && temp->key[i] == '\0') {
                cout << "Search key " << key << ": " << temp->value << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Record not found!" << endl;
    }

    void Delete_Record(char key[]) {
        int index = hashFunction(key);

        Node* temp = table[index];
        Node* previous = NULL;

        while (temp != NULL) {
            int i = 0;

            while (key[i] == temp->key[i] && key[i] != '\0')
                i++;

            if (key[i] == '\0' && temp->key[i] == '\0') {
                if (previous == NULL)
                    table[index] = temp->next;
                else
                    previous->next = temp->next;

                delete temp;
                cout << "Key " << key << " deleted successfully!" << endl;
                return;
            }

            previous = temp;
            temp = temp->next;
        }

        cout << "Record not found!" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            Node* temp = table[i];

            while (temp != NULL) {
                cout << "Index " << i << ": (" << temp->key
                     << ", " << temp->value << ")" << endl;

                temp = temp->next;
            }
        }
    }
};

int main() {
    Dictionary d;

    d.Add_Record((char*)"AB", (char*)"FASTNU");
    d.Add_Record((char*)"CD", (char*)"CS");
    d.Add_Record((char*)"EF", (char*)"AI");

    d.Word_Search((char*)"AB");

    d.Delete_Record((char*)"EF");

    d.Print_Dictionary();

    return 0;
}
