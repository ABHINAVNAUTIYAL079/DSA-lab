#include<bits/stdc++.h>
using namespace std;


int main(){
    int r1;
    int c1;
    cout<<"Enter rows of first matrix  ";
    cin>>r1;
    cout<<"Enter columns of first matrix  ";
    cin>>c1;
    int a[r1][c1];

    for(int i=1;i<=r1;i++){
        for(int j=1;j<=c1;j++){
            cin>>a[i][j] ;
        }
    }

    for(int i=1;i<=r1;i++){
        for(int j=1;j<=c1;j++){
            cout<<a[i][j] ;
        }
        cout<<endl;
    }

    for(int i=1;i<=c1;i++){
        for(int j=1;j<=r1;j++){
            cout<<a[j][i] ;
        }
        cout<<endl;
    }

}