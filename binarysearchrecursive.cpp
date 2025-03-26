#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int st, int n, int x)
{
    if (st > n)
    {
        return -1;
    }
    int mid = (st + n) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] > x){
        n = mid - 1;
        return binarysearch(arr, st, n, x);
    }

    else{
        st = mid + 1;
        return binarysearch(arr, st, n, x);
    }
}


int main()
{
    int arr[7] = {2, 5, 6, 8, 9, 10, 15};

    int x;
    cout << "finding element = ";

    cin >> x;

    int y = binarysearch(arr, 0, 7, x);

    if (y == -1)
    {
        cout << "not found";
    }
    else
    {
        cout << "element found at " << "arr[" << y << "] ";
    }

    return 0;
}