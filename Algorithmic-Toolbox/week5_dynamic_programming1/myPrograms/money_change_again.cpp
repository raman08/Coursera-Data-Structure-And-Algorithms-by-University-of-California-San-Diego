#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

#define ll long long

ll money_change(int m) {

	int coins[3] = {1, 3, 4};

	vector<ll> ways(m + 1, INT_MAX);

	ways[0] = 0;

	for (int i = 0; i <= m; ++i) {
		for (int c = 0; c < 3; ++c) {

			if (i >= coins[c]) {

				int sub_res = ways[i - coins[c]];

				if (sub_res != INT_MAX && sub_res + 1 <ways[i])
					ways[i] = sub_res + 1;


			}
		}
	}


	return ways[m];
}

int main() {

	int m;
	cin >> m;

	ll result = money_change(m);

	cout << result;

	return 0;
}