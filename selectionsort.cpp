#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    int a[n];

    for(int i =0;i<n;i++){
        cout<<"Enter element "<<i+1<<" ";
        cin>>a[i];
    }

    selectionsort(a,n);

    for(int i =0;i<n;i++){
        cout<<a[i];
    }
}