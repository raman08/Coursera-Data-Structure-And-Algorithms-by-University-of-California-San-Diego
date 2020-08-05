#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long eucliden_gcd(long long a, long long b){

	if (b == 0){
		 return  a;
	}

	return eucliden_gcd(b, a % b);
}

int main()
{
	long long a, b;
	long long result;

	// cout << "Enter 2 Numbers whose Greatest Common Divisors you want to calculate:";

	cin >> a >> b;

	result = eucliden_gcd(a, b);

	long long lcm = (a / result) * b;

	cout << lcm;
	return 0;
}