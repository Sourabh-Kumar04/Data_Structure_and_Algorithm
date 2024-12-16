#include <iostream>

using namespace std;

class Dequeue {
private:
    int front, rear, size;
    int capacity;
    int *arr;

public:
    Dequeue(int capacity) {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueueFront(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = x;
    }

    void enqueueRear(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = x;
    }

    int dequeueFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return x;
    }

    int dequeueRear() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int x = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        return x;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty() || rear == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Dequeue dq(5);
    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueFront(30);
    dq.enqueueFront(40);

    cout << "Deque Front: " << dq.getFront() << endl;
    cout << "Deque Rear: " << dq.getRear() << endl;

    cout << dq.dequeueFront() << endl;
    cout << dq.dequeueRear() << endl;

    return 0;
}