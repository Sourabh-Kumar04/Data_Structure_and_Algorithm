#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToPrefix(string postfix) {
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
            string temp = c + op2 + op1;
            s.push(temp);
        }
    }

    return s.top();
}

int main() {
    string postfix = "ab+cd-*";
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}