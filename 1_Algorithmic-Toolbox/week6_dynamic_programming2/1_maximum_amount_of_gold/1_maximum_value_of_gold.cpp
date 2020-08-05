#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll gold(int W, const vector<int> weights) {

	vector<int> c(W + 1);

	for (int i = 0; i < weights.size(); ++i) {
		for (int j = W; j >= weights[i]; --j) {

			c[j] = max(c[j], c[j - weights[i]] + weights[i]);

		}
	}

	return c[W];
}

int main() {

	ll W;
	int n = 0;

	cin >> W >> n;

	vector<int> weights(n);

	for(int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	ll result = gold(W, weights);

	cout << result;

	return 0;
}