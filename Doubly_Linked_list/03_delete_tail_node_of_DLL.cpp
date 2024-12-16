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

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to delete the head node
    void deleteHead() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Function to delete the tail node
    void deleteTail() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node at a given position
    void deleteNodeAtPosition(int position) {
        if (head == nullptr) {
            return;
        }
        if (position == 1) {
            deleteHead();
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr || temp->next == nullptr) {
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = temp;
        }
        delete nodeToDelete;
    }

    // Function to delete a node with a given value
    void deleteNodeWithValue(int value) {
        if (head == nullptr) {
            return;
        }
        if (head->data == value) {
            deleteHead();
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            return;
        }
        if (temp->next == nullptr) {
            deleteTail();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(3);

    dll.printList();

    dll.deleteHead();
    dll.printList();

    dll.deleteTail();
    dll.printList();

    dll.deleteNodeAtPosition(2);
    dll.printList();

    dll.deleteNodeWithValue(20);
    dll.printList();

    return 0;
}