#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int ALPHABET_SIZE = 5;

inline int getIndex(char c) {
	switch (c) {

	case 'A':
		return 1;

	case 'C':
		return 2;

	case 'G':
		return 3;

	case 'T':
		return 4;

	default:
		return 0;

	}
}

 vector<int> sort_double(const string& s, int L, const vector<int>& order, const vector<int>& cclass) {

	vector<int> count(s.size());
	vector<int> new_order(s.size());

	for (int i = 0; i < s.size(); ++i)
		++count[cclass[i]];


	for (int j = 1; j < s.size(); ++j)
		count[j] += count[j - 1];


	for (int i = s.size() - 1; i >= 0; --i) {

		int start = (order[i] - L + s.size()) % s.size();
		int cl = cclass[start];
		new_order[--count[cl]] = start;

	}

	return new_order;
}

vector<int> compute_chracter_classes(const string& s, const vector<int>& order) {
	 vector<int> cclass(s.size());

	for (int i = 1; i < s.size(); ++i) {

		if (s[order[i]] != s[order[i - 1]]) {

			cclass[order[i]] = cclass[order[i - 1]] + 1;
		}

		else {

			cclass[order[i]] = cclass[order[i - 1]];
		}
	}

	return cclass;
}



 vector<int> counting_chracter_sort(const  string& s) {
	 vector<int> order(s.size());
	 vector<int> count(ALPHABET_SIZE);

	for (auto& c : s) {
		++count[getIndex(c)];
	}

	for (int j = 1; j < ALPHABET_SIZE; ++j) {
		count[j] += count[j - 1];
	}

	for (int i = s.size() - 1; i >= 0; --i) {

		char c = s[i];
		count[getIndex(c)] -= 1;
		order[count[getIndex(c)]] = i;

	}

	return order;

}



 vector<int> update_class(const  vector<int>& new_order, const  vector<int>& cclass, int L) {

	const int n = new_order.size();
	 vector<int> new_cclass(n);

	for (int i = 1; i < n; ++i) {

		int cur = new_order[i], prev = new_order[i - 1];
		int mid = cur + L, midPrev = (prev + L) % n;

		if (cclass[cur] != cclass[prev] || cclass[mid] != cclass[midPrev]) {

			new_cclass[cur] = new_cclass[prev] + 1;
		}

		else {

			new_cclass[cur] = new_cclass[prev];

		}
	}

	return  move(new_cclass);

}

 vector<int> construct_suffix_array(const  string& s) {

	 vector<int> order = counting_chracter_sort(s);
	 vector<int> cclass = compute_chracter_classes(s, order);
	int L = 1;

	while (L < s.size()) {

		order = sort_double(s, L, order, cclass);
		cclass = update_class(order, cclass, L);

		L *= 2;

	}

	return  move(order);

}

int main()
{
	string s;
	cin >> s;

	auto order = construct_suffix_array(s);

	for (auto i : order) {
		cout << i << ' ';
	}

	return 0;
}