#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int maxDepthRecursive(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepthRecursive(root->left);
    int rightDepth = maxDepthRecursive(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int maxDepth = maxDepthRecursive(root);
    cout << "Maximum depth of the tree: " << maxDepth << endl;

    return 0;
}