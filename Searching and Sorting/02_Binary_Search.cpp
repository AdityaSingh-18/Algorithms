#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &a, int n, int k){
	int l = 0, r = n - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;         // Mid index of current subarray
		if (a[mid] == k)	return mid;
		else if (a[mid] < k)	l = mid + 1;
		else	r = mid - 1;
	}
	return -1;      // If element not found
} 

int main(){
	int n, k;
	cin >> n;           // Array size
	vector<int> a(n);
	for (int &i : a)	cin >> i;      // Array elements
	cin >> k;       // Element to search
	int index = BinarySearch(a, n, k);
	if(index == -1)		cout << "Not Found\n";
	else	cout << index << "\n";       // Found at index i 
}
