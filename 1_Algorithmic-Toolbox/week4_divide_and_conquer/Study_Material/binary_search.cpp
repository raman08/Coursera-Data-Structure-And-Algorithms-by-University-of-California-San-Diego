/*
	The problem statement for binary search is as follows:
	 	So what we have coming in is, A, an  sorted array, along with a low and upper bound that specify the bounds within the array in which to search.

	 	A[i] <= A[i + 1]


	 	The output for this is an index such that the element at that index in the array is equal to the key. If we don't have a match, we're going to return where in the array would you actually insert the element if you wanted to insert it? Or where would it have been, if it were there? So what we're going to return is the greatest index, such that A sub i is less than k. (A[i] < key) else return -1.


	Phuso code:

		Recursion Version:

			BinarySearch(A, low, high, key) {

				if high < low
					return low - 1

				mid = low + floor( (high - low)/ 2 )

				if  key == A[mid]
					return mid

				else if key < A[mid]
					return BinarySearch(A, low, mid -1 , key)

				else
					reurn BinarySearch(A, mid + 1, high, key)

			}

		Iterative Version:

			BinarySearch(A, low, high, key) {

				while ( low <= high) {

					mid = low + floor( (high - low)/ 2 )

					if  key == A[mid]
						return mid

					else if key < A[mid]
						high = mid - 1

					else
						low = mid + 1
				}

				reutrn low  - 1
			}



	Binary Search Recurrence Relation

		T(n) = T(n // 2) + c

		T(0) = c

		Runtine = theta(log(n)) [base 2]

*/


int BinarySearch(int A[], int low, int high, int key) {

	if (low > high)
		return low - 1;

	int mid = low + (high - low) /2;

	if (key == A[mid])
		return mid;

	else if (key < A[mid])
		return BinarySearch(A, low, mid -1, key);

	else
		return BinarySearch(A, mid + 1, high, key);
}

int BinarySearch_iterative(A, low, high, key) {

	while (low <= high) {

		mid = low + floor( (high - low)/ 2 );

		if  (key == A[mid])
			return mid;

		else if (key < A[mid])
			high = mid - 1;

		else
			low = mid + 1;
	}

	reutrn low - 1;
}