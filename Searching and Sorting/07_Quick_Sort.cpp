#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

// Quicksort is in-place algorithm as we are swapping and not using any external memory
int partition(vector<int> &a, int left, int right){
    int i = left;   // we use two pointers i and j for swapping
    for (int j = left; j < right; j++){ 
        if(a[j] <= a[right]){   // taking right index as pivot compare all elements with pivot value
            swap(a[i], a[j]);  // move the smaller elements to the right
            i++;       // move pointer for next swapping
        }
    }
    swap(a[i], a[right]);   // move pivot value to its correct position 
    return i;   // return pivot
}

// QuickSort uses Divide and Conquer method
void quickSort(vector<int> &a, int left, int right){
    if(left < right){
        int pivot = partition(a, left, right);  // choose a pivot
        quickSort(a, left, pivot - 1);    // left half
        quickSort(a, pivot + 1, right);   // right half
    }
}

int main(){
    int n;
    cin >> n;         // Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;     //  Array elements

    quickSort(a, 0, n - 1);       // O(n log n) Time Complexity

    printArray(a, n);
}


/*

Quick Sort:
Best and Average Complexity: O(n log n)
Worst Case: O(n ^ 2) when there is imbalance and bad partitioning
Extra Space: O(log n)
It is Divide and Conquer algorithm.
It is comparision based algorithm.
It is not stable sort and doesnt preserve the order of equal numbers.
It is not in-place and uses extra space for sorting.

*/