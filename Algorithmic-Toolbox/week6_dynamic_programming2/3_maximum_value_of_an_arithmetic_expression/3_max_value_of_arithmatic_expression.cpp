#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <climits>

using namespace std;

#define ll long long


ll eval(ll a, ll b, char op) {

	if (op == '+')
		return a + b;

	else if (op == '-')
		return a - b;

	else if (op == '*')
		return a * b;

	else
		assert(0);

}

vector<ll> MinAndMax(int i, int j, vector<vector<ll>> m, vector<vector<ll>> M, vector<char> op) {

	ll MIN = LLONG_MAX;
	ll MAX = LLONG_MIN;

	for (int k = i; k < j; k++) {

		ll a = eval(M[i][k], M[k + 1][j], op[k]);
		ll b = eval(M[i][k], m[k + 1][j], op[k]);
		ll c = eval(m[i][k], M[k + 1][j], op[k]);
		ll d = eval(m[i][k], m[k + 1][j], op[k]);


		MIN = min(MIN, min(a, min(b, min(c, d))));
		MAX = max(MAX, max(a, max(b, max(c, d))));


	}

	vector<ll> MinMax(2);

	MinMax[0] = MIN;
	MinMax[1] = MAX;

	return MinMax;
}



int get_max_value(const string &exp) {

	// int n = (exp.size() + 1) / 2;

	// vector<vector<ll> > Min(n, vector<ll>(n));
	// vector<vector<ll> > Max(n, vector<ll>(n));
	// vector<char> Operator(exp.size() - n);

	// for (int i = 0; i < exp.size(); ++i) {

	// 	if (i % 2 == 0){
	// 		Min[i / 2][i / 2] = exp.at(i) - 48;
	// 		Max[i / 2][i / 2] = exp.at(i) - 48;
	// 	}
	// 	else
	// 		Operator[(i - 1) / 2] = exp.at(i);
	// }

	// for (int s = 1; s < n; s++) {
	// 	for (int i = 0; i < (n - s); i++) {

	// 		vector<ll> MinMax(2);

	// 		int j = i + s;

	// 		MinMax = MinAndMax(i, j, Min, Max, Operator);

	// 		Min[i][i + s] = MinMax[0];
	// 		Max[i][i + s] = MinMax[1];

	// 	}

	// }

	// return Max[0][n - 1];

	int n = (exp.size() + 1)/2;

    // 2D-vector to record Min and Max
    vector <vector<long long> > Min(n, vector<long long>(n));
    vector <vector<long long> > Max(n, vector<long long>(n));
    vector<char> Operator(exp.size()-n);    // 1D-vector to store Operator

    // in exp, even index is a number, odd index is a operator
    for(int i = 0; i < exp.size(); i++){
        // store number in Min(i, i) Max(i, i)
        if(i % 2 == 0){
            Min[i/2][i/2] = exp.at(i)-48;
            Max[i/2][i/2] = exp.at(i)-48;
        }
        else
            Operator[(i-1)/2] = exp.at(i);
    }
    // ¥H¹ï¨¤½u¬°°ò·Ç, ©¹¥k¤W¨¤±×¦V¶ñ­pºâ¦nªº¼Æ¦r¨ìMin©MMax¤¤, indexªººâ¼Æ­nª`·N
    // compute min and max number, store them in diagonally from diagonal of matrix to upper-right corner
    for(int s = 1; s < n; s++){
        for(int i = 0; i < (n-s); i++){
            vector<long long> MinMax(2);
            int j = i + s;
            MinMax = MinAndMax(i, j, Min, Max, Operator);
            Min[i][i+s] = MinMax[0];
            Max[i][i+s] = MinMax[1];
        }
    }
    return Max[0][n-1];
}

int main() {

	string s;
	cin >> s;

	int result = get_max_value(s);

	cout << result;


	return 0;
}