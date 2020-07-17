#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
using std::vector;

#define ll long long

int no_of_refills(int d, int m, vector<int> stops) {

	int refills = 0;
	int temp_m = m;

	int distance =0;
	int i =0;

	while (distance < m){

		if (stops[i] > m){
			// cout << "Exiting";
			return -1;
		}

		distance += stops[i];
		m -= stops[i];

		if (m >= stops[i+1]) {

		    i++;
			continue;
	    }

		else {
			refills += 1;
			m = temp_m;
		}
	}


	return refills;

}

int no_of_refills_2(int n, int d, int m, vector<int> stops) {

	int numRefills, currentRefill = 0;
	int lastRefill = 0;

	while (currentRefill < n) {

		lastRefill = currentRefill;

		while ( ( currentRefill < n ) && ( (stops[currentRefill + 1] - stops[lastRefill]) <= m ) ) {

			currentRefill = currentRefill + 1;
		}

		cout << currentRefill << "  " << stops[currentRefill] << "\n"; //printing to check

		if (currentRefill == lastRefill)
		{
			cout << "Exitings.......";
			return -1;
		}

		if ( currentRefill <= n){

				numRefills = numRefills + 1;
				cout << "Stopping at gas station...."<< "\n";
		}

		// if ((stops[currentRefill] + m) >= d)
		// {
		// 	cout << "Bullshit";
		// 	numRefills += 1;
		// 	return numRefills;
		// }
	}

	return numRefills;

}

int main()
{
	int d, m;
	int n;
	int stopValue;

	cin >> d;
	cin >> m;
	cin >> n;

	vector<int> stops(n + 2);
	stops.push_back(0);

	for (int i = 0; i < n; ++i)
	{
		cin >> stopValue;
		stops.push_back(stopValue);
	}

	stops.push_back(d);

	int refills = no_of_refills_2(n, d, m , stops);

	cout << refills;


	return 0;
}