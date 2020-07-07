# Disjoint-Set data Structue

## Defination

	A disjoint-set data structure supports the following operations:

		MakeSet(x) : creates a singleton set {x}

		Find(x) : return ID of the set containing x:

						if x and y lie in same set then
							Find(x) = Find(y)
						otherwise, Find(x) != Find(y)

		Union(x, y) : Merge two set contaning x and y

## Native Implementations

Assumptions:
	1) The elements of the disjoint-set is integer from 1 to n
	2) Use smallest element of the set as ID
		Use array smallest[1..n]: smallest[i] stores smallest element in the set i belongs to

### MakeSet(i)

	MakeSet(i) {
		smallest[i] = i
	}

### Find(i)

	Find(i) {
		return smallest[i]
	}

### Union(i, j)

	Union(i, j) {
		i_id = Find(i)
		j_id = Find(j)

		if i_id = j_id:
			return

		m = min(i_id, j_id)

		for k from 1 to n:
			if smallest[k] in {i_id, j_id}:
				smallest[k] = m
	}

#### Running Time

	MakeSet(i)  : O(1)
	Find(i)     : O(1)
	Union(i, j) : O(n)

To improve the running time of the Union we can use link list.
~~~
We use the tail of the two link list as ID of two set
Then in union we can point the tail of the 1st set to the head of the other set and in this way the ID of two link list is automatically updated for all of the element.
~~~

#### Pros of using linklist

	1) Running time of Union is O(1)
	2) Well define ID

#### Pros of using linklist

	1) Running time of Find become O(n)
	2) Union(x, y) works in time O(1) only if we can get the tail of x and the head of y in constant time!!

## Effective Implementation

Assumptions:
	1) Represent each set as a rooted tree
	2) ID of a set is the root of the tree
	3) Use array parent[1..n]:
		parent[i] is the parent of i, or i if it is root

### MakeSet(i)

	MakeSet(i) {
		parent[i] = i
		rank[i] = 0
	}

### Find(i)

	Find(i) {

		while i != parent[i]:
			i = parent[i]

		return i
	}

### Union(i, j)
	We will store height of the each subtree in an array rank[1..n]:
		rank[i] is the height if the subtree whose height is i.


	Union(i, j) {
		i_id = Find(i)
		j_id = Find(j)

		if rank[i_id] > rank[j_id]:
			parent[j_id] = i_id

		else:
			parent[i_id] = j_id

			if rank[i_id] = rank[j_id]:
				rank[i_id] = rank[i_id + 1]
	}

The height of any tree in the forest ia at most log(n) [base 2]

#### Running Time

	MakeSet(i)  : O(1)
	Find(i)     : O( log(n) )
	Union(i, j) : O( log(n) )

### Path Compression

If we use find operation on any node we find the root of many other nodes.
Now if we attached all those nodes directly to the root of tree it will save us time for future operations.

This method is called path compression

The amortized running time of find in this case become log*(n).

Note: The maximun value of the log*(n) for all practicle value of n is <= 5.


#### Find(i)

	Find(i) {

		if i != parent[i]:
			parent[i] = Find(parent[i])
	}