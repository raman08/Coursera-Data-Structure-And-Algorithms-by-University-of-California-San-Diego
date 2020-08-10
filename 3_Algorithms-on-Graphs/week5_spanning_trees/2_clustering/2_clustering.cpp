#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point2D {

	int x, y;

	Point2D() : x(0), y(0) {};

	Point2D(int x, int y) : x(x), y(y) {};

	friend ostream &operator<<(ostream &os, const Point2D &point);

};

ostream &operator<<(ostream &os, const Point2D &point) {

	os << "(" << point.x << ", " << point.y <<")";

	return os;

}

struct Set {

	int rank;
	int parent;

	Set() : rank(0), parent(-1) {};

};

class Disjoint_Set {

	vector<Set> sets;


public:

	Disjoint_Set(int size) {


		sets.resize(size);

		for (int i = 0; i < size; i++)
			sets[i].parent = i;

	};


	int find(int u) {

		int index{u};

		if (sets[index].parent != index)
			sets[index].parent = find(sets[index].parent);

		return sets[index].parent;

	}



	// Method to joint the 2 set with given elements with help of the rank.
	void take_union(int u, int v) {

		auto u_id = find(u); // Finding ID of the first element.
		auto v_id = find(v); // Finding ID of the second element.


			// If ID is same then the set are already joint.
			if (u_id == v_id)
				return; // return from the function.

			// If ID is not common then they are different set..

			// Finding the tree with smaller height and merging it with the larger tree.
			if (sets[u_id].rank > sets[v_id].rank)
				sets[v_id].parent = u_id;

			else {

				sets[u_id].parent = v_id;

				// IF height of tree is same
				if (sets[u_id].rank == sets[v_id].rank)
					sets[v_id].rank++; // Increse it by 1.

			}

	}


	// Methods to check if two element is in same set.
	bool same_set(int u, int v) {
		return (find(u) == find(v));
	}



};

double distance(const Point2D &s, const Point2D &t) {

	return hypot(s.x - t.x, s.y - t.y);

}


double clustring(vector<Point2D> &points, int k) {

	int n = points.size();
	int nclusters{n};

	Disjoint_Set set(n);

	vector<pair<int, int> > edges;

	edges.reserve((int)n * (n - 1) / 2);

	for (int s = 0; s < n; s++)
		for (int t = s + 1; t < n; t++)
			edges.push_back({s, t});


	sort(edges.begin(), edges.end(),

		[points](pair<int, int> lhs, pair<int, int> rhs) {

			auto norm_lhs = distance(points[lhs.first], points[lhs.second]);

			auto norm_rhs = distance(points[rhs.first], points[rhs.second]);

			return norm_lhs < norm_rhs;

		} );

	int idx{0};

	while (nclusters >= k) {

		auto edge = edges[idx];

		if (set.find(edge.first) != set.find(edge.second)) {

			set.take_union(edge.first, edge.second);
			nclusters--;

		}

		idx++;
	}

	auto edge = edges[--idx];

	return distance(points[edge.first], points[edge.second]);

}

int main() {

	int n;
	cin >> n;

	vector<Point2D> points(n);

	for (int i = 0; i < n; i++)
		cin >>points[i].x >> points[i].y;

	int k;
	cin >> k;

	cout << setprecision(10) << clustring(points, k) << endl;

}