#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);


class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
    
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
    
        if (largest != i) {
            swap(arr[i], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }


    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=(n-2)/2; i>=0; i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int i = n - 1; i >= 1; i--){
            swap(arr[0], arr[i]);
            // Call heapify on the root of the reduced heap
            heapify(arr, i, 0);
        }
    }

};




class MinHeap
{
public:
    int *arr;
    int size;
    int cap;
    vector<int> v = {5, 3, 2, 1};

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
    void maxHeapify(int i, int heapSize)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heapSize && v[l] > v[largest])
            largest = l;
        if (r < heapSize && v[r] > v[largest])
            largest = r;

        if (largest != i)
        {
            swap(v[i], v[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    void heapsort()
    {
        buildHeap();
        int n = v.size();
        for (int i = n - 1; i >= 1; i--)
        {
            swap(v[0], v[i]);
            maxHeapify(0, i);
        }

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    void buildHeap()
    {
        int n = v.size();
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            maxHeapify(i, n);
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

    minHeap.heapsort();

    return 0;
}
