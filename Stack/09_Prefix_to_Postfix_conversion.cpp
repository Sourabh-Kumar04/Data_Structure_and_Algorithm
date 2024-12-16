#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(string prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            string op(1, c);
            s.push(op);
        } else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + c;
            s.push(temp);
        }
    }

    return s.top();
}

int main() {
    string prefix = "-+ab*cd";
    string infix = prefixToPostfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}