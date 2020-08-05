#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
using std::vector;

#define ll long long

ll majority_element(const vector<ll> A, int n) {

	map<int, int> freq;

	for (int i = 0; i < n; ++i)
		freq[A[i]]++;

	for (int i = 0; i < n; ++i)
		if (freq[A[i]] > n / 2)
			return 1;

	return 0;

}



int main() {

	ll n;
	cin >> n;

	vector<ll> a(n);

	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << majority_element(a, n) << ' ';


	return 0;
}