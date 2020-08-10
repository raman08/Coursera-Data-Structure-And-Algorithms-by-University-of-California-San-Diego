#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <queue>

using namespace std;

// class Number {

// public:

// 	long long value;
// 	bool is_inf;

// 	Number() : is_inf(true) {}

// 	void set_value(long long value) {

// 		this->value = value;
// 		this->is_inf = false;

// 	}


// 	Number operator+(const long long &rhs) {

// 		Number res = Number();

// 		if (not is_inf)
// 			res.set_value(value + rhs);

// 		return res;

// 	}

// 	Number operator+(const Number &rhs) {

// 		Number res = Number();
// 		res.is_inf = is_inf or rhs.is_inf;

// 		if (not res.is_inf)
// 			res.set_value(value + rhs.value);

// 		return res;

// 	}

// 	bool operator>(const Number &rhs) {

// 		if (is_inf)
// 			return !rhs.is_inf;

// 		else if (rhs.is_inf)
// 			return false;

// 		else
// 			return value > rhs.value;

// 	}

// };




// struct Result {

// 	vector<Number> dist;
// 	vector<int> prev;
// 	set<int> neg_inf;

// 	Result(vector<Number> dist, vector<int> prev, set<int> neg_inf) : dist(dist), prev(prev), neg_inf(neg_inf) {}

// };



class Number {

  public:

    long long value;
    bool is_infty;

    Number() : is_infty(true) {}

    void set_value(long long value) {

        this->value = value;
        this->is_infty = false;

    }


    Number operator+(const long long &rhs) {

        Number res = Number();

        if (not is_infty) {
            res.set_value(value + rhs);
        }

        return res;
    }



    Number operator+(const Number &rhs) {

        Number res = Number();

        res.is_infty = is_infty or rhs.is_infty;

        if (not res.is_infty) {
            res.set_value(value + rhs.value);
        }

        return res;

    }


    bool operator>(const Number &rhs) {

        if (is_infty) {

            return !rhs.is_infty;

        }

        else if (rhs.is_infty) {

            return false;

        }
        else {

            return value > rhs.value;
        }

    }
};


struct Result {

    vector<Number> dist;
    vector<int> prev;
    set<int> neg_infty;

    Result(std::vector<Number> dist, std::vector<int> prev, std::set<int> neg_infty)
        : dist(dist), prev(prev), neg_infty(neg_infty) {}

};


// Result bellman_ford(vector< vector<int> > &adj, vector< vector<int> > &cost, int s) {

// 	vector<Number> dist(adj.size());

// 	for (int i = 0; i < adj.size(); i++)
// 		dist[i].value = INT_MAX;

// 	vector<int> prev(adj.size(), -1);

// 	dist[s].set_value(0);
// 	prev[s] = 0;

// 	for (int count = 0; count < adj.size() - 1; count++) {

// 		for (int u = 0; u < adj.size(); u++) {

// 			for (int j = 0; j < adj.size(); j++) {

// 				int v = adj[u][j];

// 				if (dist[v] > dist[u] + cost[u][j]) {

// 					dist[v] = dist[u] + cost[u][j];
// 					prev[v] = u;

// 				}

// 			}
// 		}


// 	}


// 	queue<int> nq;
// 	set<int> neg_inf;
// 	set<int> processed;

// 	for (int u = 0; u < adj.size(); u++) {

// 		for (int j = 0; j < adj[u].size(); j++) {

// 			int v = adj[u][j];

// 			if (dist[v] > dist[u] + cost[u][j]) {

// 				dist[v] = dist[u] + cost[u][j];

// 				nq.push(v);
// 				processed.insert(v);

// 			}

// 		}
// 	}


// 	while (!nq.empty()) {

// 		auto curr = nq.front();
// 		nq.pop();

// 		neg_inf.insert(curr);

// 		for (auto n : adj[curr]) {

// 			if (processed.find(n) == processed.end()) {

// 				nq.push(n);
// 				processed.insert(n);

// 			}
// 		}
// 	}

// 	return Result(dist, prev, neg_inf);


// }


Result bellman_ford(vector< vector<int> > &adj, vector< vector<int> > &weights, int s) {

	vector<Number> dist(adj.size());
    vector<int> prev(adj.size(), -1);

    dist[s].set_value(0);
    prev[s] = 0;


    for (int count = 0; count < adj.size() - 1; ++count) {

        for (int u = 0; u < adj.size(); ++u) {

            for (int j = 0; j < adj[u].size(); ++j) {

                int v = adj[u][j];


                if (dist[v] > dist[u] + weights[u][j]) {

                    dist[v] = dist[u] + weights[u][j];
                    prev[v] = u;

                }

            }

        }
    }


    queue<int> nqueue;
    set<int> neg_infty;
    set<int> processed;

    for (int u = 0; u < adj.size(); ++u) {

        for (int j = 0; j < adj[u].size(); ++j) {

            int v = adj[u][j];

            if (dist[v] > dist[u] + weights[u][j]) {

                dist[v] = dist[u] + weights[u][j];

                nqueue.push(v);
                processed.insert(v);

            }
        }
    }


    while (not nqueue.empty()) {

        auto curr = nqueue.front();
        nqueue.pop();

        neg_infty.insert(curr);

        for (auto n : adj[curr]) {

            if (processed.find(n) == processed.end()) {

                nqueue.push(n);
                processed.insert(n);

            }
        }
    }

    return Result(dist, prev, neg_infty);

}



int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>() );
	vector<vector<int> > cost(n, vector<int>() );

	for (int i = 0; i < m; i++){

		int u, v, w;
		cin >> u >> v >> w;

		adj[u - 1].push_back(v - 1);
		cost[u - 1].push_back(w);


	}

	int s;
	cin >> s;

	auto res = bellman_ford(adj, cost, s - 1);

	for (int e = 0; e < n; e++) {

		if (res.prev[e] == -1)
			cout << "*" << endl;

		else if (res.neg_infty.find(e) != res.neg_infty.end())
			cout << "-" << endl;

		else
			cout << res.dist[e].value << endl;

	}


	return 0;
}