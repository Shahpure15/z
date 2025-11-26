#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string prefixToInfix(string pre) {
    stack<string> st;
    reverse(pre.begin(), pre.end());

    for (int i = 0; i < pre.length(); i++) {
        char c = pre[i];

        if (!isOperator(c)) {
            string temp = "";
            temp += c;
            st.push(temp);
        } else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string exp = "(" + a + c + b + ")";
            st.push(exp);
        }
    }
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Infix: " << prefixToInfix(prefix);
    return 0;
}

