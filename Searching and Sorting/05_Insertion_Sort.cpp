#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

// Assume the subarray 0 to i - 1 is already sorted and we try to place 
// the element at i in the correct position
void insertionSort(vector<int> &a, int n){
    for (int i = 1; i < n; i++){ 
        int cur = a[i];   // store the current element in cur
        int prev = i - 1;
        while(prev >= 0 && a[prev] > cur){
            a[prev + 1] = a[prev];  // shift the elements forward to make space for element at index i
            prev--;
        }
        a[prev + 1] = cur;  // place the element at index i at correct position
    }
}

int main(){
    int n;
    cin >> n;       //  Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;      // Array elements

    insertionSort(a, n);       // O(n ^ 2) Time Complexity

    printArray(a, n);
}


/*

Insertion Sort:
Best Time Complexity: O(n)
Average and Worst Case: O(n ^ 2)
Extra Space: O(1)
It is a comparison based sorting technique.
It is stable sort so the order of two equal number is preserved.
It is in-place so we dont need any extra space.

*/