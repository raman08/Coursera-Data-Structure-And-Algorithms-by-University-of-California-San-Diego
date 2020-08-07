#include <iostream>
#include <vector>

using namespace std;

void explore(int v, vector<vector<int> > &adj, vector<bool> &visited) {

	visited[v] = true;

	for (int i = 0; i < adj[v].size(); i++) {

		int w = adj[v][i];

		if (!visited[w])
			explore(w, adj, visited);

	}
}

int no_of_components(vector<vector<int> > &adj) {

	vector<bool> visited;
	visited.resize(adj.size());

	int cc = 0;

	for (int v = 0; v < adj.size(); v++) {

		if (!visited[v]) {
			explore(v, adj, visited);
			cc++;

		}
	}

	return cc;
}


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int x, y;
		cin >> x >> y;

		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);

	}

	cout << no_of_components(adj);

	return 0;

}