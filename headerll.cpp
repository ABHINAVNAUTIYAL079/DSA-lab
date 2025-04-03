#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* createList() {
    Node* header = new Node(0);
    return header;
}

void traverseList(Node* header) {
    Node* temp = header->next;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAfter(Node* ptr, int data) {
    if (!ptr) return;
    Node* newNode = new Node(data);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteAfter(Node* ptr) {
    if (!ptr || !ptr->next) return;
    Node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

void insertAtLast(Node* header, int data) {
    Node* temp = header;
    while (temp->next)
        temp = temp->next;
    insertAfter(temp, data);
}

void deleteLast(Node* header) {
    if (!header->next) return; 
    Node* temp = header;
    while (temp->next && temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

int main() {
    Node* header = createList();
    
    insertAtLast(header, 10);
    insertAtLast(header, 20);
    insertAtLast(header, 30);
    cout << "List after insertion: ";
    traverseList(header);
    
    insertAfter(header->next, 15);
    cout << "List after inserting 15 after first node: ";
    traverseList(header);
    
    deleteAfter(header->next);
    cout << "List after deleting node after first node: ";
    traverseList(header);
    
    deleteLast(header);
    cout << "List after deleting the last node: ";
    traverseList(header);
    
    return 0;
}
