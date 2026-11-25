#include <iostream>
using namespace std;

class Heap {
    int arr[100];
    int size;
    bool maxMode;

    bool higher(int a, int b) {
        if (maxMode)
            return a > b;
        return a < b;
    }

    void heapifyDown(int i) {
        int best = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && higher(arr[left], arr[best]))
            best = left;

        if (right < size && higher(arr[right], arr[best]))
            best = right;

        if (best != i) {
            swap(arr[i], arr[best]);
            heapifyDown(best);
        }
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (higher(arr[i], arr[parent])) {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapifyArray(int a[], int n, int i) {
        int best = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[best])
            best = left;

        if (right < n && a[right] > a[best])
            best = right;

        if (best != i) {
            swap(a[i], a[best]);
            heapifyArray(a, n, best);
        }
    }

public:
    Heap(int a[], int n, bool mode) {
        size = n;
        maxMode = mode;

        for (int i = 0; i < size; i++)
            arr[i] = a[i];

        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void deleteValue(int value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << value << " not found!" << endl;
            return;
        }

        arr[index] = arr[size - 1];
        size--;

        if (index < size) {
            if (index > 0 && higher(arr[index], arr[(index - 1) / 2]))
                heapifyUp(index);
            else
                heapifyDown(index);
        }
    }

    void heapSort() {
        int a[100];
        int n = size;

        for (int i = 0; i < n; i++)
            a[i] = arr[i];

        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyArray(a, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapifyArray(a, i, 0);
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main() {
    int arr[] = {25, 30, 35, 11, 15, 19, 18, 55, 78, 36};
    int n = 10;

    Heap maxHeap(arr, n, true);

    cout << "Max-Heap:" << endl;
    maxHeap.display();

    maxHeap.deleteValue(55);

    cout <<endl<< "Max-Heap after deleting 55:" << endl;
    maxHeap.display();

    Heap minHeap(arr, n, false);

    cout << "\nMin-Heap:" << endl;
    minHeap.display();

    minHeap.deleteValue(18);

    cout <<endl<< "Min-Heap after deleting 18:" << endl;
    minHeap.display();

    Heap sortHeap(arr, n, true);

    cout << "\nHeap Sort:" << endl;
    sortHeap.heapSort();

    return 0;
}
