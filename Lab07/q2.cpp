#include <iostream>
using namespace std;

int count[100] = {0};

void printArray(int arr[], int low, int high){
    cout << "[ ";
    for(int i = low; i <= high; i++)cout << arr[i] << " ";
    cout << "]" << endl;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    for(int i = 0; i < n1; i++)left[i] = arr[low + i];
    for(int i = 0; i < n2; i++)right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void sortArray(int arr[], int low, int high, int level){
    if(low >= high)return;

    cout << "\nLevel: " << level << endl;

    if(level % 2 == 1){
        cout << "Technique: Quick Sort Partition" << endl;

        int pivot = arr[high];
        cout << "Pivot: " << pivot << endl;

        int p = partition(arr, low, high);

        if(low < p){
            cout << "Left subarray: ";
            printArray(arr, low, p - 1);
            count[level]++;
        }

        cout << "Pivot position: " << arr[p] << endl;

        if(p < high){
            cout << "Right subarray: ";
            printArray(arr, p + 1, high);
            count[level]++;
        }

        cout << "Subarrays generated at level " << level
             << ": " << count[level] << endl;

        sortArray(arr, low, p - 1, level + 1);
        sortArray(arr, p + 1, high, level + 1);
    }
    else{
        cout << "Technique: Merge Sort Division" << endl;

        int mid = (low + high) / 2;

        cout << "Left subarray: ";
        printArray(arr, low, mid);
        count[level]++;

        cout << "Right subarray: ";
        printArray(arr, mid + 1, high);
        count[level]++;

        cout << "Subarrays generated at level " << level
             << ": " << count[level] << endl;

        sortArray(arr, low, mid, level + 1);
        sortArray(arr, mid + 1, high, level + 1);

        merge(arr, low, mid, high);

        cout << "Merged subarray: ";
        printArray(arr, low, high);
    }
}

int main(){
    int n;

    cout << "Enter number of product IDs (at least 20): ";
    cin >> n;

    if(n < 20){
        cout << "Enter at least 20 product IDs.";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter product IDs: ";
    for(int i = 0; i < n; i++)cin >> arr[i];

    sortArray(arr, 0, n - 1, 1);

    cout << "\nFinal sorted product IDs: ";
    printArray(arr, 0, n - 1);

    cout << "\nTotal subarrays generated at each level:" << endl;

    for(int i = 1; i < 100; i++){
        if(count[i] > 0){
            cout << "Level " << i << ": " << count[i] << endl;
        }
    }

    delete[] arr;

}

