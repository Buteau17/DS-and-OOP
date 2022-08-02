#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void heapify(vector<int>& arr, int n, int i)
{

// Initialize largest as root
    int largest = i;

// left = 2*i + 1
    int l = 2 * i + 1;

// right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void HeapSort(vector<int>& arr, int n)
{

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
    
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[(start+end)/2];
 
    int count = 0;
    for (int i = start; i <= end; i++) {
        if(i == (start+end)/2) continue;
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[(start+end)/2]);
    
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
 
    return pivotIndex;
}

void QuickSort(vector<int>& arr, int start, int end) {
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

void PrintArray(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    fstream file;
    file.open("input2.txt");

    int times = 0;
    file >> times;

    for (int t = 0; t < times; t++) {
        int size = 0;
        file >> size;

        vector<int> array1;
        vector<int> array2;

        for (int i = 0; i < size; i++) {
            int x;
            file >> x;
            array1.push_back(x);
            array2.push_back(x);
        }

        HeapSort(array1, size);
        cout << "Max Heap Sort : ";
        PrintArray(array1);

        QuickSort(array2, 0, size-1);
        cout << "Quick Sort : ";
        PrintArray(array2);
    }
    system("pause");
    return 0;
}
