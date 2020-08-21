#include <iostream>
#include <string>
#include <vector>
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

int main() {

	int n;
	cin >> n;
	// n = 1;

	vector<string> pattrens(n);

	for (int i = 0; i < n; i++) {

		string s;
		cin >> s;
		// s = "ATA";

		pattrens.push_back(s);

	}

	tire t = build_tire(pattrens);

	for (int i = 0; i < t.size(); i++) {

		for (auto j : t[i])
			cout << i << "->" << j.second << ":" << j.first << endl;
	}

	return 0;


}