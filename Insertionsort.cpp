#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i];

        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

int main(){

    int n;
    cout<<"Enter size of array = ";
    cin>>n;

    int a[n];
     
    cout<<"Enter elements of array = "<<endl; 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertionsort(a,n);

    cout<<"Sorted array = "<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}