#include <iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        this->data = data1;
        this->next = next1;
    }

    public:
    Node(int data){
        this->data = data;
        next = nullptr;
    }  
};

Node* convert_Array_to_LinkedList(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i <arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void display_LL(Node* head) {
    while(head != NULL) {
        cout << head-> data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node* insert_at_Position(Node* head, int data, int pos){
    if(head == NULL) {
        if (pos == 1) {
            return new Node(data);
        }
        else {
            return head;
        }
    }
    if (pos == 1) {
        return new Node(data, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        if (count == (pos - 1)) {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    Node* head = convert_Array_to_LinkedList(arr);
    
    display_LL(head);
    head = insert_at_Position(head, 100, 0);
    display_LL(head);

    return 0;
}



