#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void explore(int node, vector<vector<int> > &adj, set<int> &visited){

    visited.insert(node);

    for (auto a : adj[node]) {

        if (visited.find(a) == visited.end()) {

            explore(a, adj, visited);

        }

    }

}

void reverse_explore(int node, vector<vector<int> > reverse_adj, set<int> &visited, vector<int> &ordering) {

    visited.insert(node);

    for (auto a : reverse_adj[node]) {

        if (visited.find(a) == visited.end()) {

            reverse_explore(a,reverse_adj, visited, ordering);
        }
    }

    ordering.push_back(node);

}

vector<int> get_reverse_post_order(vector<vector<int> > &adj, vector<vector<int> > &reverse_adj) {

    vector<int> ordering;
    set<int> visited;

    for (int node = 0; node < adj.size(); ++node) {

        if (visited.find(node) == visited.end()) {

            reverse_explore(node, reverse_adj, visited, ordering);

        }
    }

    reverse(ordering.begin(), ordering.end());

    return ordering;

}

size_t number_of_strong_components(vector<vector<int> > adj, vector<vector<int> > reverse_adj) {

    if (adj.size() == 0) {
        return 0;
    }

    set<int> visited;

    size_t ncomponents = 0;

    auto node_list = get_reverse_post_order(adj, reverse_adj);

    for (auto node : node_list) {

        if (visited.find(node) == visited.end()) {

            explore(node, adj, visited);

            ncomponents++;

        }
    }

    return ncomponents;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());

	vector<vector<int> > reverse_adj(n, vector<int>());


	for (int i = 0; i < m; i++) {

		int x, y;
		cin >> x >> y;

		adj[x - 1].push_back(y - 1);
		reverse_adj[y - 1].push_back(x - 1);

	}

	cout << number_of_strong_components( adj, reverse_adj);

}