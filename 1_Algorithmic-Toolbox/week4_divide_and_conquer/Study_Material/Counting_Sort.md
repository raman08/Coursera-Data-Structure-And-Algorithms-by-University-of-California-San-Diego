### Counting Sort:

#### Steps:

1. Assume that all elements of A[] are integer from 1 to M.
2. By single scan of the array A, count the number if occurrences of each 1 <= k <= M in the array A and store it in count[k].
3. Use this information, fill in the sorted array A'.

#### Implementation

```

count_sort(A[]) {

	count[1...M] = 0;

	for i from 1 to n:
		count[A[i]] += 1;

	Pos[1....M] = 0;
	Pos[1] = 1;

	for j from 2 to M:
		Pos[j] = Pos[j - 1] + count[j - 1]

	for i from 1 to n:
		A'[Pos[A[i]]] = A[i]
		Pos[A[i]] += 1;

}

```
**Running time:** O(n + M)