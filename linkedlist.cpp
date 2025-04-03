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
    node* insertion_at_head(node* head,int value){
        node* temp = new node(value,head);
        return temp;
        
    }
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
    
    node* insertion_at_last(node* head,int value){
        if(head==nullptr){
            node* temp = new node(value,head);
        }
        
        node* temp=head;
        while(temp->next != nullptr){
           temp=temp->next;

        }

        node* x = new node(value,nullptr);
        temp->next=x;

        return head;
    }

    node* del_first(node* head){
       if(head==nullptr){
        return nullptr;
       }

        node* temp=head;
        head=temp->next;
        free(temp);
        return head;

    }

    node* del_last(node* head){
        if(head==nullptr){
            return nullptr;
        }
        node* temp=head;
        while(temp->next->next!= nullptr){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=nullptr;
        

        return head;
    }
    
    node* deletelist(node* head){
        while(head!=nullptr){
            del_first(head);
            head=head->next;
        }
        return head;
    }

int main(){
    vector <int> arr = {3,4,7,8,8};

    node* head = c2ll(arr);

    head = insertion_at_head(head,35);
    head = insertion_at_head(head,44);
    head = insertion_at_last(head,44);
    head = del_first(head);
    head = del_first(head);
    head = del_first(head);
    head = del_last(head);
    head = del_last(head);
    head = deletelist(head);

    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }


}