#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int u, int v) {

	vector<int> dist;
	dist.resize(adj.size());

	for (int i = 0; i < adj.size(); i ++)
		dist[i] = -1;

	dist[u] = 0;

	queue<int> Q;
	Q.push(u);

	while (!Q.empty()) {

		int s = Q.front();
		Q.pop();

		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			if (dist[*i] == -1) {

				Q.push(*i);
				dist[*i] = dist[s] + 1;

			}
		}
	}

	return dist[v];

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

	int u, v;
	cin >> u >> v;

	cout << distance(adj, u - 1, v - 1);

	return 0;

}