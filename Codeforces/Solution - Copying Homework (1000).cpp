#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

void Transform(vector<int>& V) {
	int posOf1 = 0, posOfMax = 0;
	for (int i = 0; i < V.size(); ++i) {
		if (V[i] == 1) { posOf1 = i; }
		if (V[i] == V.size()) { posOfMax = i; }
	}
	V[posOf1] = V.size();
	V[posOfMax] = 1;
	
}

int main() {
	int size = 0, entry = 0;
	cin >> size;
	vector<int>perm = {};
	while (size > 0) {
		cin >> entry;
		perm.push_back(entry);
		--size;
	}

	Transform(perm);

	for (int i = 0; i < perm.size(); ++i) {
		cout << perm[i] << " ";
	}
	cout << "\n";
	return 0;
}
