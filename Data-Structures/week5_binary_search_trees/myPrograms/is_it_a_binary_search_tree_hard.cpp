#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

#define ll long long

#define INT_MIN     (-9223372036854775807 - 1)
#define INT_MAX       9223372036854775807



struct Node {

	int key;
	int left;
	int right;

	Node() : key(0), left(-1), right(-1) {}
	Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}

};



bool isBSTUtil(const vector<Node>& tree, const int &node_index, ll min, ll max) {

	if (node_index == -1)
		return true;

	if (tree[node_index].key < min || tree[node_index].key >= max)
		return false;

	return

		isBSTUtil(tree, tree[node_index].left, min, tree[node_index].key) &&
		isBSTUtil(tree, tree[node_index].right, tree[node_index].key, max);

}

bool isBinarySearchTree(const vector<Node>& tree) {

	if (tree.size() == 0)
		return true;

	return isBSTUtil(tree, 0, INT_MIN, INT_MAX);

}

int main() {

	int nodes;
	cin >> nodes;

	vector<Node> tree;

	for (int i = 0; i < nodes; ++i) {

		int key, left, right;
		cin >> key >> left >> right;

		tree.push_back(Node(key, left, right));

	}


	if (isBinarySearchTree(tree))
		cout << "CORRECT" << endl;

	else
		cout << "INCORRECT" << endl;


	return 0;
}