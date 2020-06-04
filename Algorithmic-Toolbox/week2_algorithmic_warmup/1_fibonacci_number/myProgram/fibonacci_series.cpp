/*  Calculating the fibonacci series*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// Native Approch of computing by resurrsion....

long long fibonacci_native(int n){

	long long fibonacci_result;

	if(n < 0){
		cout << "Number can't be negative.";
		exit(0);
	}

	else if (n <= 1)
		fibonacci_result = n;
	else {

		fibonacci_result = fibonacci_native(n -1) + fibonacci_native(n -2);
	}

	return fibonacci_result;

}

//  List method of storing in the list.....

long long fibonacci_fast(int n) {

	long long fibonacci_array[n];

	if(n < 0){
		cout << "Number can't be negative.";
		exit(0);
	}


	fibonacci_array[0] = 0;
	fibonacci_array[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		fibonacci_array[i] = fibonacci_array[i -1] + fibonacci_array[i - 2];
	}

	return fibonacci_array[n];
}

int  main()
{
	int n;
	cout << "Enter the number:";
	cin >> n;

	long long result = fibonacci_fast(n);


	cout << result;


	return 0;
}