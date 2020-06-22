#Defination:

	Well we got basically a contiguous array of memory. That is one chunk of memory.
	That can either be on a stack or it can be in the heap, it doesn't really matter where it is.
	It is broken down into equal sized elements, and each of those elements are indexed by contiguous integers.
	All three of these things are important for defining an array.

###Features:

	Well, the key point about an array is we have random access.
	That is, we have constant time access to any particular element in an Array.
	Constant time access to read, constant time access to write.

###Working:

	To find the address of i^th element, you do:
		```
		array_add + elem_size * (i - first_index)
		```

###Multi-Dimensional Array:

	Row major:
			Fill all the elements of the first row, followed by all of the elements of the second row, and so on. That's called row-major ordering or row-major indexing.
			And what we do is basically, we lay out, (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6). And then right after that in memory (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6).
			So the column index is changing most rapidly as we're looking at successive elements.

	Column Major:
		Fiil all the column in order, so you'd have the first column, then the second column, and then the third column. And so that, then, the successive elements would be (1, 1), (2, 1), (3, 1), followed by (1, 2), (2, 2), (3, 2), and so on.
		So there we see that the row index is changing most rapidly, and this is called column-major ordering.

	To find address in Multi-Dimensional you do for (i, j)^th element in m * n element:
			```
			array_address + elem_size *((i -1) * n + (j - 1))
			```

##Times for Common Operations

	|	| Add | Remove |
	|:---|:---| :---|
	| Beginning | O(n) | O(n) |
	| End | O(1) | O(1)|
	|Middle| O(n) | O(n) |

##Summery

	1. an array consists of a contiguous area of memory. because if it where 	non-contiguous then we couldn't just do this simple arithmetic to get 		where we're going. We have to have equal-size elements again so our		 arithmetic works. And indexed by contiguous integers again so our 		arithmetic works.
	2. We have constant time access to any element
	3. constant time to add or remove at the end
	4.linear time to add and remove at any arbitrary location