#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define ll long long

using namespace std;
using std::vector;


pair<int, int> parition3(vector<int> &A, int l, int r) {

	int x = A[l], m1;
	int j = l;

	for (int i = l + 1; i < r; ++i) {

		if (A[i] <= x) {

			j = j + 1;
			swap(A[i], A[j]);
		}
	}

	swap(A[l], A[j]);

	m1 = j -1;

	for (int i = l; i < j && m1 >= l && m1 > i;) {

		if (A[j] == A[i])
			swap(A[i], A[m1--]);

		else
			i++;

	}

	m1++;


	return make_pair(m1, j);
}


int random_no_generator(int min, int max) {

	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;

	do{
		x = rand();
	} while (x >= RAND_MAX - remainder);

	return min + x % n;

}

vector<int> quick_sort_partition3(vector<int> &a, int l, int r) {
	int x = a[l];
	int p_l = l;
	int i = l;
	int p_e = r;

	vector<int> m(2);

	while (i <= p_e) {

	    if (a[i] < x) {

	        swap(a[p_l], a[i]);
	        p_l++;
	        i++;

	    }
	    else if (a[i] == x) {
	        i++;
	    }
	    else {
	        swap(a[i], a[p_e]);
	        p_e -= 1;
	    }

	    m[0] = p_l;
	    m[1] = p_e;

	}

	return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {

	if (l >= r)
		return;

	int k = l + rand() % (r - l + 1);

	swap(a[l], a[k]);

	// pair<int, int> m = parition3(a, l, r);
	vector<int> m = quick_sort_partition3(a, l, r);

	randomized_quick_sort(a, l, m[0] - 1);
	randomized_quick_sort(a, m[1] + 1, r);
}


int main() {

	int n;
	cin >> n;

	vector<int> a(n);

	for (size_t i = 0; i < a.size(); ++i)
		cin >> a[i];

	randomized_quick_sort(a, 0, a.size() - 1);

	for (size_t i = 0; i < a.size(); ++i)
		cout << a[i] << ' ';
}