# Prim's Algorithm

### Idea

* Start with an empty data structure  X. {Priority Queue is recomended}
* x is always a subtree, grows one by one at each itreration.
* We add a lightest edge between a vertex of the tree and a vertex not in the tree.
* This is very similar to the Dihkstra's Algorithm.

### Implementation

```

Prim(G) {

	for all u in V:
		cost[u] = inf
		parent[u] = nil // MST

	pick any initial vertex u

	cost[u] = 0

	prioQ = MakeQueue(V) {priority is cost}

	while prioQ is not empty:
		v= extractMin(prioQ)

		for all {v, z} in E:
			if z in prioQ and cost[z] > w(v, z): // w is the weight of the edge
				cost[z] = w(v, z)
				parent[z] = v
				ChangePriority(PrioQ, z, cost[z])

}

```

#### Running Time

* **Running Time:** |V|. T(ExtractMin) + |E|. T(ChangePriority)

* For **array based implementation**, running time is : |V|. O(|V|) + |E|. O(1) = O($|V|^2$)

* for **binary heap-based implementation**, the running time is: O( (|V| + |E|). log(|V|) ) = O( |E|. log(|V|) )