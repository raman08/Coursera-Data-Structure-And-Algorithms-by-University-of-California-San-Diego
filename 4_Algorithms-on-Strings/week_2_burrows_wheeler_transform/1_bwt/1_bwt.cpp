#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



string BWT(string text) {

	string result = "";

	vector<string> rotations(text.size());

	for (int i = 0; i < text.size(); i++)
		rotations[i] = text.substr(text.size() - i) + text.substr(0, text.size() - i);

	sort(rotations.begin(), rotations.end());

	for (int i = 0; i < rotations.size(); i++)
		result += rotations[i].back();

	return result;

}

int main() {

	string text;
	cin >> text;

	cout << BWT(text) << endl;

	return 0;

}