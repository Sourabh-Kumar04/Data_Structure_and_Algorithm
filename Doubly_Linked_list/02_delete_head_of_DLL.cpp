#include <iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data){
        data = data;
        next = nullptr;
        prev = nullptr;
    }    
};
 
Node* convert_Array_to_DLL(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 0; i < arr.size(); i++) { 
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void display(Node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "\n";
}

Node* delete_head_DLL(Node* head) {
    if (head == NULL|| head->next == NULL) {
        return NULL;  
    }
    Node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;

    delete temp;
    return head;
}

int main() {
    vector<int> arr = {3, 4, 6, 8};
    Node* head = convert_Array_to_DLL(arr);

    display(head);
    delete_head_DLL(head);
    display(head);

    return 0;
}