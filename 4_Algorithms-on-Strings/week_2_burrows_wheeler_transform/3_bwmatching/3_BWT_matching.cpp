#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using Symbol = vector<int>;


class BWT_Matching {

	int N;
	string bwt;

	vector<vector<int> > symbol_counter_by_index;
	vector<int> symbol_counter;


	int get_index(char s) {

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

	int get_first_position(char s) {

		switch (s) {

			case 'A':
				return 1;

			case 'C':
				return symbol_counter[0] + 1;

			case 'G':
				return symbol_counter[1] + symbol_counter[0] + 1;

			case 'T':
				return symbol_counter[2] + symbol_counter[1] + symbol_counter[0] + 1;

			default:
				return 0;

		}

	}


	int get_symbol_counter_by_index(int i, char s) {

		return symbol_counter_by_index[get_index(s)][i];

	}

	bool is_symbol_in_top_bottom_range(int top, int bottom, char s) {

		return symbol_counter_by_index[get_index(s)][bottom] > symbol_counter_by_index[get_index(s)][top];

	}


public:

	BWT_Matching(const string& bwt)

		:symbol_counter_by_index {vector<vector<int> >(5, vector<int>(bwt.size() + 1)) }

	{
		N = bwt.size();
		this->bwt = bwt;

		symbol_counter.resize(5);
		// symbol_counter_by_index.resize(5);


		for (int i = 1; i <= N; i++) {

			for(auto& o : symbol_counter_by_index)
				o[i] = o[i - 1];

			++symbol_counter[get_index(bwt[i - 1])];
			++symbol_counter_by_index[get_index(bwt[i - 1])][i];

		}
	}


	int get_num_of_pattren_occured(const string& pattren) {

		if (pattren.size() == 1)
			return symbol_counter[get_index(pattren[0])];

		int top = 0;
		int bottom = bwt.size() - 1;
		int k = pattren.size();

		while (top <= bottom) {

			if(k) {

				char s = pattren[--k];

				if(is_symbol_in_top_bottom_range(top, bottom + 1, s)) {

					top = get_first_position(s) + get_symbol_counter_by_index(top, s);

					bottom = get_first_position(s) + get_symbol_counter_by_index(bottom + 1, s) - 1;

				}

				else
					return 0;

			}

			else
				return (bottom - top) + 1;

		}
	}

};

int main() {

	string bwt;
	cin >> bwt;

	BWT_Matching bwm(bwt);

	int s;
	cin >> s;

	while (s--) {

		string pattren;
		cin >>pattren;

		cout << bwm.get_num_of_pattren_occured(pattren) << endl;

	}

	return 0;

}