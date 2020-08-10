#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool bellman_ford(vector<vector<int> > &adj, vector<vector<int> > &cost, int s) {

	vector <long long> dist(adj.size());

	for (int i = 0; i < adj.size(); i++)
		dist[i] = INT_MIN;

	dist[s] = 0;

	for (int count = 0; count < adj.size() - 1; count++) {

		for (int u = 0; u < adj.size(); u++) {

			for (int j = 0; j < adj[u].size(); j++) {

				int v = adj[u][j];

				if (dist[v] > dist[u] + cost[u][j])
					dist[v] = dist[u] + cost[u][j];

			}
		}
	}

	for (int u = 0; u < adj.size(); u++) {
		for (int j = 0; j < adj[u].size(); j++) {

			int v = adj[u][j];

			if (dist[v] > dist[u] + cost[u][j])
				return true;

		}
	}

	return false;

}



bool negative_cycle( vector<vector<int> > adj, vector<vector<int> > cost) {

	for (int s = 0; s < adj.size(); s++) {

		if (bellman_ford(adj, cost, s))
			return true;
	}

	return false;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>() );
	vector<vector<int> > cost(n, vector<int>() );

	for (int i = 0; i < m; i++) {

		int u, v, w;
		cin >> u >> v >> w;

		adj[u - 1].push_back(v -1);
		cost[u - 1].push_back(w);

	}

	cout << negative_cycle(adj, cost);

	return 0;

}