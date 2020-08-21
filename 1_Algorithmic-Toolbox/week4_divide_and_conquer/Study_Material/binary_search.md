### Binary Search

**Input:**

 - A, an  **sorted array**
 - low and upper bound that specify the bounds within the array in which to search.
 - Key to search

**Output:**
 an index such that the element at that index in the array is equal to the key. If we don't have a match, return is the greatest index, such that A[i] is less than key. (A[i] < key) else return -1.


#### Binary Search Recursive

```

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

```

#### Binary Search Iterative

```

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

```


##### Binary Search Recurrence Relation

T(n) = T(n // 2) + c

T(0) = c

**Running Time:** O( log(n) )

