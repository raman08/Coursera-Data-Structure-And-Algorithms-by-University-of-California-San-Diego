#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
	x is the array of coordinates of the gas stations.
 	n is the number of gas stations.
 	L is the farthest distance a car can travel without refueling.
 	lastRefill is the index of the previous gas station visited.
 	currentRefill is used to enumerate the position of the next gas station we are going to stop in.

*/
int minRefills(int x[n + 1], int n , int L ){

	int num_refills, current_refills = 0;

	while(current_refills <= n) {

	    int last_refills = current_refills;
	    while(current_refills <= n && x[current_refills +1] - x[last_refills] <= L) {

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