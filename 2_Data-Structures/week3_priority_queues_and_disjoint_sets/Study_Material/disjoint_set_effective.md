# Disjoint Set

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
	
For the union operation we hang the one tree over the other tree.
To do this we just find the tree with smaller height and hand it to the other tree.

We will store height of the each subtree in an array rank[1..n]:
	rank[i] is the height of the subtree whose root is i.
	
		
		


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

#### Iterated Logarithm

log*(n) is the number of the logarithm functon needs to be applied to n before teh result is less or equal than 1



#### Find_Path_Compression(i)

	Find_Path_Compression(i) {

		if i != parent[i]:
			parent[i] = Find(parent[i])
		
		return parent[i];
	
	}
	
## Running Time
	
When used both path compression and union by the rank huristic the amortizrd running time become: O( log*(n) ) which is nearly constant for all the practicle values.
