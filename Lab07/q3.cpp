#include <iostream>
using namespace std;

int digitSum(int n){
    int sum = 0;

    while(n > 0){
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

void radixSort(int arr[], int n){
    int *output = new int[n];

    int place = 1;

    for(int pass = 1; pass <= 4; pass++){
        int count[10] = {0};

        for(int i = 0; i < n; i++){
            int digit = (arr[i] / place) % 10;
            count[digit]++;
        }

        int evenCount = 0;

        for(int i = 0; i < n; i++){
            int digit = (arr[i] / place) % 10;

            if(digit % 2 == 0)evenCount++;
        }

        for(int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for(int i = n - 1; i >= 0; i--){
            int digit = (arr[i] / place) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for(int i = 0; i < n; i++)arr[i] = output[i];

        cout << "\nAfter ";
        if(pass == 1)cout << "units";
        else if(pass == 2)cout << "tens";
        else if(pass == 3)cout << "hundreds";
        else cout << "thousands";

        cout << " pass: ";

        for(int i = 0; i < n; i++)cout << arr[i] << " ";

        cout << "\nIDs with even digit at this position: "
             << evenCount << endl;

        place *= 10;
    }

    delete[] output;
}

int main(){
    int n;

    cout << "Enter number of students (at least 20): ";
    cin >> n;

    if(n < 20){
        cout << "Enter at least 20 students.";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter the last four digits of each student ID: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] < 0 || arr[i] > 9999){
            cout << "Enter IDs between 0 and 9999.";
            delete[] arr;
            return 0;
        }
    }

    radixSort(arr, n);

    cout << "\nSorted IDs: ";
    for(int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    cout << "\nDuplicate IDs and frequencies:" << endl;

    bool found = false;

    for(int i = 0; i < n; i++){
        if(i == 0 || arr[i] != arr[i - 1]){
            int frequency = 1;

            for(int j = i + 1; j < n; j++){
                if(arr[j] == arr[i])frequency++;
                else break;
            }

            if(frequency > 1){
                cout << arr[i] << " occurs "
                     << frequency << " times" << endl;
                found = true;
            }
        }
    }

    if(!found)cout << "No duplicate IDs found." << endl;

    int maxSum = -1;
    int maxID = arr[0];

    cout << "\nDigit sums:" << endl;

    for(int i = 0; i < n; i++){
        int sum = digitSum(arr[i]);

        cout << arr[i] << " = " << sum << endl;

        if(sum > maxSum){
            maxSum = sum;
            maxID = arr[i];
        }
    }

    cout << "\nID with highest digit sum: " << maxID << endl;
    cout << "Highest digit sum: " << maxSum << endl;

    int bestStart = -1, bestLength = 0;
    int currentStart = -1, currentLength = 0;

    for(int i = 0; i < n; i++){
        if(digitSum(arr[i]) % 2 == 0){
            if(currentLength == 0)currentStart = i;
            currentLength++;

            if(currentLength > bestLength){
                bestLength = currentLength;
                bestStart = currentStart;
            }
        }
        else{
            currentLength = 0;
        }
    }

    cout << "\nLongest sequence with even digit sums: ";

    if(bestLength == 0){
        cout << "No such IDs found.";
    }
    else{
        for(int i = bestStart; i < bestStart + bestLength; i++)
            cout << arr[i] << " ";

        cout << "\nLength: " << bestLength;
    }

    cout << endl;

    delete[] arr;

}
