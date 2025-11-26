#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// ------------------- Check Operator -------------------
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

// ------------------- a) PREFIX ? INFIX -------------------
string prefixToInfix(string prefix) {
    stack<string> st;

    // scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
        else if (isalnum(c)) {
            string temp = "";
            temp += c;
            st.push(temp);
        }
    }

    return st.top();
}

// ------------------- Precedence for Infix ? Postfix -------------------
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// ------------------- b) INFIX ? POSTFIX -------------------------
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // remove '('
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// ------------------- c) POSTFIX EVALUATION -----------------------
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push((int)pow(a, b)); break;
            }
        }
    }

    return st.top();
}

// ----------------------------- MAIN ------------------------------
int main() {
    string prefix, infix, postfix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "\n--- OUTPUTS ---\n";
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;
    cout << "Infix to Postfix: " << infixToPostfix(infix) << endl;
    cout << "Postfix Evaluation = " << evaluatePostfix(postfix) << endl;

    return 0;
}

