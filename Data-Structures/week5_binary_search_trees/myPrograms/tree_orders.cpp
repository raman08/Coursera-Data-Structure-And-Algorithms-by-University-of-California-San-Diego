#include <iostream>
#include <vector>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

#define ll long long

using namespace std;
using std::vector;

class TreeOrders {

	int n;
	vector<int> key;
	vector<int> left;
	vector<int> right;

public:

	void read() {

		cin >> n;

		key.resize(n);
		left.resize(n);
		right.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> key[i] >> left[i] >> right[i];
		}

	}

	void in_order_node(vector<int> &result, int node) {

		if (node == -1)
			return;

		else {

			in_order_node(result, this->left[node]);
			result.push_back(this->key[node]);
			in_order_node(result, this->right[node]);

		}
	}

	void pre_order_node(vector<int> &result, int node) {

		if (node == -1)
			return;

		else {

			result.push_back(this->key[node]);
			pre_order_node(result, this->left[node]);
			pre_order_node(result, this->right[node]);

		}

	}

	void post_order_node(vector<int> &result, int node) {

		if (node == -1)
			return;

		else {

			post_order_node(result, this->left[node]);
			post_order_node(result, this->right[node]);
			result.push_back(this->key[node]);

		}

	}

	vector<int> in_order() {

		vector<int> result;

		in_order_node(result, 0);

		return result;

	}

	vector<int> pre_order() {

		vector<int> result;

		pre_order_node(result, 0);

		return result;

	}

	vector<int> post_order() {

		vector<int> result;

		post_order_node(result, 0);

		return result;

	}

};


void print(vector<int> a) {

	for (int i = 0; i < a.size(); ++i)
	{
		if (i > 0)
			cout << " ";

		cout << a[i];

	}

	cout << "\n";

}
int main_with_large_stack_space() {

	ios_base::sync_with_stdio(0);

	TreeOrders tree;

	tree.read();

	print(tree.in_order());
	print(tree.pre_order());
	print(tree.post_order());

	return 0;


}


int main() {

	#if defined(__unix__) || defined(__APPLE__)

		const rlim_t kStackSize = 16 * 1024 * 1024;

		struct rlimit rl;
		int result;

		result = getrlimit(RLIMIT_STACK, &rl);

		if (result != 0){

			if (rl.rlim_cur < kStackSize){

				rl.rlim_cur = kStackSize;

				result = setrlimit(RLIMIT_STACK, &rl);

				cerr << "Setrlimit returned result = " << result << endl;
			}
		}

	#endif

	return main_with_large_stack_space();

}