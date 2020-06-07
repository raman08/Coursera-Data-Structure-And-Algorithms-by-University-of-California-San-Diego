#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int minRefills(int x[n + 1], int n , int L ){

	int num_refills, current_refills = 0;

	while(current_refills <= n) {

	    int last_refills = current_refills;
	    while(current_refills <= n && x[current_refills +1] - x[last_refills]) {

	        current_refills += 1;

	    }

	 if (current_refills == last_refills)
	 {
	 	return -1;
	 }

	 if (current_refills <= n){

	 	num_refills += 1;
	 }

	}

	return num_refills;

}