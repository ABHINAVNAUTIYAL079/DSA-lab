#include<bits/stdc++.h>
using namespace std;

class stackimp{
    public:
        int top=-1;
        int st[10];
    
        void push(int x){
        if(top>=9){
            cout<<"STack is full";
        }
        st[++top]=x;
        } 
        
        int gettop(){
            if (top==-1){
                cout<<"STack is empty";
                return -1;
            }
            return st[top];
        }

        void pop(){
            if (top==-1){
                cout<<"STack is empty";
                return;
            }
            top=top-1;
        }

        int size(){
            return top+1;
        }
        
        
};


int main(){
    stackimp s;
    s.push(5);
    s.push(7);
    cout<<s.gettop()<<endl;
    s.pop();
    
    cout<<s.size()<<endl;
    cout<<s.gettop()<<endl;
}