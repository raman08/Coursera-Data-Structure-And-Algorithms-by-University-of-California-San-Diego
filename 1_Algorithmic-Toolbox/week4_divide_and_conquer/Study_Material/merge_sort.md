
###  Merge Sort

##### Idea

- Split the array into two parts
- Sort the halves recursively
- Merge the sorted half into one array


#### Implementation

- **Merge Sort**

```
merge_sort(A[]) {

   if n = 1:
   	return A;

   m = n/2;

   B = merge_sort(A[1...m])
   C = merge_sort(A[m + 1....n])

   A' = merge(B, C)

   return A';
}

```

- **Merge**

```

merge(B[p], C[q]) {

   D = Array of size p + q

   while B and C are both non-empty:
     	b = B[0]
     	c = C[0]

   	if b <= c:
   		move b from B to end of D

   	else:
   		move c from C to end of D

   move the rest if B and C to the end of D

   return D;

}

```

**Time Complaxity:** O(n log(n))
