#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

ll change;

ll moneyChange(int m) {

	while(m) {

		if (m >= 10) {
			m -= 10;
			change += 1;
		}

		else if (m >= 5){
			m -= 5;
			change += 1;

		}
		else {
			m -= 1;
			change += 1;
		}

	}

	return change;

}



int main()
{
	ll m;

	cin >> m;

	change = moneyChange(m);

	cout << change;

	return 0;
}