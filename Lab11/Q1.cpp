#include <iostream>
using namespace std;

class Parcel {
public:
    char name[50];
    int rating;

    Parcel() {
        name[0] = '\0';
        rating = 0;
    }

    Parcel(const char n[], int r) {
        int i = 0;

        while(n[i] != '\0') {
            name[i] = n[i];
            i++;
        }

        name[i] = '\0';
        rating = r;
    }
};

class MinHeap {
private:
    Parcel arr[100];
    int size;

    void swap(Parcel &a, Parcel &b) {
        Parcel temp = a;
        a = b;
        b = temp;
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && arr[left].rating < arr[smallest].rating)
            smallest = left;

        if(right < size && arr[right].rating < arr[smallest].rating)
            smallest = right;

        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {
        size = 0;
    }

    void insert(Parcel p) {
        arr[size] = p;
        int i = size;
        size++;

        while(i > 0 && arr[(i - 1) / 2].rating > arr[i].rating) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << arr[i].name << " - Rating: " << arr[i].rating << endl;
        }
    }

    void displaySorted() {
        MinHeap temp = *this;

        while(temp.size > 0) {
            cout << temp.arr[0].name << " - Rating: "
                 << temp.arr[0].rating << endl;

            temp.arr[0] = temp.arr[temp.size - 1];
            temp.size--;

            if(temp.size > 0)
                temp.heapifyDown(0);
        }
    }
};

int main() {
    MinHeap h;

    h.insert(Parcel("Laptop", 1));
    h.insert(Parcel("Books", 3));
    h.insert(Parcel("Mobile", 2));
    h.insert(Parcel("Clothes", 5));
    h.insert(Parcel("Documents", 4));

    h.insert(Parcel("Medicine", 2));

    cout << "Heap Structure:" << endl;
    h.display();

    cout << endl;

    cout << "Sorted Dispatch Order:" << endl;
    h.displaySorted();

    return 0;
}
