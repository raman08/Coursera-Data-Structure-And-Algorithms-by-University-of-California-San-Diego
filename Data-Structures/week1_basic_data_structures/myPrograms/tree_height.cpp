#include <algorithm>
#include <iostream>
#include <vector>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
using std::vector;

class Node {

public:
		int key;
		Node *parent;

		vector<Node *> children;

		Node() {
			this->parent = NULL;
		}

		void setParent(Node *theParent) {

			parent = theParent;

			parent->children.push_back(this);

		}
};

Node find_root(vector<Node> &nodes) {

	for (Node n : nodes) {

		if (n.parent == NULL)
			return n;
	}

}

int branch_max_height(Node node) {

	int max_height = 0;

	if (node.children.empty())
		return 1;

	for(int i = 0; i < node.children.size(); ++i) {

		int height = branch_max_height(*(node.children[i]));
		max_height = max(max_height, height);

	}

	max_height++;

	return max_height;
}


int main_with_large_stack_space() {

	std::ios_base::sync_with_stdio(0);

	int n;

	cin >> n;

	vector<Node> nodes;

	nodes.resize(n);

	for (int child_index = 0; child_index < n; child_index++) {

		int parent_index;
		cin >> parent_index;

		if (parent_index >= 0)
			nodes[child_index].setParent(&nodes[parent_index]);

		nodes[child_index].key = child_index;

	}

	int maxHeight = 0;

	Node root = find_root(nodes);

	maxHeight = branch_max_height(root);

	cout << maxHeight << endl;

	return 0;
}

int main (int argc, char **argv) {
	#if defined(__unix__) || defined(__APPLE__)

		const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB

		struct rlimit rl;
		int result;

		result = getrlimit(RLIMIT_STACK, &rl);

		if (result == 0) {

			if (rl.rlim_cur < kStackSize) {

				rl.rlim_cur = kStackSize;
				result = setrlimit(RLIMIT_STACK, &rl);

				if (result != 0) {
						std::cerr << "setrlimit returned result = " << result << std::endl;
				}
			}
		}

	#endif

	return main_with_large_stack_space();
}