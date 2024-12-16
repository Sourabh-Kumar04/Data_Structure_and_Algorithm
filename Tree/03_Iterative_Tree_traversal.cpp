#include <iostream>
#include <stack>
#include <queue>

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

// Iterative Traversals

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

void inorderTraversalIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderTraversalIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) {
            s.push(curr->right);
        }
        if (curr->left) {
            s.push(curr->left);
        }
    }
}

void postorderTraversalIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) {
            s1.push(curr->left);
        }
        if (curr->right) {
            s1.push(curr->right);
        }
    }

    while (!s2.empty()) {
        Node* curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal (Iterative): ";
    preorderTraversalIterative(root);
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    inorderTraversalIterative(root);
    cout << endl;

    cout << "Postorder Traversal (Iterative): ";
    postorderTraversalIterative(root);
    cout << endl;

    return 0;
}