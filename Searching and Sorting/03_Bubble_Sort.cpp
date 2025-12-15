#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

void bubbleSort(vector<int> &a, int n){
    for (int i = 0; i < n - 1; i++){
        int isSwapped = false;
        for (int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);    // perform swapping for subarray [0 to n - i]
                isSwapped = true;
            }
        }
        if(isSwapped)   return;   // If no swap occured then array is already sorted 
    }
}

int main(){
    int n;
    cin >> n;       /// Size of array

    vector<int> a(n);
    for (int &i : a)    cin >> i;       // Arrat elements

    bubbleSort(a, n);       // O(n ^ 2) Time Complexity

    printArray(a, n);
}


/*

Bubble Sort:
Best Time Complexity: O(n) if already sorted.
Average and Worst Complexity: O(n ^ 2)
Extra Space: O(1)
It is a comparison based sorting technique.
It is stable sort so the order of two equal number is preserved.
It is in-place so we dont need any extra space.

*/