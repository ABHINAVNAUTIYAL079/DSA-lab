#include <bits/stdc++.h>
using namespace std;

struct Node {
    float coe;
    int exp;
    Node* next;
};

Node* insert(Node* head, float co, int ex) {
    Node* temp;
    Node* newnode = new Node;
    newnode->coe = co;
    newnode->exp = ex;
    newnode->next = nullptr;

    if (head == nullptr || ex > head->exp) {
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    temp = head;
    while (temp->next != nullptr && temp->next->exp > ex) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

Node* create(Node* head) {
    int n, expo;
    float coeff;
    cout << "Enter the number of terms: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient of term " << i + 1 << ": ";
        cin >> coeff;
        cout << "Enter exponent of term " << i + 1 << ": ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "No polynomial" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->coe << "x^" << temp->exp << ")";
            temp = temp->next;
            if (temp != nullptr) {
                cout << " + ";
            } else {
                cout << endl;
            }
        }
    }
}

int main() {
    Node* head = nullptr;
    cout << "ENTER THE POLYNOMIAL" << endl;
    head = create(head);
    print(head);
    return 0;
}
