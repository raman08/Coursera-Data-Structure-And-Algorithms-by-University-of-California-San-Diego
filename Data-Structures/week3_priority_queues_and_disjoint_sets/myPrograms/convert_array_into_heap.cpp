#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using std::vector;

class HeapBuilder {

	vector<int> data;
	vector<pair<int, int> > swap_data;

	void showdata() const {

		// cout << "showdata running...." << endl;

		cout << swap_data.size() << endl;

		for (int i = 0; i < swap_data.size(); ++i)
			cout << swap_data[i].first << " " << swap_data[i].second << endl;
	}


	void read_data() {

		// cout << "read_data running...." << endl;


		int n;
		cin >> n;

		data.resize(n);

		for (int i = 0; i < n; ++i)
			cin >> data[i];
	}


	int parent(int child) {
		return int( (child + 1) / 2);
	}


	int left_child(int parent) {
		return 2 * parent + 1;
	}


	int right_child(int parent) {
		return 2 * parent + 2;
	}



	void bubble_down(int index) {

		int min_index = index;

		int left_index = left_child(index);
		int right_index = right_child(index);

		if ( (left_index < data.size() ) && (data[left_index] < data[min_index]) )
			min_index = left_index;

		if ( (right_index < data.size() ) && (data[right_index] < data[min_index]) )
			min_index = right_index;

		if (min_index != index) {

			swap(data[index], data[min_index]);
			swap_data.push_back(make_pair(index, min_index));
			bubble_down(min_index);

		}

	}


	void count_swap() {

		// cout << "count_swap running...." << endl;


		for (int i = int(data.size() / 2); i>=0; i--) {

			// cout << "bubble_down no " << i<< " running...." << endl;

			bubble_down(i);
		}

	}

public:

	void solve() {

		read_data();
		count_swap();
		showdata();

	}

};


int main()
{
	std::ios_base::sync_with_stdio(false);

	HeapBuilder heapbuilder;
	heapbuilder.solve();

	return 0;
}