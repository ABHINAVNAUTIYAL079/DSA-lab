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

Node* create() {
    Node* head = nullptr;
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

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* temp;
    
    while (poly1 != nullptr || poly2 != nullptr) {
        float coeff;
        int expo;
        
        if (poly1 == nullptr) {
            coeff = poly2->coe;
            expo = poly2->exp;
            poly2 = poly2->next;
        } else if (poly2 == nullptr) {
            coeff = poly1->coe;
            expo = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp > poly2->exp) {
            coeff = poly1->coe;
            expo = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            coeff = poly2->coe;
            expo = poly2->exp;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coe + poly2->coe;
            expo = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        result = insert(result, coeff, expo);
    }
    return result;
}

int main() {
    cout << "Enter first polynomial:" << endl;
    Node* poly1 = create();
    cout << "Enter second polynomial:" << endl;
    Node* poly2 = create();
    
    cout << "First Polynomial: ";
    print(poly1);
    cout << "Second Polynomial: ";
    print(poly2);
    
    Node* result = addPolynomials(poly1, poly2);
    cout << "Resultant Polynomial: ";
    print(result);
    
    return 0;
}
