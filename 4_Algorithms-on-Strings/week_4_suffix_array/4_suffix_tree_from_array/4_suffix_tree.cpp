#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>


using namespace std;

struct Suffix_Tree_Node {

	Suffix_Tree_Node* parent{ nullptr };
	map<char, Suffix_Tree_Node*> children;

	int string_depth{ 0 };
	int edge_start{ -1 };
	int edge_end{ - 1 };

};

Suffix_Tree_Node snode_buf[400000];
int cur_buf_index = 0;

inline Suffix_Tree_Node* new_tree_node(Suffix_Tree_Node* parent, int depth, int start, int end) {

	snode_buf[cur_buf_index].parent = parent;
	snode_buf[cur_buf_index].string_depth = depth;
	snode_buf[cur_buf_index].edge_start = start;
	snode_buf[cur_buf_index].edge_end = end;

	return &(snode_buf[cur_buf_index++]);

}

inline Suffix_Tree_Node* create_new_leaf(Suffix_Tree_Node* node, const string& S, int suffix) {

	Suffix_Tree_Node* leaf  = new_tree_node(node, S.size() - suffix, suffix + node->string_depth, S.size() - 1);

	node->children[S[leaf->edge_start]] = leaf;

	return leaf;

}

inline Suffix_Tree_Node* break_edge(Suffix_Tree_Node* node, const string& S, int start, int offset) {

	char start_char = S[start];
	char mid_char = S[start + offset];

	Suffix_Tree_Node* mid_node = new_tree_node(node, node->string_depth + offset, start, start + offset - 1);

	mid_node->children[mid_char] = node->children[start_char];
	node->children[start_char]->parent = mid_node;
	node->children[start_char]->edge_start += offset;
	node->children[start_char] = mid_node;

	return mid_node;

}

Suffix_Tree_Node* build_suffix_tree(const string& S, const vector<int>& order, const vector<int>& lcp_array) {

	Suffix_Tree_Node* root = new_tree_node(nullptr, 0, -1 , -1);

	Suffix_Tree_Node* cur_node = root;

	int lcp_prev = 0;

	const int N = S.size();

	for(int i = 0; i < N; i++) {

		auto suffix = order[i];

		while (cur_node->string_depth > lcp_prev)
			cur_node = cur_node->parent;

		if (cur_node->string_depth == lcp_prev)
			cur_node = create_new_leaf(cur_node, S, suffix);

		else {

			int edge_start = order[i - 1] + cur_node->string_depth;

			int offset = lcp_prev - cur_node->string_depth;
			Suffix_Tree_Node* mid_node = break_edge(cur_node, S, edge_start, offset);
			cur_node = create_new_leaf(mid_node, S, suffix);

		}

		if (i < N - 1)
			lcp_prev = lcp_array[i];

	}

	return root;

}

void preorder_print(Suffix_Tree_Node* root) {

	stack<Suffix_Tree_Node*> node_stack;

	for (auto iter = root->children.rbegin(); iter != root->children.rend(); iter++)
		node_stack.push(iter->second);

	while (!node_stack.empty()) {

		Suffix_Tree_Node* node = node_stack.top();
		node_stack.pop();

		cout << node->edge_start << " " <<node->edge_end + 1 << endl;

		for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
			node_stack.push(it->second);

	}

}

int main() {

	std::ios::sync_with_stdio(false);

	string text;
	cin >> text;

	vector<int> suffix_array(text.size());
	vector<int> lcp_array(text.size() - 1);

	for (int i = 0; i < text.size(); i++) {

		cin >> suffix_array[i];

	}

	for (int i = 0; i < text.size() - 1; i++) {

		cin >> lcp_array[i];

	}


	auto root = build_suffix_tree(text, suffix_array, lcp_array);

	cout << text << endl;

	preorder_print(root);

	return 0;

}