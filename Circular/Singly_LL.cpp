#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int key) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (head->data == key) {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }

        while (temp->next != head && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
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
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(20);

    cll.printList();

    cll.deleteNode(10);
    cll.printList();

    return 0;
}
