
### Linear Search

The problem statement for linear search is as follows:

Given an unsorted array with n elements in it and a key k, find an index, i of the array element that's equal to k.
If no element array is equal to k, the output should be NOT_FOUND.

##### Idea

To find a particular element of the array, we look at the first element, if it's not there, we look at the second element. We continue until we either find the element we're interested in, or until we reach the end of the array.


**Input:**

- A, the array of values
- low: the lower bound of the array in which to search
- high: the upper bound of the array in which to search
- k: the key for which to search.

**Output:**	An index in the range low to high, if it finds a matching value, or NOT_FOUND, if it finds no such match.


#### Linear Search Recursive

```

LinearSerach(A, low, high, key){

		if high < low
			return Not_foud

		if A[low] == key
			return low

		return LinearSerach(A, low + 1, high, key)

}

```

#### Linear Search Iterative

```

LinearSerach(A, low, high, key){

  for i from low to high:
	if A[i] == key:
  		return i

  return Not_Found

}

```

**Runtime:** O(n)
