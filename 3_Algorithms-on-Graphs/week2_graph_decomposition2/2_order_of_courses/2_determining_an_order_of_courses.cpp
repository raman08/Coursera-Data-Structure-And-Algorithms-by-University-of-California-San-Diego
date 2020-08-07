#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void explore(int v, vector<vector<int> > &adj, vector<bool> &visited, stack<int> &ordering) {

	visited[v] = true;

	for (int i = 0; i < adj[v].size(); i++) {

		int w = adj[v][i];

		if (!visited[w])
			explore(w, adj, visited, ordering);

	}

	ordering.push(v);

}


stack<int> topo_sort(vector<vector<int> > &adj) {

	vector<bool> visited;
	visited.resize(adj.size());

	stack<int> ordering;

	for (int i = 0; i < adj.size(); i++)
		if (!visited[i])
			explore(i, adj, visited, ordering);

	return ordering;

}



void display(vector<vector<int> > &adj) {

	stack<int> ordering = topo_sort(adj);

	while (not ordering.empty()) {

		int n = ordering.top();
		ordering.pop();

		cout << n + 1 << " ";

	}

	cout << endl;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int x, y;
		cin >> x >> y;

		adj[x - 1].push_back(y - 1);

	}

	display(adj);

}