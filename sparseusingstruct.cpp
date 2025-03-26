#include<bits/stdc++.h>
using namespace std;

struct sparse{
    int row;
    int col;
    int val;

};



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

    cout<<"sparse matrix"<<endl;
    sparse spar[size];
    int k=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=0){
            spar[k].row=i;
            spar[k].col=j;
            spar[k].val=arr[i][j];
            k++;
            }

        }
    }

    for(int i=0;i<size;i++){
        cout<<spar[i].row<<"\t"<<spar[i].col<<"\t"<<spar[i].val<<endl;
    }
    
    cout<<"transpose"<<endl;

    sparse sm[size];
    for(int i=0;i<size;i++){
        sm[i].row=spar[i].col;
        sm[i].col=spar[i].row;
        sm[i].val=spar[i].val;

    }
    
    for(int i=0;i<size;i++){
        cout<<sm[i].row<<"\t"<<sm[i].col<<"\t"<<sm[i].val<<endl;
    }
    

} 