
#include <iostream>
using namespace std;

int quickCount = 0;
int mergeCount = 0;

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    cout << "\nSelected pivot: " << pivot << endl;

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

    int p = i + 1;

    if(low < p){
        cout << "Left subarray: [ ";
        for(int j = low; j < p; j++)cout << arr[j] << " ";
        cout << "]" << endl;
        quickCount++;
    }

    cout << "Pivot: " << arr[p] << endl;

    if(p < high){
        cout << "Right subarray: [ ";
        for(int j = p + 1; j <= high; j++)cout << arr[j] << " ";
        cout << "]" << endl;
        quickCount++;
    }

    return p;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
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

    cout << "Merged subarray: [ ";
    for(int x = low; x <= high; x++)cout << arr[x] << " ";
    cout << "]" << endl;

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        cout << "\nDividing subarray: [ ";
        for(int i = low; i <= high; i++)cout << arr[i] << " ";
        cout << "]" << endl;

        cout << "Left subarray: [ ";
        for(int i = low; i <= mid; i++)cout << arr[i] << " ";
        cout << "]" << endl;

        cout << "Right subarray: [ ";
        for(int i = mid + 1; i <= high; i++)cout << arr[i] << " ";
        cout << "]" << endl;

        mergeCount += 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main(){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if(n < 10){
        cout << "Enter at least 10 elements.";
        return 0;
    }

    int *original = new int[n];
    int *quick = new int[n];
    int *merged = new int[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> original[i];
        quick[i] = original[i];
        merged[i] = original[i];
    }

    cout << "\nquick Sort:" << endl;

    quickSort(quick, 0, n - 1);

    cout << "\nSorted array: [ ";
    for(int i = 0; i < n; i++)cout << quick[i] << " ";
    cout << "]" << endl;

    cout << "Total subarrays generated: " << quickCount << endl;

    cout << "MergeSort:" << endl;

    mergeSort(merged, 0, n - 1);

    cout << "\nSorted array: [ ";
    for(int i = 0; i < n; i++)cout << merged[i] << " ";
    cout << "]" << endl;

    cout << "Total subarrays generated during division: "
         << mergeCount << endl;

    delete[] original;
    delete[] quick;
    delete[] merged;

    return 0;
}

