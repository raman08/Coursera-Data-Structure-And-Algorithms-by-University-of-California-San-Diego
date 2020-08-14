#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum class NodeProperties {

	OnlyLTypeLeafs,
	OnlyRTypeLeafs,
	RTypeAndLtypeLeafs,
	None

};

struct Node {

	Node(int next, int start, int end):
		next(next),
		start(start),
		end(end) {}


	int next = 0;
	int start = 0;
	int end = 0;


};

using Edges = vector<Node>;


class SuffixTree {

	string text;
	int LENGTH;
	int first, second;

	vector<Edges> tree;

	int current;
	int ROOT;

	vector<string> substrings;



public:

	SuffixTree(const string& text, int second) {

			this->text = text;

			LENGTH = text.size();

			first = 0;
			this->second = second;

			current = 1;
			ROOT = 0;

			tree.emplace_back(Edges {} );
			// tree.reserve(LENGTH / 10);

	}


	inline void add_node(int start, int i) {

		tree.emplace_back(Edges{});
		tree[i].emplace_back(Node(current++, start, LENGTH));

	}

	inline void add_nodes_branching(Node& node, int k, int m) {

		if (!tree[node.next].empty()) {

			tree.emplace_back(Edges {});
			tree.emplace_back(Edges {});

			tree[current] = move(tree[node.next]);

			tree[node.next].emplace_back(Node(current++, m, node.end));
			tree[node.next].emplace_back(Node(current++, k, LENGTH));

			node.end = m;

		}

		else {

			add_node(m, node.next);
			add_node(k, node.next);
			node.end = m;

		}
	}




	void build_tree() noexcept {

		for (int j = 0; j < LENGTH; j++) {

			int current = ROOT;

			for (int k = j; true;) {

				char symbol = text[k];

				auto it = find_if(tree[current].begin(), tree[current].end(), [&] (const Node& n) {

					return text[n.start] == symbol;

				});

				if (it == tree[current].end()) {

					add_node(k, current);
					break;

				}

				Node& node = *it;
				int m = node.start;

				for (; k < LENGTH && m < node.end; k++, m++) {

					if (text[k] != text[m]) {

						add_nodes_branching(node, k, m);

						goto inner_loop_wayout;

					}
				}

				if (m == node.end && k == LENGTH)
					break;

				else if (m == node.end) {

					if (tree[node.next].empty()) {

						add_node(k, node.next);
						break;

					}

					current = node.next;
					continue;

				}

				else {

					if (tree[node.next].empty()) {

						add_node(m, node.next);
						node.end = m;
						break;

					}

					tree.emplace_back(Edges {});
					tree[current].emplace_back(Node(node.next, m, node.end));

					node.next = current;
					node.end = m;
					break;

				}

				inner_loop_wayout:
					break;


			}
		}
	}



	NodeProperties search_leafs(int node, string s = "") {

		bool is_L_type_leaf = false;
		bool is_R_type_leaf = false;

		for (Node& n : tree[node]) {

			NodeProperties np = search_leafs(n.next, s + text.substr(n.start, n.end - n.start));

			if (np == NodeProperties::OnlyLTypeLeafs) {

				is_L_type_leaf = true;

				if (node == 0)
					substrings.emplace_back(text.substr(n.start, n.end - n.start));

			}

			else if (np == NodeProperties::OnlyRTypeLeafs)
				is_R_type_leaf = true;

			else if (np == NodeProperties::RTypeAndLtypeLeafs) {

				is_R_type_leaf = true;
				is_L_type_leaf = true;

			}

			else {

				for (int i = n.start; i < n.end; i++) {

					if (text[i] == '$') {

						is_R_type_leaf = true;

						break;

					}

					if (text[i] == '#') {

						is_L_type_leaf = true;

						break;

					}
				}
			}
		}


		if (is_R_type_leaf && is_L_type_leaf) {


			for (Node& n : tree[node]) {

				if (text[n.start] =='#' || text[n.start] == '$')
					continue;

				for (int i = n.start; i < n.end; i++) {

					if (text[i] == '#') {

						substrings.emplace_back(s + text[n.start]);

						break;

					}
				}
			}

			return NodeProperties::RTypeAndLtypeLeafs;

		}

		else if (!is_R_type_leaf && is_L_type_leaf) {

			for (Node& n : tree[node]) {

				if (text[n.start] == '$')
					continue;

				for (int i = n.start; i < n.end; i++) {

					if (text[i] == '#') {

						substrings.emplace_back(s);
						break;
					}
				}
			}

			return NodeProperties::OnlyLTypeLeafs;
		}


		else if (is_R_type_leaf && !is_L_type_leaf) {

			return NodeProperties::OnlyRTypeLeafs;

		}

		else {

			return NodeProperties::None;

		}
	}




	void display_edges() {

		for (const auto& edges : tree)
			for (const auto& e: edges) {

				for (int i = e.start; i < e.end; i++)
					cout << text[i];

				cout << endl;

			}
	}



	void print_non_shared_substring() {

		search_leafs(0);

		int max_size = 100000;
		int k = 0;

		for (int i = 0; i < substrings.size(); i++) {

			if (substrings[i].size() < max_size) {

				k = i;
				max_size = substrings[i].size();

			}
		}

		cout << substrings[k] << endl;

	}

};


int main() {

	string text1;
	cin >> text1;

	string text2;
	cin >> text2;

	text1 += "#" + text2 + "$";

	SuffixTree suffixTree(text1, text2.size() + 1);

	suffixTree.build_tree();

	suffixTree.print_non_shared_substring();

	return 0;

}