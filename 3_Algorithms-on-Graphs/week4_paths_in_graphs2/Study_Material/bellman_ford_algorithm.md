# Bellman-Ford Algorithms

This algorithm is useful when there is negitive weights in the graph.

**Note:**  
- The Dijkstra Algoritm will not work on the graphs with negative weights.
- This algorithm will not give correct answer for the graph with negitive weights algorithm.

### Implementation

#### BellmanFord(G, s)

```

BellmanFord(G, s) {

	for all u in V:
		dist[u] = inf
		prev[u] = nil

	dist[s] = 0

	repeat |V| - 1 times: // Repeat untill there will no change in dist.
		for all (u, v) in E:
			Relax(u, v)

}

```

**Running Time:** O(|E|*|V|)

## Detecting Negative Cycles

- A graph G contains a **negative cycle** if and only if |V|-th iteration if BellmanFord(G, s) updates some dist-values.


#### Algorithm

- Run |V| iteraton of Bellman-Ford algorithm, save node v relaxed on the last iteration
- v is rechable from a negative cycle.
- Start from x <-- v, follow the link x <-- prev[x] for |V| times - will be definitely on the cycle.
- Save y <-- x and go x <-- prev[v] untill x = y again.

## Detecting Infinite Arbitrage

- Do |V| iterations of Bellman-Ford, save all nodes relaxed on V-th iteration -- set A.
- Put all the nodes from A in queue Q.
- Do breadth-first search with queue Q and find all node rechable from A.
- ALl those node and only those nodes can have infinite arbitrage.

### Reconstruct Infinite Arbitrage

- During Breadth-First Search, remember the parent of each visited node.
- Reconstruct the path to u from some node w relaxed on iteration V.
- Go back from w to find negative cycle from which w is rechable.
- Use this negative cycle to achive infinite arbitrage from S to u.
