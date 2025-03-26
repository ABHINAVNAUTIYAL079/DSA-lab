#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][4]={{0,4,0,1},{7,0,0,0},{0,0,0,0},{0,5,0,0}};
    int size=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=0){
                size++;
            }
        }
    }

    int sp[size][3];

    int k=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=0){
                sp[k][0]=i;
                sp[k][1]=j;
                sp[k][2]=arr[i][j];
                k++;
            }
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<3;j++){
            cout<<sp[i][j]<<" ";
        }
        cout<<endl;
    }

}