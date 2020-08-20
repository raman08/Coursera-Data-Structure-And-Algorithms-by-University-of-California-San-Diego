## Local Search

#### Defination

A Local Structure Data Struture stores a number of elements each with a key comming from ordered set.

It support following operations :

1. **Insert(x):** Adds a element with key x.

2. **Delete(x):** Removes the element with key x.

3. **RangeSearch(x, y):** Returns all elements with keys b/w x and y.

4. **NearestNeighbour(z):** Returns the element with keys on either side of z.

This problem is solved by using **binary search tree.**

**Property:** This tree has a special property of that node to left of tree will be smaller then the root and mode to the right is bigger then its root.

### Basic Operation in binary search tree

#### Find(k, R)

- k = key to search
- R = root of tree

```
Find(k, R) {

  if R.key = k:
  	return R

  else if R.key > k:
  	return Find(k, R.Left)

  else if R.key < k:
  	return Find(k, R.Left)

}

```

If the elemnt we are looking is not in the tree we can return the null pointer.
OR we can return the postion where it should be Inserted.

##### Find (modified)

```
else if R.key > k:
if R.Left != null:
	return Find(k, R.Left)

return R

```

#### Next(N)

- N = node of the tree

- **Output:** The node with next largest element

```

Next(N) {

  if N.Right != null:
  	return LeftDescendant(N.right)

  else:
  	return RightAncestor(N)

}

```

##### LeftDescendant(N)

```

LeftDescendant(N) {

  if N.Left = null:
  	return N

  else:
  	return LeftDescendant(N.Left)

}

```

##### RightDescendant(N)

```

RightDescendant(N) {

  if N.Key < N.Parent.Key:
  	return N.Parent

  else:
  	return RightDescendant(N.Parent)

}

```

#### RangeSearch(x, y, R)

- x-y : Range of number to search
- R : Root

- **Output:** A list of node with key between x and y.

```

RangeSearch(x, y, R) {

  L = an empyt list of result

  N = Find(x, R)

  while N.key <= y;
  	if N.key >= x:
  		L.append(N)

  	N = Next(N)

  return L

}

```


### Insert(k, R)

```

Insert(k, R) {

  P = Find(k, R)

  Add new node with key k as a child of P

}

```

### Delete(N)

```

Delete(N) {

  if N.Right = null:
  	Remove N, promote N.Left

  else:
  	X = Next(N)

  	Replace N by x, promote X.Right

}

```

### MergeWithRoot(R1, R2, T)

- R1 and R2 are the roots of the two trees.
- All keys in R1 is smaller then the keys of R2.
- T is the root of new tree

**Output:** The root of a new tree with all the element of the both trees.

```

Merge(R1, R2) {

  T.Left = R1
  T.Right = R2
  R1.Parent = T
  R2.Parent = T

  return T

}

```

#### Merge(R1, R2)

```

Merge(R1, R2) {

  T = Find(Infinity, R1)
  Delete(T)
  MergeWithRoot(R1, R2, T)

  return T

}

```

`Note:`The merge function dosen't return balanced tree.

To solve this problem we will find the apporiate node with the sufficient height and merge tree with that node.

#### Split(R, x)

- R : Root of the tree
- x: key

**Output:** Two tree; one with elements < x. other with elements > x.

```

Split(R, x) {

  if R = null:
  	return (null, null)

  if x < R.key:
  	(R1, R2) = Split(R.Right, x)
  	R3 = MergeWithRoot(R2, R.Right, R)
  	return (R1, R3)

  if x > R.key:
  	(R1, R2) = Split(R.Left, x)
  	R3 = MergeWithRoot(R2, R.Left, R)
  	return (R1, R3)

}

```

Using AVLMergeWithRoot mantains the balance


## Runtime

- **Find(k, R):** O(depth) //O( log(n) ) for balanced tree and O(n) for unbalanced tree

- **Merge(R1, R2):** O(height)

- **Split(R, x):** O( log(n) )

### Balance tree

A tree with  left and right subtree to have approximately the same size is called **balance tree**.

Insertion and deletion can unbalanced tree.
The rotation will help in balanced the tree.

THIS CAN BE IMPLEMENTED BY AVL TREES
