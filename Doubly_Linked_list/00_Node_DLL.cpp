#include <iostream>
#include<vector>
using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int data1, Node* next1, Node* prev1){
//         data = data1;
//         next = next1;
//         prev = prev1;
//     }

//     Node(int data){
//         data = data;
//         next = nullptr;
//         prev = nullptr;
//     }
    
// };


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

    // public:
    Node(int data){
        data = data;
        next = nullptr;
        prev = nullptr;
    }
    
};

int main() {
    vector<int> arr = {2, 4, 6, 8};
    Node* y = new Node(arr[0]);
    // Node y = new Node(arr[0]);  // Only objected created and give error
    cout << y <<"\n";

    return 0;
}
















