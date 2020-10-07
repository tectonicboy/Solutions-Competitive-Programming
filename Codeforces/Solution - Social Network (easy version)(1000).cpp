#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	unsigned long long n;
	vector<unsigned long>::size_type k;
	unsigned long i;
	cin >> n >> k;
	vector<unsigned long>V;
	unsigned long long counter = 0;
	while ((cin >> i) && (counter < n - 1)) {
		++counter;
		if (V.size() < k) {
			if (find(V.begin(), V.end(), i) == V.end()) {
				V.insert(V.begin(), 1, i);
			}
		}
		else {
			if (find(V.begin(), V.begin() + k, i) == (V.begin() + k)) {
				V.insert(V.begin(), 1, i);
			}
		}
 
	}
	if (V.size() < k) {
		if (find(V.begin(), V.end(), i) == V.end()) {
			V.insert(V.begin(), 1, i);
		}
	}
	else {
		if (find(V.begin(), V.begin() + k, i) == (V.begin() + k)) {
			V.insert(V.begin(), 1, i);
		}
	}
	if (V.size() < k) {
		cout << V.size() << "\n";
		for (vector<unsigned long>::size_type i = 0; i < V.size(); ++i) {
			cout << V[i] << " ";
		}
	}
	else {
		cout << k << "\n";
		for (vector<unsigned long>::size_type i = 0; i < k; ++i) {
			cout << V[i] << " ";
		}
	}
	cout << "\n";
	return 0;
}