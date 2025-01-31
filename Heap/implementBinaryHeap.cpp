#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void deleteNode(int i) {
        if (i >= heap.size()) return;
        heap[i] = heap.back();
        heap.pop_back();
        heapify(i);
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        deleteNode(0);
        return maxVal;
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    void pop() {
        deleteNode(0);
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

class MinHeap {
    vector<int> heap;

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void deleteNode(int i) {
        if (i >= heap.size()) return;
        heap[i] = heap.back();
        heap.pop_back();
        heapify(i);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        deleteNode(0);
        return minVal;
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    void pop() {
        deleteNode(0);
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    cout << "Max Heap:" << endl;
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.printHeap();
    cout << "Extract Max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();
    maxHeap.pop();
    maxHeap.printHeap();

    cout << "\nMin Heap:" << endl;
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.printHeap();
    cout << "Extract Min: " << minHeap.extractMin() << endl;
    minHeap.printHeap();
    minHeap.pop();
    minHeap.printHeap();
    
    return 0;
}
