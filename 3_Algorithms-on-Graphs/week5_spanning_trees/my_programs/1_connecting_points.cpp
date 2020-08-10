#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

struct Point2D {

	int x, y;

	Point2D() : x(0), y(0) {};

	Point2D(int x, int y) : x(x), y(y) {};

};

struct Node {

	size_t index;
	double dist;

	Node(size_t index, double dist) : index(index), dist(dist) {};

	bool operator>(const Node &rhs) const {
		return dist > rhs.dist;
	}

};

double distance(const Point2D &s, const Point2D &t) {

	return hypot(s.x - t.x, s.y - t.y);

}


double min_distance(vector<Point2D> &points) {

	vector<double> dist(points.size(), INT_MAX);

	dist[0] = 0;

	priority_queue<Node, vector<Node>, greater<Node> > pq;
	pq.push(Node(0, 0));

	set<int> processed;

	set<int> missing;

	for (int i = 0; i < points.size(); i++)
		missing.insert(i);

	double result = 0;

	while(not pq.empty()) {

		auto min = pq.top();
		pq.pop();

		if (processed.find(min.index) != processed.end())
			continue;


		result += min.dist;
		missing.erase(min.index);

		for (auto i : missing) {

			auto d = distance(points[min.index], points[i]);

			if (d < dist[i]) {

				dist[i] = d;
				pq.push(Node(i, d));

			}
		}

		processed.insert(min.index);

	}

	return result;

}


int main() {

	int n;
	cin >> n;

	vector<Point2D> points(n);

	for (int i = 0; i < n; i++)
		cin >> points[i].x >> points[i].y;

	cout << setprecision(10) << min_distance(points) << endl;
}