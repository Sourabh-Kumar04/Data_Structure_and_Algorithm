#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else {
            if (s.empty()) {
                return false;
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string expression = "{([])()}";

    if (isBalanced(expression)) {
        cout << "Balanced Parentheses" << endl;
    } else {
        cout << "Unbalanced Parentheses" << endl;
    }

    return 0;
}