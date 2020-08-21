#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Node {

		Node(int next, int start, int end)
		: next(next), start(start), end(end) {}

		int start = 0;
		int end = 0;
		int next = 0;

};


using Edges = vector<Node>;


class SuffixTree {

	string text;
	int LENGTH;

	vector<Edges> tree;

	int current;
	int ROOT;


public:

	SuffixTree(const string& text) {

		this->text = text;
		LENGTH = text.size();

		current = 1;
		ROOT = 0;

		tree.reserve(LENGTH / 10);
		tree.emplace_back( Edges {} );

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




	void display() {

		for (const auto& edges : tree)
			for (const auto& e: edges) {

				for (int i = e.start; i < e.end; i++)
					cout << text[i];

				cout << endl;

			}
	}


};


int main() {

	string text;
	cin >> text;

	SuffixTree suffixTree(text);

	suffixTree.build_tree();

	suffixTree.display();

	return 0;

}