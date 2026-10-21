#include <iostream>
using namespace std;

int binaryLength(int n){
    int length = 0;

    do{
        length++;
        n = n / 2;
    }while(n > 0);

    return length;
}

void printBinary(int n, int bits){
    for(int i = bits - 1; i >= 0; i--){
        cout << ((n >> i) & 1);
    }
}

int setBits(int n){
    int count = 0;

    while(n > 0){
        if(n % 2 == 1)count++;
        n = n / 2;
    }

    return count;
}

void radixSort(int arr[], int n){
    int *output = new int[n];
    int maxValue = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > maxValue)maxValue = arr[i];
    }

    int bits = binaryLength(maxValue);

    for(int bit = 0; bit < bits; bit++){
        int zeroCount = 0, oneCount = 0;

        for(int i = 0; i < n; i++){
            if(((arr[i] >> bit) & 1) == 0)zeroCount++;
            else oneCount++;
        }

        int z = 0;
        int o = zeroCount;

        for(int i = 0; i < n; i++){
            if(((arr[i] >> bit) & 1) == 0){
                output[z] = arr[i];
                z++;
            }
            else{
                output[o] = arr[i];
                o++;
            }
        }

        for(int i = 0; i < n; i++)arr[i] = output[i];

        cout << "\n====================================" << endl;
        cout << "Pass " << bit + 1 << " - Bit Position " << bit;

        if(bit == 0)cout << " (LSB)";
        if(bit == bits - 1)cout << " (MSB)";

        cout << "\n====================================" << endl;
        cout << "Zeros: " << zeroCount << endl;
        cout << "Ones: " << oneCount << endl;

        cout << "Array in decimal: ";
        for(int i = 0; i < n; i++)cout << arr[i] << " ";
        cout << endl;

        cout << "Array in binary: ";
        for(int i = 0; i < n; i++){
            printBinary(arr[i], bits);
            cout << " ";
        }
        cout << endl;
    }

    delete[] output;
}

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n < 10){
        cout << "Enter at least 10 elements.";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter decimal integers: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] < 0){
            cout << "Enter non-negative integers only.";
            delete[] arr;
            return 0;
        }
    }

    cout << "\nBinary Representations:" << endl;

    int maxValue = arr[0];

    for(int i = 0; i < n; i++){
        if(arr[i] > maxValue)maxValue = arr[i];

        cout << arr[i] << " = ";
        printBinary(arr[i], binaryLength(arr[i]));
        cout << endl;
    }

    radixSort(arr, n);

    cout << "\n====================================" << endl;
    cout << "Final Sorted Array" << endl;
    cout << "====================================" << endl;

    int bits = binaryLength(maxValue);

    cout << "Decimal:" << endl;
    for(int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    cout << "\nBinary:" << endl;
    for(int i = 0; i < n; i++){
        printBinary(arr[i], bits);
        cout << " ";
    }
    cout << endl;

    int longest = arr[n - 1];

    cout << "\n====================================" << endl;
    cout << "Additional Analysis" << endl;
    cout << "====================================" << endl;

    cout << "Longest Binary Representation:" << endl;
    cout << longest << " = ";
    printBinary(longest, binaryLength(longest));
    cout << "\nLength = " << binaryLength(longest) << " bits" << endl;

    cout << "\nLargest Input Value:" << endl;
    cout << maxValue << " = ";
    printBinary(maxValue, binaryLength(maxValue));

    int maxSetBits = setBits(maxValue);

    cout << "\nNumber of set bits (1s): " << maxSetBits << endl;

    cout << "\nNumbers with the same number of set bits:" << endl;

    int count = 0;

    for(int i = 0; i < n; i++){
        if(setBits(arr[i]) == maxSetBits){
            cout << arr[i] << " ";
            count++;
        }
    }

    cout << "\nCount: " << count << endl;

    delete[] arr;

}

