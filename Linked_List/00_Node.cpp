#include <iostream>
#include<vector>
using namespace std;

// struct Node {
//     private:
//     int data;
//     Node* next;

//     public:
//     Node(int data, Node* next){
//         data = data1;
//         next = next1;
//     }

//     public:
//     Node(int data, Node* next){
//         data = data;
//         next = nullptr;
//     }
    
// };

class Node {
    private:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // public:
    Node(int data){
        data = data;
        next = nullptr;
    }
    
};

int main() {
    vector<int> arr = {2, 4, 6, 8};
    Node* y = new Node(arr[0], nullptr);
    // Node y = new Node(arr[0], nullptr);  // Only objected created and give error
    cout << y <<"\n";

    return 0;
}
















