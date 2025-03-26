#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;

}

int partition(int a[],int st,int n){
    int x = a[st];
    int i = st;

    for(int j=st + 1;j<n;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i],a[st]);
    return i;

}

void qs(int a[],int st,int n){
    if(st<n){
        int q = partition(a,st,n);
        qs(a,st,q);
        qs(a,q+1,n);
    }
}

int main(){
    int n;
    cout<<"enter array size = ";
    cin>>n;

    int a[n];

    for(int i = 0;i<n;i++){
        cout<<"ENTER ELEMENT "<<i+1<<"="<<endl;
        cin>>a[i];
    }

    qs(a,0,n);

    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }

    return 0;
}

