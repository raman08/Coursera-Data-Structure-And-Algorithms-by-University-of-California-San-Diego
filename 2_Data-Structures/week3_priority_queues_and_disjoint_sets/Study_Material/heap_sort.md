## Heap Sort

Sort using Priority Queue

#### Native Implimentation

```

HeapSort(A[n]) {

	create an empty priority queue

	for i from 0 to n:
		Insert(A[i])

	for i from n downto 0:
		A[i] = ExtractMax()

}

```

**Time Complexity:** O( log(n) )

###### Disadvantage

- uses extra space for storing the heap

To overcome the disadvantage we can convert heap into array.


#### BuildHeap(A[n])

```

BuildHeap(A[n]) {

  size = n

  for i from floor(n/2) down to 0:
  	ShiftDown(i)

}

```


#### In-place/Fast HeapSort(A[n])

```
HeapSort(A[n]) {

  BuildHeap(A[n])

  size = n

  repeat (n - 1) times:
  	swap A[1] and A[size]
  	size = size - 1
  	ShiftDown(1)

}

```

#### Time Complexity

| Operation       | Time             |
|---              |---               |
| BuildHeap(A[n]) | O(n)             |
| HeapSort(A[n])  | O( n . log(n) )  |