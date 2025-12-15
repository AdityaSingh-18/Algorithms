#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

void selectionSort(vector<int> &a, int n){
    for (int i = 0; i < n - 1; i++){
        int smallIdx = i;     // Assume i has the smallest element
        for (int j = i + 1; j < n; j++){
            if(a[smallIdx] > a[j])      smallIdx = j;  // store the smallest element index
        }
        if(i != smallIdx){
            swap(a[smallIdx], a[i]);  // Swap the smallest element in subarray [i + 1 to n] to index i
        }
    }
}

int main(){
    int n;
    cin >> n;      // Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;       // Array elements

    selectionSort(a, n);      // O(n ^ 2) Time Compexity

    printArray(a, n);
}


/*

Selection Sort:
All Time Complexity: O(n ^ 2)
Extra Space: O(1)
It is a comparison based sorting technique.
It is not stable sort so the order of two equal number is not preserved.
It is in-place so we dont need any extra space.

*/