#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
using std::string;

typedef unsigned long long ull;

struct Data {
	string pattren, text;
};



Data read_input() {


	Data data;

	cin >> data.pattren;
	cin >> data.text;

	return data;
}



void print_output(const vector<int>& output) {

	for(int i = output.size() - 1; i >= 0; --i)
		cout << output[i] << " ";

	cout << "\n";

}


ull hash_function(const string& s, const ull &prime, const ull &x) {

	ull hash = 0;

	for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
		hash = (hash * x + s[i]) % prime;

	return hash;

}


vector<ull> PreComputeHash(const string& T, const string& t_substr, const size_t &pattren_size, const ull &prime, const ull &x) {

	size_t text_size = T.size();

	vector<ull> H(text_size - pattren_size + 1);

	H[text_size - pattren_size] = hash_function(t_substr, prime, x);

	ull y = 1;

	for (size_t i = 1; i <= pattren_size; i++){
		y = (y * x) % prime;
	}


	for (int i = text_size - pattren_size - 1; i >=0; --i)
		H[i] = (ull)(((H[i + 1] * x) + T[i] - (y * T[i + pattren_size])) % prime);

	return H;
}


void RibinKarp(const Data& input) {


	const string& p = input.pattren;
	const string& t = input.text;

	ull prime = 100000007;
	ull x = 1;

	srand(time(0));

	while(x > (prime - 1)) {

	    x = 1 + rand() / ((RAND_MAX + 1u) / (prime-1));

	}

	// x = ull(((double)rand() / (RAND_MAX)) * (prime-1));

	size_t pattren_size = p.size();
	size_t text_size = t.size();

	vector<int> ans;


	ull pattren_hash = hash_function(p, prime, x);

	string t_substr = t.substr(text_size - pattren_size, pattren_size);

	vector<ull> H = PreComputeHash(t, t_substr, pattren_size, prime, x);

	for (int i = 0; i <= text_size - pattren_size; ++i)
	{
		if ((H[i] == pattren_hash) && (t.substr(i, pattren_size).compare(p) == 0)) {
			cout << i << " ";
			// ans.push_back(i);
		}
	}

	// cout << endl;

}


int main() {


	std::ios_base::sync_with_stdio(false);

	// RibinKarp(read_input());

	Data data;
	data = read_input();

	RibinKarp(data);



	return 0;

}