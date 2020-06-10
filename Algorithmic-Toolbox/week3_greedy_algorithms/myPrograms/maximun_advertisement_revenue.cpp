#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
using std::vector;

#define ll long long

ll revenue_calculate(int n, vector<ll> profit, vector<ll> clicks) {

	int revenue = 0;

	sort(profit.begin(), profit.end());
	sort(clicks.begin(), clicks.end());

	for (int i = 0; i < n; ++i)
	{
		cout << profit[i] << "  ";
	}


	for (int i = 0; i < n; ++i)
	{
		cout << clicks[i] << "  ";
	}

	cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		revenue += (profit[i] * clicks[i]);
	}

	return revenue;
}


int main() {

	int n;
	vector<ll> profit(n);
	vector<ll> clicks(n);


	// ll profit[n];
	// ll clicks[n];

	cin >> n;

	// profit.reserve(n);
	// clicks.reserve(n);


	for (int i = 0; i < n; ++i)
	{
		cin >> profit[i];
	}


	for (int i = 0; i < n; ++i)
	{
		cin >> clicks[i];
	}


	ll revenue = revenue_calculate(n, profit, clicks);


	// ll revenue = CalcIt(profit, clicks, n);
	cout  << revenue;



	return 0;
}