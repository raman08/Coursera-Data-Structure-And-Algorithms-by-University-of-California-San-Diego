#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <array>

#define ll long long

using namespace std;
using std::vector;
using std::string;

struct Quaries {

	string str, type;
	int index;

};

class QuaryProcessor {

	int bucket_count;

	vector<list<string>> elements;

	size_t hashFunction(const string& str) const {

		static const size_t x = 263;
		static const size_t p = 1000000007;
		unsigned ll hash = 0;

		for (int i = static_cast<int>(str.size()) - 1; i >= 0 ; --i) {
				hash = (( (hash * x + str[i]) % p) + p ) % p;
			}

		return hash % bucket_count;

	}


public:

	explicit QuaryProcessor(int bucket_count) {

		this->bucket_count = bucket_count;

		list<string> l;

		for(size_t i = 0; i < bucket_count; ++i) {
			this->elements.push_back(l);
		}
	}



	Quaries read_data() const {

		Quaries quary;

		cin >> quary.type;

		if (quary.type == "check")
			cin >> quary.index;

		else
			cin >> quary.str;

		return quary;

	}



	void write_data(bool was_found) const {

		cout << (was_found ? "yes\n" : "no\n");

	}



	void process_quaries(const Quaries& quary) {

		if (quary.type == "check") {

			if (quary.index < elements.size()) {

				auto L = elements[quary.index];

				for (auto s : L) {
					cout << s << " ";
				}

				cout << endl;
			}
		}

		else {

			size_t hash_ind = hashFunction(quary.str);

			auto it = find(elements[hash_ind].begin(), elements[hash_ind].end(), quary.str);

			if (quary.type == "find")
				write_data(it != elements[hash_ind].end());

			else if (quary.type == "add") {

				if (it == elements[hash_ind].end())
					elements[hash_ind].push_front(quary.str);

			}

			else if (quary.type == "del") {

				if (it != elements[hash_ind].end())
					elements[hash_ind].erase(it);
			}

		}


	}

	void processQueries() {

        int n;
        cin >> n;

		vector<Quaries> queries(n);

		for (int i = 0; i < n; ++i)
			queries[i] = read_data();

		for (int i = 0; i < n; ++i)
            process_quaries(queries[i]);

		cout << endl;

    }

};


int main() {

	std::ios_base::sync_with_stdio(false);

	int bucket_count;
	cin >> bucket_count;

	QuaryProcessor proc(bucket_count);

	proc.processQueries();

	return 0;

}