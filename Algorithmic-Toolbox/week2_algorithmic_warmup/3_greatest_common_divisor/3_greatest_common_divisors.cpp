// Computing Greatest Common Divisors...

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int gcd_native(int a, int b){

	int current_gcd = 1;

	for (int i = 2; i <= a && i <= b; ++i){
		if (a % i == 0 && b % i == 0){
			if(i > current_gcd){
				current_gcd = i;
			}
		}
	}

	return current_gcd;
}

/*	How it works :
		We find a' = a % b
		then gcd(a, b) = gcd(a', b) = gcd(b, a')

		Proof ::
			Sincd a = a' + bq for some q then:
				d divides both a and b if and only if d divide a' and b.
				(d is the gcd.........)

	This method is called Eucliden Algorithm
*/

int eucliden_gcd(int a, int b){

	if (b == 0){
		 return  a;
	}

	return eucliden_gcd(b, a % b);
}

int main()
{


	// Test snippet


	// while(true) {
	// 	int a = rand() % 100 + 2;
	// 	int b = rand() % 100 + 2;

	// 	cout << a  << " " << b<<"\n";


	// 	float res1 = gcd_native(a, b);
	// 	int res2 = gcd_naive_test(a, b);

	// 	if (res1 != res2)
	// 	{
	// 		cout << "Wrong result : " << res1 << " " << res2 << '\n';
	// 		break;
	// 	}

	// 	else{

	// 		cout << "OK!!"  << "\n";
	// 	}
	// }


	int a, b;
	long long result;

	// cout << "Enter 2 Numbers whose Greatest Common Divisors you want to calculate:";

	cin >> a >> b;

	result = eucliden_gcd(a, b);

	cout << result;
	return 0;
}