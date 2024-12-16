#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToInfix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {
            string op(1, c);
            s.push(op);
        } else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op2 + c + op1 + ")";
            s.push(temp);
        }
    }

    return s.top();
}

int main() {
    string postfix = "ab+cd-*";
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}