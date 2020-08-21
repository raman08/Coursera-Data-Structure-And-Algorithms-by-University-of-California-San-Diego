## Splay Tree

If there are some nodes which are search more frequently then othres. So idea here is to put those common node near the root.

#### Splay(N)

```

Splay(N) {

	Determine proper case
	Apply Zig-Zig, Zig-Zag, Zig as appropriate

	if N.Parent != null:
		Splay(N)

}

```

#### STFind(k, R)

```
STFind(k, R) {

	N = Find(k, R)
	Splay(N)

	return N

}

```

#### STInsert(k, R)

```
STInsert(k, R) {

	Insert(k, R)
	STFind(k, R)

}

```

#### STDelete(N)

```
STDelete(N) {

	Splay(Next(N))
	Splat(N)

	L = N.Left
	R = N.Right

	R.Left = L
	L.Parent = R

	Root = R

	R.Parent = null

}

```

#### STSplit(R, x)

```

STSplit(R, x) {

	N = Find(x, R)

	if N.Key > x:
		return CutLeft(R)

	else if N.Key < x:
		return CutRight(R)

	else
		return N.Left, N.Right

}

```

##### CutLeft(N)

```

CutLeft(N) {

	L = N.Left
	N.Left = null
	n.Parent = null

	return L, N

}

```

##### CutRightt(N)

```

CutLeft(N) {

	L = N.Right
	N.Left = null
	n.Parent = null

	return L, N

}

```

#### STMerge(R1, R2)

```

STMerge(R1, R2) {

	N = Find(Infinity, R1)
	SPlay(N)

	N.Right = R2
	R2.Parent = N

}

```

**Runtime:** The amortized cost of the all Splay tree operations is O( log(n) )