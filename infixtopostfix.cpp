#include <bits/stdc++.h>
using namespace std;

class stackimp {
public:
    int top = -1;
    char st[100];  

    void push(char x) {
        if (top >= 99) {
            cout << "Stack is full\n";
            return;
        }
        st[++top] = x;
    }

    char gettop() {
        if (top == -1) {
            return -1;
        }
        return st[top];
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        top--;
    }

    bool isempty() {
        return top == -1;
    }

    int precedence(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '^') return 3;  
        return 0;
    }

    string infixtopostfix(string s) {
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

           
            if (isalnum(ch)) {
                ans += ch;
            }
           
            else if (ch == '(') {
                push(ch);
            }
            
            else if (ch == ')') {
                while (!isempty() && gettop() != '(') {
                    ans += gettop();
                    pop();
                }
                pop(); 
            }
            else {
                while (!isempty() && precedence(gettop()) >= precedence(ch)) {
                    ans += gettop();
                    pop();
                }
                push(ch);
            }
        }
        while (!isempty()) {
            ans += gettop();
            pop();
        }

        return ans;
    }
};

int main() {
    stackimp st;
    string infix;
    
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = st.infixtopostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
