#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long fibonacci_last_digit(int n, int mod) {

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

	return fibonacci_array[n]; //% 10;
}

int  main()
{
	int n;
	int mod = 10;
	// cout << "Enter the number:";
	cin >> n;

	long long result = fibonacci_last_digit(n, mod);


	cout << result;


	return 0;
}