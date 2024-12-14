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

Node* remove_Tail(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    // delete temp->next;
    free(temp->next);
    temp->next = nullptr;
    return head;
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    Node* head = convert_Array_to_LinkedList(arr);
    
    display_LL(head);
    head = remove_Tail(head);
    display_LL(head);

    return 0;
}


