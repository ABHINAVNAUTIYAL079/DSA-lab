#include<bits/stdc++.h>
using namespace std;

int ls(int arr[],int n,int a){
    for(int i = 0 ; i<n;i++){
        if(a==arr[i]){
            return i;
            break;
        }
    }
    
}

int main(){
    int arr[10]={12,45,32,78,98,103,43,21};

    int x;
    cout<<"Enter the element you want to find in array = ";
    cin>>x;
    

    if (ls(arr,10,x)>=0 && ls(arr,10,x)<10){
        cout<<"Element found at "<<"arr["<<ls(arr,10,x)<<"]";

    }

    else{
        cout<<"not found";

    }

    return 0;

}