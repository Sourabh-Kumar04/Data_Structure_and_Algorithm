#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = q.front();
        q.pop();

        // Move all elements except the top element to the end
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        return x;
    }

    int peek() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl;
    cout << s.peek() << endl;

    return 0;
}