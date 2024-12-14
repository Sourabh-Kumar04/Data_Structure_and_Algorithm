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


int check_if_Present(Node* head, int val) {
    Node* temp = head;
    while(true){
        if(temp->data = val) return 1;
        temp = temp->next;
    }
    return 0;

    // Time complexity in:
    // Worst case = O(n)
    // Best case = O(1)
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    Node* head = convert_Array_to_LinkedList(arr);

    cout << check_if_Present(head, 4) << "\n";

    return 0;
}
















