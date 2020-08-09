#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

bool distance(vector<vector<int> > &adj, int u, vector<int> &color) {


	color[u] = 1;

	queue<int> Q;
	Q.push(u);

	while (!Q.empty()) {

		int s = Q.front();
		Q.pop();

		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			if (color[*i] == -1) {

				Q.push(*i);
				color[*i] = 1 - color[s] ;

			}

			else if (color[*i] == color[s])
				return false;
		}
	}

	return true;

}

int distance_all(vector<vector<int> > &adj) {

	vector<int> color;
	color.resize(adj.size());

	for (int i = 0; i < adj.size(); i ++)
		color[i] = -1;

	for (int i = 0; i < adj.size(); i++) {

		if (color[i] == -1)
			if (!distance(adj, i, color))
				return false;

	}

	return true;
}

int main() {

	int n, m;
	cin >> n >>m;

	vector<vector<int> > adj(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int x, y;

		cin >> x >> y;

		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);

	}

	cout << distance_all(adj);

	return 0;

}