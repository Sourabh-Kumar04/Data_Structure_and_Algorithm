#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteNode(int key) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
            return;
        }

        while (temp->next != head && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            toDelete->next->prev = temp;
            delete toDelete;
        }
    }

    void printList() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    cdll.insertAtBeginning(10);
    cdll.insertAtBeginning(5);
    cdll.insertAtEnd(20);

    cdll.printList();

    cdll.deleteNode(10);
    cdll.printList();

    return 0;
}