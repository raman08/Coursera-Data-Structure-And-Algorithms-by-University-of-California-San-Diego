/*
	 To find a particular element of the array, we look at the first element, if it's not there, we look at the second element. We continue until we either find the element we're interested in, or until we reach the end of the array.

	 The problem statement for linear search is as follows:

		 Given an unsorted array with n elements in it and a key k, find an index, i of the array element that's equal to k. If no element array is equal to k, the output should be NOT_FOUND.

	Our recursive function will take four parameters:
	 	A, the array of values:
	 	low: the lower bound of the array in which to search;
		high:the upper bound of the array in which to search;
	 	and k: the key for which to search.

	It will return either:
		an index in the range low to high, if it finds a matching value;
		or NOT_FOUND, if it finds no such match.

	We'll recursively search through that smaller sub array, and then just return the result of the recursive search.


	Psudo code:

		Recursion Method:
			LinearSerach(A, low, high, key){
				if high < low
					return Not_foud

				if A[low] == key
					return low

				return LinearSerach(A, low + 1, high, key)
			}

		Iterative Method:
			LinearSerach(A, low, high, key){
				for i from low to high:
					if A[i] == key:
						return i

				return Not_Found
			}






	Runtine of linerar rearch:

		The worst-case time is when an element isn't found because we must check every element of the array. In this case we have a recursion for a problem of size n which consists of a subproblem of size n minus one plus a constant amount of work. The constant amount of work includes checking high versus low, checking A at low equals key, preparing the parameters for the recursive call, and then returning the result of that call. Thus the recurrence is T(n) equals T(n-1) plus c, where c is some constant.

		The base case of the recursion is in an empty array, there's a constant amount of work: checking high less than low and then returning NOT_FOUND. Thus T(0) equals c.

			T(n) = T(n + 1) + c
			T(0) = c

		Runtime = theta(n)



*/


int LinearSerach(int A[], int low, int high, int key) {

	if high < low
		return -1;

	if A[low] == key
		return low;

	LinearSerach(A[], low + 1, high, key);

}



int LinearSerach_Iteration(int A[], int low, int high, int key) {

	for (int i = low; i < high; ++i)
	{
		if A[i] == key
			return i;
	}

	return -1;
}