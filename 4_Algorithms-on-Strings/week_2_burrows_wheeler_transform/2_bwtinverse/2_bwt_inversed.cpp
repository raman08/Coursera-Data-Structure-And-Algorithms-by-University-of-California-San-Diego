#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using Symbol = vector<int>;

int get_index_in_symbol(char s) {

	switch (s) {

		case 'A':
			return 0;

		case 'C':
			return 1;

		case 'G':
			return 2;

		case 'T':
			return 3;

		default:
			return 4;

	}

}

int get_index_in_right_column(Symbol& sm, char s, int count) {

	switch (s) {

		case 'A':
			return count;

		case 'C':
			return sm[0] + count;

		case 'G':
			return sm[1] + sm[0] + count;

		case 'T':
			return sm[2] + sm[1] + sm[0] + count;

		default:
			return 0;

	}

}



string BWT_inversed(string text) {

	if (text.size() == 1)
		return text;

	Symbol symbol(5, 0);
	vector<int> indexes(text.size(), 0);

	auto* iptr = &indexes[0];
	auto* sptr = text.c_str();

	while (*sptr)
		*iptr++ = ++symbol[get_index_in_symbol(*sptr++)];

	auto rsize = text.size();

	char r[rsize + 1];
	r[rsize] = '\0';

	char s = text[0];
	int j = indexes[0];
	int k = text.size() - 1;

	r[k--] = '$';
	r[k--] = s;

	for (int i = 2, itres = text.size() - i; itres--; ++i) {

		int index_in_right_column = get_index_in_right_column(symbol, s, j);

		r[k--] = text[index_in_right_column];
		j = indexes[index_in_right_column];
		s = r[k + 1];

	}

	return r;

}

int main() {

	string text;
	cin >> text;

	auto result =  BWT_inversed(text);
	cout << result;

	return 0;

}