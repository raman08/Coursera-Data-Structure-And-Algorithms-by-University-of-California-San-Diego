#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

#define ll long long

vector<ll> calculator(int n){

	std::vector<ll> steps;

	// steps[0] = 1;


	while(n >= 1 ) {
		steps.push_back(n);

		if (n % 3 == 0)
			n /= 3;

		else if (n % 2 == 0)
			n /= 2;

		else
			n -= 1;

	}

	reverse(steps.begin(), steps.end());

	return steps;
}



vector<int> optimal_sequence(int n){

	vector<int> sequence;

	vector<int> CostRecord(n+1);

	CostRecord[0] = 0;
	CostRecord[1] = 0;

	int div2, div3, minus1, prevStep;

	for(int i = 2; i < CostRecord.size(); i++){

		div2 = -1; div3 = -1; minus1 = -1, prevStep = 0;

		if(i%2 == 0)
			div2 = i/2;

		if(i%3 == 0)
			div3 = i/3;

		minus1 = i - 1;

		if(div2 == -1 && div3 != -1)
			prevStep = min(CostRecord[minus1], CostRecord[div3]);

		else if(div3 == -1 && div2 != -1)
			prevStep = min(CostRecord[minus1], CostRecord[div2]);

		else if(div2 == -1 && div3 == -1)
			prevStep = CostRecord[minus1];

		else
			prevStep = min(CostRecord[minus1], min(CostRecord[div2], CostRecord[div3]));

		CostRecord[i] = prevStep + 1;
	}

	int lastIndex = CostRecord.size()-1;
	int temp = lastIndex;

	sequence.push_back(lastIndex);

	for(int i = lastIndex-1; i >= 1; i--){

		if(CostRecord[i] == CostRecord[temp]-1){

			if(temp%i == 0 || i == (temp-1)){

				sequence.push_back(i);
				temp = i;
			}

			else
				continue;

		}
	}

	reverse(sequence.begin(), sequence.end());

	return sequence;
}


int main() {

	int n;
	cin >> n;

	vector<int> result = optimal_sequence(n);

	cout << result.size() - 1 << "\n";

	for (size_t i = 0; i < result.size(); i++) {

		cout << result[i] << " ";
	}

	return 0;
}