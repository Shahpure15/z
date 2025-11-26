#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

// Check operator
bool isOp(char x) {
    return x=='+' || x=='-' || x=='*' || x=='/' || x=='^';
}

// Precedence for infix→postfix
int priority(char x){
    if(x=='^') return 3;
    if(x=='*' || x=='/') return 2;
    if(x=='+' || x=='-') return 1;
    return 0;
}

// Prefix → Infix
string preToIn(string pre){
    stack<string> st;
    for(int i=pre.size()-1; i>=0; i--){
        char ch = pre[i];

        if(isOp(ch)){
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string expr = "(" + a + string(1,ch) + b + ")";
            st.push(expr);
        } else {
            st.push(string(1,ch));
        }
    }
    return st.top();
}

// Infix → Postfix
string inToPost(string inf){
    stack<char> st;
    string post = "";

    for(char ch: inf){
        if(isalnum(ch))
            post += ch;
        else if(ch=='(')
            st.push(ch);
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                post += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && priority(st.top()) >= priority(ch)){
                post += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        post += st.top();
        st.pop();
    }
    return post;
}

// Postfix Evaluation
int evalPost(string post){
    stack<int> st;
    for(char ch: post){
        if(isdigit(ch)){
            st.push(ch - '0');
        }
        else{
            int v2 = st.top(); st.pop();
            int v1 = st.top(); st.pop();
            int r;

            switch(ch){
                case '+': r = v1 + v2; break;
                case '-': r = v1 - v2; break;
                case '*': r = v1 * v2; break;
                case '/': r = v1 / v2; break;
                case '^': r = pow(v1, v2); break;
            }
            st.push(r);
        }
    }
    return st.top();
}

// MAIN MENU
int main(){
    int ch;
    string p, in, po;

    do{
        cout << "\n====== STACK OPERATIONS MENU ======";
        cout << "\n1) Prefix to Infix";
        cout << "\n2) Infix to Postfix";
        cout << "\n3) Evaluate Postfix";
        cout << "\n4) Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch){
            case 1:
                cout << "\nEnter Prefix: ";
                cin >> p;
                cout << "Infix = " << preToIn(p) << "\n";
                break;
            case 2:
                cout << "\nEnter Infix: ";
                cin >> in;
                cout << "Postfix = " << inToPost(in) << "\n";
                break;
            case 3:
                cout << "\nEnter Postfix: ";
                cin >> po;
                cout << "Result = " << evalPost(po) << "\n";
                break;
            case 4:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nInvalid input, try again.\n";
        }

    } while(ch != 4);

    return 0;
}
