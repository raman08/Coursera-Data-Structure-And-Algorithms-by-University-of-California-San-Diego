# Kruskal's Algorithm

### Steps

- Start with an empty set X.
- Repeatedly add X to the next lightest edge e that doesn't produce a cycle.
- At any point of time, the set X is a forest, i.e a collection of tree.
- The next edge e connects two different trees, say T1 and T2.
- The edge e is the lightest between T1 and V - T1, hence adding e is safe.


### Implementation details

* Use disjoint set data structure.
* Initially, each vertex lies on the seprate vertex.
* Each set if the set of vertices if a connected component.
* To check weather the current edge {u, v} produce a cycle, we check weather u and v belong to the same set.

### Implementation

```

Kruskal(G) {

	for all u in V:
		MakeSet(v)

	X = empty set

	sort the edges E by weight

	for all {u, v} in E in assending weight order:
		if find(u) != find(v):
			all {u, v} to X
			Union(u, v)

	return X
}

```


#### Running Time

- Sorting edges
 	* O(|E|. ( log(|V|)) )

- Processing Edges
	* 2|E|. T(Find) + |V|. T(Union) = O( (|E|+|V|). log(|V| ) = O(|E|. log(|V|)) )

* **Total  Running Time**
 	- O(|E|. log(|V|) )