#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <set>
#include <queue>

using namespace std;

struct Node {

	int vertex;
	int dist;

	Node(int vertex, int dist) : vertex(vertex), dist(dist) {}

	bool operator>(const Node & rhs) const {return this->dist > rhs.dist;}
};

int flight_cost(vector<vector<int>> &adj, vector<vector<int>> cost, int s, int e) {

	vector<int> dist(adj.size(), INT_MAX);

	dist[s] = 0;

	priority_queue < Node, vector<Node>, greater<Node> > pq;

	pq.push(Node(s, 0));

	set<int> proceded;

	while (!pq.empty()) {

		auto curr = pq.top();
		pq.pop();

		int curr_index = curr.vertex;

		for (int i = 0; i < adj[curr_index].size(); i++) {

			int n = adj[curr_index][i];

			if (dist[n] > dist[curr_index] + cost[curr_index][i]) {

				dist[n] = dist[curr_index] + cost[curr_index][i];

				pq.push(Node(n, dist[n]));

			}
		}

		proceded.insert(curr_index);

	}

	if (dist[e] == INT_MAX){
		return -1;
	}

	else
		return dist[e];

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int u, v, w;
		cin >> u >> v >> w;

		adj[u - 1].push_back(v - 1);
		cost[u - 1].push_back(w);

	}

	int x, y;
	cin >> x >> y;

	cout << flight_cost(adj, cost, x - 1, y - 1);

	return 0;

}