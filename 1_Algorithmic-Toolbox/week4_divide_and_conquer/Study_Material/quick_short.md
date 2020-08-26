## Qick Sort

- The algorithm is comparison based, meaning that it sorts the n given elements by comparing pairs of them.

- Its running time is also asymptotically n log(n), but not in the worst case, as was with the merge sort algorithm,  but on the average case.

- This is because this algorithm is randomized, so it uses random numbers to sort the given n objects.

### Implementation

- **A:**  Given Array
- **l, r:** Lower and Upper bond

##### Recursive Method

```

Quick_sort(A, l, r) {

	if l>= r:
		return;

	m = Partition(A, l, r)

	Quick_sort(A, l, m - 1)
	Quick_sort(A, m + 1, r)

}

```

##### Tail Recursion Method

```
Quick_sort(A, l, r) {

	while l < r:
		m = Partition(A, l, r)

		if (m - l) < (r - m):
			Quick_sort(A, l, m - 1)
			l = m + 1

		else:
			Quick_sort(A, m + 1, r)
			r = m - 1


}

```

#### Partition

###### Idea

1. The pivot is x = A[l]
2. Move i from l + 1 to r mantaning the following invariant:
	- A[k] <= x for all l + 1 <= k <= j
	- A[k] > x for all j + 1 <= k <= i
3. In the end, move A[l] to its final position.

```

Parition(A, l, r) {

   x = A[l];
   j = l;

   for i from l + 1 to r:
	if A[i] <= x:
   		j = j + 1;
   		swap A[j] and A[i];

   swap A[l] and A[j];
   return j;

}

```

#### Randomized Quick Sort

```

Randomized_Quick_sort(A, l, r) {

	if l>= r:
		return;

	k = random number between l and r;

	swap A[l] and A[k];

	m = Partition(A, l, r)

	Randomized_Quick_sort(A, l, m - 1)
	Randomized_Quick_sort(A, m + 1, r)
	
}

```

**Running Time:**

- Avrage Running Time: O(n.log(n) )
- Worse Case Running Time: O(n^2)
