#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int start, int n){
    int x = arr[n - 1];
    int i = start - 1;

    for (int j = start; j <= n - 2; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[n - 1]);

    return i + 1;
}

void quicksort(int arr[], int start, int n){
    if (start < n) {
        int q = partition(arr, start, n);
        quicksort(arr, start, q );
        quicksort(arr, q + 1, n);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size. Exiting." << endl;
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    quicksort(arr, 0, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
