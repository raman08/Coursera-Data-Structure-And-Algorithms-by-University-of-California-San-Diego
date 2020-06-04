#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

long long maxPairwiseProduct(const vector<int>& numbers){

	long long maxProduct = 0;

	int n = numbers.size();

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (((long long)numbers[i]) * numbers[j] > maxProduct)
			{
				maxProduct = ((long long)numbers[i] * numbers[j]);
			}
		}
	}

	return maxProduct;

}



long long maxPairwiseProductFast(const vector<int> numbers){

	// cout << "Entered Loop";

	long long result;

	int n = numbers.size();

	int maxIndex1 = -1;

	// cout << "Looping .....";

	for (int i = 0; i < n; ++i){
		if ( (maxIndex1 == -1) || (numbers[i] > numbers[maxIndex1]) ){

				maxIndex1 = i;
			}
	}

	int maxIndex2 = -1;
	for (int j = 0; j < n; ++j)
	{
		if (( j != maxIndex1) && ( (maxIndex1 == -1) || numbers[j] > numbers[maxIndex2]))
		{
			maxIndex2 = j;
		}
	}


	// cout << maxIndex1 << " " << maxIndex2 << "\n";
	// cout << "Exiting Loop";

	result =  ((long long)numbers[maxIndex1]) * numbers[maxIndex2];

	return result;


}

int  main()
{

	// while(true) {
	// 	int n  = rand() % 10 + 2;

	// 	cout << n <<"\n";

	// 	vector<int> a;

	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		a.push_back(rand() % 100000);
	// 	}

	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << a[j] << " " ;
	// 	}

	// 	cout << '\n';

	// 	long long res1 = maxPairwiseProduct(a);
	// 	long long res2 = maxPairwiseProductFast(a);

	// 	if (res1 != res2)
	// 	{
	// 		cout << "Wrong result : " << res1 << " " << res2 << '\n';
	// 		break;
	// 	}

	// 	else{

	// 		cout << "OK!!"  << "\n";
	// 	}
	// }

	int n;
	cin >> n;

	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		// cout << numbers[i];
	}

	// cout << "Entering Functions";
	// cout << maxPairwiseProduct(numbers) << "\n";
	long long result = maxPairwiseProductFast(numbers);

	cout << result;

	return 0;
}