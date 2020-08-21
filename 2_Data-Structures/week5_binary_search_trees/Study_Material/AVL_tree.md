## AVL trees

AVL tree are just sort of a specific way of maintaining balace in your binary search tree.

The balace of the tree can be measured by the height of the tree.

#### AVL property

AVL trees mantain the following proberty:

	For all the nodes N,

		| N.Left.Height - N.Right.Height | <= 1.

This ensures balance of the tree.

The height must be O( log(n) )


### Implementation of the AVL tree

#### AVLInsert(k, R)

```

AVLInsert(k, R) {

	Insert(k, R)
	N = Find(k, R)
	Rebalance(N)

}

```

#### Rebalance(N)

```

Rebalance(N){

	P = N.Parent

	if N.Left.Height > N.Right.Height + 1:
		RebalabceRight(N)

	if N.Right.Height > N.Left.Height + 1:
		RebalabceRight(N)

	AdjustHeight(N)

	if P != null:
		Rebalace(P)

}

```

#### AdjustHeight(N)

```

AdjustHeight(N) {
	N.Height = 1 + max(N.Left.Height, N.Right.Height)
}

```

#### RebalabceRight(N)

```

RebalabceRight(N) {

	M = N.left

	if M.Right.Height > M.Left.Height:
		RotateLeft(M)

	RotateLeft(N)

	Adjust Height of affected nodes.

}

```



#### AVLTreeMergeWithRoot(R1, R2, T)

```

AVLTreeMergeWithRoot(R1, R2, T) {

	if |R1.Height - R2.Height| <= 1:
		MergeWithRoot(R1, R2, T)
		T.Height = max(R1.Height, R2.Height) + 1

		return T

	else if R1.Height > R2.Height:
		R' = AVLTreeMergeWithRoot(R1.Right, R2, T)
		R1.Right = R'
		R'.Parent = R1
		Rebalance(R1)

		return R'

	else if R1.Height< R2.Height:
		R' = AVLTreeMergeWithRoot(R2.Right, R1, T)
		R2.Right = R'
		R'.Parent = R2
		Rebalance(R1)

		return R'

}

```


#### AVLDelete(N)

```

AVLDelete(N) {

	Delete(N)
	M = Parent of the node replacing N
	Rebalance(M)

}

```

### Time complexity

- All of the AVL trees can be implemented all basic operations in O( log(n) ) time pre operations.

- **MergeWithRoot(R1, R2, T):** O(1)

- **AVLTreeMergeWithRoot(R1, R2, T):** O(R1.Height - R2.Height| + 1)