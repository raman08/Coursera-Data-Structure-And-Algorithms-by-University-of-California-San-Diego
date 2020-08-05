#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define ll long long

int edit_distance(const string &first, const string &second, int m, int n) {

	vector<vector<int>> distance(m + 1, vector<int> (n + 1));

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; j++) {

			if (i == 0)
				distance[i][j] = j;

			else if (j == 0)
				distance[i][j] = i;

			if (first[i - 1] == second[j - 1])
				distance[i][j] = distance[i - 1][j - 1];

			else
				distance[i][j] = min(min(distance[i][j - 1], distance[i - 1][j]), distance[i - 1][j - 1]) + 1;
		}

	}

	return distance[m][n];
}

int edit_distance2(const string &str1, const string &str2){

	int n = str1.size();
	int m = str2.size();

	vector <vector<int> > D(n+1, vector<int>(m+1));

	for(int i = 0; i <= n; i++)
		D[i][0] = i;

	for(int j = 0; j <= m; j++)
		D[0][j] = j;

	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){

			int insertion = D[i][j-1] + 1;
			int deletion = D[i-1][j] + 1;
			int match = D[i-1][j-1];
			int notmatch = D[i-1][j-1] + 1;

			if(str1.at(i-1) == str2.at(j-1))
				D[i][j] = min(insertion, min(deletion, match));

			else
				D[i][j] = min(insertion, min(deletion, notmatch));
		}
	}

	return D[n][m];
}


int main() {

	string first, second;

	cin >> first >> second;

	int result = edit_distance2(first, second);

	cout << result;


	return 0;
}