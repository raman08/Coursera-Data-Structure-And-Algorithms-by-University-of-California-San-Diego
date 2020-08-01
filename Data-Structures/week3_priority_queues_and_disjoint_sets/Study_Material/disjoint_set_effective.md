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
