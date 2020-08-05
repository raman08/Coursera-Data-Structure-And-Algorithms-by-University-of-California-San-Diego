#include <bits/stdc++.h>
#include <iostream>

using namespace std;


long long pisanoPeriod(long long m) {

	if(m == 1)
		return 1;

	long long previous = 0;
	long long current = 1;

	for(long long i = 0; i < (m * m); ++i) {
		long long temp = current;
		current = (current + previous) % m;
		previous = temp;

		// index = i;
		if (previous == 0 && current ==1)
			return i + 1;
	}

	return -1;
}


long long fibonacci_sum(long long  n, long long mod) {

/*
	to compute, say,
	F(2015) mod 3 we just need to find the remainder of 2015 when divided by 8.
	Since 2015 = 251 * 8 + 7, we conclude that F(2015) mod 3 = F(7) mod 3 = 1.

*/

	long long pisano_period = pisanoPeriod(mod);

	n = n % pisano_period;


	long long previous = 0;
	long long current = 1;

	long long sum = 0;

	// Finding fibonacci series for new n;

	if (n >= 1)
		sum = 1;

	long long fibonacci_array[n];

	if(n < 0){
		cout << "Number can't be negative.";
		exit(0);
	}


	fibonacci_array[0] = 0;
	fibonacci_array[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		 fibonacci_array[i]  = ((fibonacci_array[i -1] % mod ) +   (fibonacci_array[i - 2] % mod)) % mod;
		 fibonacci_array[i] %= mod;

		 sum += fibonacci_array[i];
	}

	sum %= 10;



	return sum;

}


int main()
{
	long long n;
	int mod = 10;

	cin >> n;

	long long result = fibonacci_sum(n, mod);

	cout << result;



	return 0;
}