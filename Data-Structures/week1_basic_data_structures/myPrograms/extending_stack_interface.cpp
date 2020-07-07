#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <stack>


using namespace std;
using std::vector;
using std::string;
using std::stoi;

class StackWithMax {
	vector <int> stack;
	vector <int> maxStack;


	public:

		void Push(int value) {

			stack.push_back(value);


			if (stack.size() == 1)
				maxStack.push_back(value);

			if (value > maxStack.back())
				maxStack.push_back(value);

			else
				maxStack.push_back(maxStack.back());

		}

		void Pop() {

			assert(stack.size());
			stack.pop_back();

			assert(maxStack.size());
			maxStack.pop_back();

		}

		int Max() {

			return maxStack.back();
		}


};

void printVector(vector <int> v) {

	for (int i = 0; i < v.size(); ++i)
		cout << v[i];

}

int main() {
	int q;
	cin >> q;

	string query;
	int value;

	StackWithMax stack;

	for (int i = 0; i < q; ++i) {

		cin >> query;

		if (query == "push") {
			cin >> value;
			stack.Push(value);
		}

		else if (query == "pop") {
			stack.Pop();
		}

		else if (query == "max") {
			cout << stack.Max() << endl;
		}

	}


	return 0;
}