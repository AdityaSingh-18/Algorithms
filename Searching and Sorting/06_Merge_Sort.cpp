#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

void merge(vector<int> &a, int left, int mid, int right){
    vector<int> temp;       // temporary vector to store sorted subarray
    int i = left, j = mid + 1;
    while (i <= mid && j <= right){   // push the smaller element in temp vector
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    // after the previous while loop atmost 1 subarray element will be left
    // we push the remaining elements in the temp
    while (i <= mid){   
        temp.push_back(a[i]);
        i++;
    }
    while (j <= right){
        temp.push_back(a[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++){
        a[left + k] = temp[k];      // copy the sorted temp vector to original vector from index left
    }
}

// MergeSort uses Divide and Conquer method
void mergeSort(vector<int> &a, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);    // left half
        mergeSort(a, mid + 1, right);   // right half
        merge(a, left, mid, right);     // merge both part in sorted way
    }
}

int main(){
    int n;
    cin >> n;      // Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;     // Array elements

    mergeSort(a, 0, n - 1);       // O(n log n) Time Complexity

    printArray(a, n);
}


/*

Merge Sort:
All time Complexity: O(n log n)
Extra Space: O(n)
It is a Divide and Conquer algorithm.
It is a comparison based algorithm.
It is stable sort so the order of two equal number is preserved.
It is not in-place so we need extra space for sorting.

*/