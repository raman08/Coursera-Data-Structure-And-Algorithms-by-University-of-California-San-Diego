
###  Selection Sort

##### Steps

1. Find the minimun element by scanning the array.
2. Swap it with first element.
3. Repeat with the remaining part of array

```

selection_sort(A) {

	for i from 1 to n:
		minIndex = i

		for j from i + 1 to n:
			if A[j] < A[minIndex]:
				minIndex = j

		swap(A[i], A[minIndex])
}

```
**Time Complaxicity:** O(n ^ 2)
