#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> compute_prefix_function(const string& S) {

	vector<int> prefix(S.size());

	for (int j = 1, border = 0, n = S.size(); j < n; j++) {

		while (border && S[j] != S[border])
			border = prefix[border - 1];

		border = (S[j] == S[border]) ? ++border : 0;
		prefix[j] = border;

	}

	return prefix;

}



vector<int> find_pattren(const string& gnome, const string& pattren) {

	string S = pattren + '$' + gnome;

	vector<int> s = compute_prefix_function(S);
	vector<int> result;

	for (int i = pattren.size() + 1; i < S.size(); i++) {

		if (s[i] == pattren.size())
			result.push_back(i - 2 * pattren.size());

	}

	return result;

}


int main() {

	string pattren, gnome;
	cin >> pattren >> gnome;

	auto result = find_pattren(gnome, pattren);

	for (auto x: result)
		cout << x << " ";

	cout << endl;

}