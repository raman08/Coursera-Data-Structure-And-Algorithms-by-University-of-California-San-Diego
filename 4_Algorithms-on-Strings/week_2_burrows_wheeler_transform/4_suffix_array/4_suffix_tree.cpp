#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node {

	int next{0};
	int start{0};
	int end{0};
	int suffix_start{0};

};

using Edges = map<char, Node>;


class Suffix_tree {

	string text;
	int Length;

	int count;
	int ROOT;

	vector<Edges> tree;



public:

	Suffix_tree(const string& text) {

		this->text = text;

		Length = text.size();

		count = 1;
		ROOT = 0;


		// tree.reserve(Length / 10);
		tree.emplace_back(Edges{} );

	}

	inline void add_node(int start, int i, int suffix_start) {

		tree[i].emplace(make_pair(text[start], Node { count++, start, Length, suffix_start }));

		tree.emplace_back( Edges{} );

	}

	inline void add_nodes_branching(Node& node, int k, int m, int suffix_start) {

		if (!tree[node.next].empty()) {

			tree.emplace_back(Edges {});
			tree.emplace_back(Edges {});

			tree[count] = move(tree[node.next]);

			tree[node.next].emplace(make_pair(text[m], Node{count++, m, node.end, suffix_start }));

			tree[node.next].emplace(make_pair(text[k], Node{count++, k, Length, suffix_start }));

			node.end = m;

		}

		else {

			add_node(k, node.next, suffix_start);
			add_node(m, node.next, node.suffix_start);

			node.end = m;

		}
	}


	void print_suffix_array( int level = 0) {

		for (const auto& it : tree[level]) {

			if (!tree[it.second.next].empty())
				print_suffix_array(it.second.next);

			else
				cout << it.second.suffix_start << " ";

		}
	}


	void build_tree() {

		for (int j = 0; j < Length; j++) {

			int cur = ROOT;

			for (int k = j; true; ) {

				auto it = tree[cur].find(text[k]);

				if (it == tree[cur].end()) {

					add_node(k, cur, j);
					break;

				}

				Node& node = it->second;
				int m = node.start;

				for(; k < Length && m < node.end; k++, m++) {

					if (text[k] != text[m]) {

						add_nodes_branching(node, k, m, j);

						goto inner_loop_wayout;

					}
				}


				if (m == node.end && k == Length)
					break;


				else if (m == node.end) {

					if (tree[node.next].empty()) {

						add_node(k, node.next, j);
						break;

					}

					cur = node.next;
					continue;

				}

				else {

					if (tree[node.next].empty()) {

						add_node(m, node.next, j);

						break;

					}

					tree.emplace_back(Edges {});
					tree[count].emplace(make_pair(text[m], Node {node.next, m, node.end, j }));

					node.next = count;
					node.end = m;

					break;

				}

				inner_loop_wayout:
					break;

			}
		}
	}

};


int main() {

	string text;
	cin >> text;

	Suffix_tree suffix_tree(text);

	suffix_tree.build_tree();
	suffix_tree.print_suffix_array();

	return 0;

}