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

		if (previous == 0 && current ==1)
			return i + 1;
	}

	return -1;
}


long long fibonacci_parial_sum(long long  n, long long m, long long mod) {


	long long pisano_period = pisanoPeriod(mod);

	n = n % pisano_period;


	long long previous = 0;
	long long current = 1;

	long long sum = 0;

	// Finding fibonacci series for new n;

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

	}

	cout << "fibonacci_array :" << "\n";

	for (int i = 0; i <= n; ++i)
	{
		cout << fibonacci_array[i] << " ";
	}

	cout << " \n";

	cout << "Sum of Series :" << " \n";

	for (int i = m; i <= n; ++i)
	{
		sum += fibonacci_array[i];

		cout <<sum << " ";
	}

	cout << "\n" << "Final Sum :" << sum << "\n\n";

	sum %= 10;

	return sum;

}


int main()
{
	long long n, m;
	int mod = 10;

	cin >> m >> n;

	long long result = fibonacci_parial_sum(n, m, mod);

	cout << result;



	return 0;
}