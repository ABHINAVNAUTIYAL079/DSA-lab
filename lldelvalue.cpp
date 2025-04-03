#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;

    public:
    node(int data1,node* next1){
         data=data1;
         next=next1;
    }
};
    
    node* c2ll(vector <int> &arr){
        node* head= new node(arr[0],nullptr);
        node* mover = head;
        for(int i=1;i<arr.size();i++){
            node* temp = new node(arr[i],nullptr);
            mover->next=temp;
            mover = temp;
    
        }
        return head;
    } 

    node* delvalue(node* head,int val){
        while(head!=nullptr && head->data==val){
            node* temp=head;
            head=head->next;
            free(temp);
        }
        
       
        node* temp = head;
        node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == val) {
            prev->next = temp->next;  
            free(temp);               
            temp = prev->next;        
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

        return head;
    }
    
int main(){
    vector <int> arr = {3,4,7,90,8};

    node* head = c2ll(arr);

    head = delvalue(head,7);

    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }


}