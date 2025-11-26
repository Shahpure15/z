#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evalPostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int r;

            switch(c) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/': r = a / b; break;
                default: r = 0;
            }
            st.push(r);
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result = " << evalPostfix(postfix);
    return 0;
}

