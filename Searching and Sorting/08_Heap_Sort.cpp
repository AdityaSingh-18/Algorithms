#include<bits/stdc++.h>
using namespace std;

// Heapify function is used to fix the heap property of the subtree rooted at index i
void heapify(vector<int> &a, int i, int n){
    int maxIdx = i;             
    int left = i * 2 + 1;       // index of left child
    int right = i * 2 + 2;      // index of right child
    // updating maxIdx value by comparing
    if (left < n && a[left] > a[maxIdx])    maxIdx = left;     
    if (right < n && a[right] > a[maxIdx])   maxIdx = right;
    // If the current node doesnt have the largest element then swap it and heapify its subtree
    // otherwise we stop
    if (i != maxIdx){
        swap (a[i], a[maxIdx]);
        heapify(a, maxIdx, n);     // Again restore Max Heap property for subtree rooted at maxIdx
    }
}

void heapSort(vector<int> &a, int n){
    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);               // Move the current max to its final position
        heapify(a, 0, i);               // Restore Max Heap property for the reduced heap
    }
}

void buildHeap(vector<int> &a, int n){
    for (int i = (n - 1) / 2; i >= 0; i--){     // We start from last non leaf node
        heapify(a, i, n);         // Restore Max Heap property for subtree rooted at i 
    }
}

int main(){
    int n;
    cin >> n;        // Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;       // Array elements

    buildHeap(a, n);    // Convert vector into a Heap

    heapSort(a, n);
    for (int &i : a)    cout << i << " ";       // Print the sorted vector(ascending for MaxHeap)
    cout << "\n";
}


/*

HeapSort:
All Time Complexity: O(n log n)
Extra Space: O(1)
It is comparison based algorithm.
It is not stable sort so the order of two equal number is not preserved.
It is in-place so we dont need any extra space.

*/