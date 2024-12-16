#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    int minEle;

public:
    MinStack() {
        minEle = INT_MAX;
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        } else {
            if (x < minEle) {
                s.push(2 * x - minEle);
                minEle = x;
            } else {
                s.push(x);
            }
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        int t = s.top();
        s.pop();

        if (t < minEle) {
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        if (s.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int t = s.top();
        return (t < minEle) ? minEle : t;
    }

    int getMin() {
        if (s.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return minEle;
    }
};

int main() {
    MinStack s;
    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);
    cout << "minimum element is " << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << "minimum element is " << s.getMin() << endl;
    return 0;
}