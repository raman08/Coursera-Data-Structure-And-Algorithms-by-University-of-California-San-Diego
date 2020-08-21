#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using edges = map<char, int>;
using tire = vector<edges>;



tire build_tire(vector<string>& pattrens) {

	if (pattrens.empty())
		return tire{};

	tire t{edges{}};

	int root = 0;
	int cnt = 0;

	for(auto& pattren : pattrens){

		int current = root;

		for (auto s: pattren) {

			if (t[current].find(s) != t[current].end())
				current = t[current][s];

			else {

				t.emplace_back(edges{});
				t[current][s] = ++cnt;
				current = cnt;

			}
		}

	}

	return t;

}



vector<int> tire_matching(const string& text, int n, vector<string>& pattrens) {

	vector<int> postions;
	tire pattrens_tire = build_tire(pattrens);

	for (int i = 0; i < text.size(); i++) {

		int current_vector = 0;
		int current_symbol = i;

		char symbol = text[current_symbol];

		while (true) {

			if (pattrens_tire[current_vector].empty()) {

				postions.push_back(i);
				break;

			}

			else if (pattrens_tire[current_vector].find(symbol) != pattrens_tire[current_vector].end()) {

				current_vector = pattrens_tire[current_vector][symbol];
				symbol = text[++current_symbol];

			}

			else
				break;

		}
	}

	return postions;
}



int main() {

	string text;
	cin >> text;

	int n;
	cin >> n;

	vector<string> pattrens;

	for (int i = 0; i < n; i++) {

		string s;
		cin >> s;

		pattrens.push_back(s);


	}


	auto ans = tire_matching(text, n, pattrens);

	for (int i = 0; i < (int)ans.size(); i++) {

		cout << ans[i];

		if (i + 1 < (int)ans.size())
			cout << " ";

		else
			cout << endl;

	}
}