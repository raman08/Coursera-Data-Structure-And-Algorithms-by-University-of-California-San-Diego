#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
using std::vector;

#define ll long long

ll BinarySearch_iterative(const vector<ll> &A, ll key) {

	ll low = 0;
	ll high = A.size();

	while (low <= high) {


		ll mid = low +  floor((high - low)/ 2) ;

		if  (key == A[mid])
			return mid;

		else if (key < A[mid])
			high = mid - 1;

		else
			low = mid + 1;
	}

	return -1;
}



int main() {

	ll n;
	cin >> n;

	vector<ll> a(n);

	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}

	ll k;
	cin >> k;

	vector<ll> b(k);

	for (int i = 0; i < k; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < k; ++i) {

		cout << BinarySearch_iterative(a, b[i]) << ' ';

	}


	return 0;

}