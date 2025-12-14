#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n;       // Size of Array
	vector<int> a(n);
	for (int &i : a)	cin >> i;     // Array elements
	cin >> k;     // Element to search
    int index = -1;
	for (int i = 0; i < n; i++){
		if(a[i] == k){
			index = i;      // Found at index i
            break;
		}
	}
    if(index == -1)     cout << "Not Found\n";
    else    cout << index << "\n";      // Found at index i    
}