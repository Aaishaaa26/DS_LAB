
#include <iostream>
using namespace std;

class PairHash {
    int head[100];
    int sum[21];
    int first[21];
    int second[21];
    int next[21];
    int count;

    int hashFunction(int value) {
        return value % 100;
    }

public:
    PairHash() {
        count = 0;

        for (int i = 0; i < 100; i++)
            head[i] = -1;
    }

    void findPairs(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int currentSum = arr[i] + arr[j];
                int index = hashFunction(currentSum);

                int temp = head[index];

                while (temp != -1) {
                    if (sum[temp] == currentSum) {
                        if (first[temp] != arr[i] &&
                            first[temp] != arr[j] &&
                            second[temp] != arr[i] &&
                            second[temp] != arr[j]) {

                            cout << "(" << first[temp] << ", "
                                 << second[temp] << ") and ("
                                 << arr[i] << ", " << arr[j] << ")"
                                 << endl;
                            return;
                        }
                    }

                    temp = next[temp];
                }

                sum[count] = currentSum;
                first[count] = arr[i];
                second[count] = arr[j];

                next[count] = head[index];
                head[index] = count;

                count++;
            }
        }

        cout << "No pairs found!" << endl;
    }
};

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};

    PairHash h1;
    PairHash h2;
    PairHash h3;

    cout << "First Array:" << endl;
    h1.findPairs(arr1, 7);

    cout << "\nSecond Array:" << endl;
    h2.findPairs(arr2, 6);

    cout << "\nThird Array:" << endl;
    h3.findPairs(arr3, 7);

    return 0;
}
