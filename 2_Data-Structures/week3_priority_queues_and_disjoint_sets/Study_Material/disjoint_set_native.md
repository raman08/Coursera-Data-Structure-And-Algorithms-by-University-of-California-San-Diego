# Disjoint-Set data Structure

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
	
2) Use smallest element of the set used as ID

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

We use the tail of the two link list as ID of two set.
	
Then in union we can point the tail of the 1st set to the head of the other set and in this way the ID of two link list is automatically updated for all of the element.




#### Pros of using link-list

	1) Running time of Union is O(1)
	
	2) Well define ID



#### Corns of using link-list

	1) Running time of Find become O(n)
	
	2) Union(x, y) works in time O(1) only if we can get the tail of x and the head of y in constant time!!

