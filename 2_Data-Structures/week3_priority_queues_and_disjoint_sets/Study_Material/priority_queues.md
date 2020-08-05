# Priority Queue

A priority queue data structure is a generalization of the standard queue data structure.

In the priority queue data structure, there is no such thing as the beginning or the end of a queue.

## Defination (Informally)

A priority queue is a generalization of a queue where each element is assigned a priority and elements come out in order by priority.

## Defination (Formally)

Priority Queue is an abstract data type support the following main operations:

Insert(p): add a new element with priority p

ExtractMax(): extracts an element with maximun priority

#### Additional Operations

Remove(it) : removes an element pointed by iterator it

GetMax() : returns an element with maximun priority (without changing anything)

ChangePriority(it, p) : changes the priority of an element pointed bt it to p

## Implementations

1) Unsorted array/list
	
	Insert:     O(1)
	ExtractMax: O(n)

2) Sorted array/list
	
	Insert:     O(n)
	ExtractMax: O(1)


3) Binary Heap
	
	Insert:     O( log(n) )
	ExtractMax: O( log(n) )
