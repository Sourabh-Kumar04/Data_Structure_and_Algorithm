#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
public:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(15);
    h.insert(2);

    cout << h.getMin() << endl; // Output: 2

    h.extractMin();
    h.extractMin();

    cout << h.getMin() << endl; // Output: 10

    return 0;
}