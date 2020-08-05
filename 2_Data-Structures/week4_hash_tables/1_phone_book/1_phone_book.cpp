#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;
using std::vector;
using std::string;

struct Quaries {

	string type, name;
	int number;

};

vector<Quaries> read_data() {

	int N;
	cin >> N;

	vector<Quaries> quary(N);

	for (int i = 0; i < N; ++i) {

		cin >> quary[i].type;

		if (quary[i].type == "add")
			cin >> quary[i].number >> quary[i].name;

		else
			cin >> quary[i].number;

	}

	return quary;

}


void write_responce(const vector<string>& result) {

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}

}


vector<string> process_quaries(vector<Quaries> quary) {

	vector<string> result;

	const int contact_size = 10000000;
	vector<string> contacts(contact_size);

	for(size_t i = 0; i < quary.size(); ++i) {

		if(quary[i].type == "add") {
			contacts[quary[i].number] = quary[i].name;
		}

		else if(quary[i].type == "del") {
			contacts[quary[i].number] = "";
		}

		else {

			if (contacts[quary[i].number] == "")
				result.push_back("not found");

			else
				result.push_back(contacts[quary[i].number]);
		}


	}

	return result;

}


int main() {

	write_responce(process_quaries(read_data()));

	return 0;

}