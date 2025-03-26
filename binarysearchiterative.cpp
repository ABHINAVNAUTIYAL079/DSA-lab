#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int st, int n, int x) {
    while (st <= n) {
        int mid = st + (n - st) / 2; 

        if (arr[mid] == x) {
            return mid; 
        }

        if (arr[mid] > x) {
            n = mid - 1; 
        } else {
            st = mid + 1;
        }
    }

    return -1; 
}

int main() {
    int arr[7] = {2, 5, 6, 8, 9, 10, 15};

    int x;
    cout << "Finding element: ";
    cin >> x;

    int y = binarySearch(arr, 0, 6, x); 

    if (y == -1) {
        cout << "Not found";
    } else {
        cout << "Element found at arr[" << y << "]";
    }

    return 0;
}
