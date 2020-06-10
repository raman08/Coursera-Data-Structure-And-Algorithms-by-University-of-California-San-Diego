#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
using std::vector;

#define ll long long


int get_max_index(int n, vector<int> values, vector<int> weights ) {

	int max_index = -1;
	double max_ratio = 0.0;

	for (int i = 0; i < n; ++i) {

		double ratio = (double) values[i] / weights[i];

		if (weights[i] != 0 &&  ratio > max_ratio) {

			max_index = i;
			max_ratio = ratio;

		}
	}

	return max_index;
}


double maxLoot(int n, int capacity, vector<int> values, vector<int> weights) {

	double loot = 0.0;

	for (int i = 0; i < n; ++i) {

		if (capacity == 0)
			return loot;

		int max_index = get_max_index(n, values, weights);
		// cout << "max_index : " << max_index <<" ";

		int a = min(weights[max_index], capacity);
		// cout << "a: " << a <<" ";

		loot +=  a * ( (double) values[max_index] / weights[max_index]);
		// cout << "loot: " << loot <<" ";

		capacity -= a;
		// cout << "capacity: " << capacity <<"  ";

		weights[max_index] -= a;
		// cout << "weights: " << weights[max_index] << '\n';

	}

	// return -1;
}





int main()
{

	int n;
	int capacity;

	cin >> n >> capacity;

	vector<int> values(n);
	vector<int> weights(n);

	for (int i = 0; i < n; i++) {

		cin >> values[i] >> weights[i];
	}


	double loot = maxLoot(n, capacity, values, weights);

	cout.precision(10);
	cout << loot << endl;


	return 0;
}