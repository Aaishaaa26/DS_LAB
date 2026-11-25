#include <iostream>
using namespace std;

class DataItem {
public:
    string name;
    int priority;

    DataItem() {
        name = "";
        priority = 0;
    }

    DataItem(string n, int p) {
        name = n;
        priority = p;
    }
};

class MaxHeap {
private:
    DataItem arr[100];
    int size;

    void swap(DataItem &a, DataItem &b) {
        DataItem temp = a;
        a = b;
        b = temp;
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && arr[left].priority > arr[largest].priority)
            largest = left;

        if(right < size && arr[right].priority > arr[largest].priority)
            largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(DataItem item) {
        arr[size] = item;
        int i = size;
        size++;

        while(i > 0 && arr[(i - 1) / 2].priority < arr[i].priority) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void deleteRoot() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Deleted Item: " << arr[0].name;
        cout << " Priority: " << arr[0].priority << endl;

        arr[0] = arr[size - 1];
        size--;

        if(size > 0)
            heapifyDown(0);
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << "Name: " << arr[i].name;
            cout << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    MaxHeap h;

    h.insert(DataItem("Item A", 5));
    h.insert(DataItem("Item B", 8));
    h.insert(DataItem("Item C", 3));
    h.insert(DataItem("Item D", 10));
    h.insert(DataItem("Item E", 6));
    h.insert(DataItem("Item F", 7));

    cout << "Original Max Heap:" << endl;
    h.display();

    cout << endl;

    h.deleteRoot();

    cout << endl;

    cout << "Updated Max Heap:" << endl;
    h.display();

    return 0;
}
