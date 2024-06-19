#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class MinHeap
{
public:
    int *arr;
    int size;
    int cap;

    MinHeap(int totalcap)
    {
        size = 0;
        cap = totalcap;
        arr = new int[cap];
    }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int num)
    {
        if (size == cap)
        {
            cout << "Can't insert\n";
            return;
        }
        arr[size] = num;
        size++;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
        cout << "Inserted " << num << "\n";
    }

    // min heapify
    void heapify(int num)
    {
        int l = left(num), r = right(num), smallest = num;
        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != num)
        {
            swap(arr[num], arr[smallest]);
            heapify(smallest);
        }
    }

    // max heapify
    void maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(largest);
    }
}


    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }

    void printHeap()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void decreasekey(int ind, int key)
    {
        if (ind < size)
        {
            arr[ind] = key;
            while (ind != 0 && arr[parent(ind)] > key)
            {
                swap(arr[parent(ind)], arr[ind]);
                ind = parent(ind);
            }
        }
    }
    void deletekey(int ind)
    {
        decreasekey(ind, INT_MIN);
        extractMin();
    }

    void buildHeap(vector<int> v)
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }
};

int main()
{
    fast;

    MinHeap minHeap(7);

    minHeap.insert(4);
    minHeap.insert(11);
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(1);

    cout << "Array before building heap:\n";
    minHeap.printHeap();

    // below for loop is same for build heap for loop function
    for (int i = (minHeap.size / 2) - 1; i >= 0; i--)
        minHeap.heapify(i);
    // TC: O(N)

    cout << "Array after building heap:\n";
    minHeap.printHeap();

    cout << "Array after extract min:\n";
    minHeap.printHeap();
    cout << minHeap.extractMin() << " this is min\n";

    cout << "Array after extract min:\n";
    minHeap.printHeap();
    cout << minHeap.extractMin() << " this is min\n";

    cout << "Array after extract min:\n";
    minHeap.printHeap();
    minHeap.insert(1);
    minHeap.insert(3);
    minHeap.insert(4);
    minHeap.insert(2);

    cout << "Array after insertions:\n";
    minHeap.printHeap();
    minHeap.decreasekey(5, 0);
    cout << "Array after decreasekey:\n";
    minHeap.printHeap();
    minHeap.deletekey(3);
    cout << "Array after deletekey:\n";
    minHeap.printHeap();

    return 0;
}
