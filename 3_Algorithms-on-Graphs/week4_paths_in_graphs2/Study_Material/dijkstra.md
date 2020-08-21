# Dijkstra's Algorithm

- At any movement of time, if we relaxed all the edges outgoing from some set of node for which the distance are already known correctly, then the the node with the smallest dist value estimate is also a node for which we know distance correctly.

## Main ideas of the Dijkstra's Algorithm

* We mantain a set R of the vertices for which dist is already correctly ("known regions").
* The first vertex added to R is S.
* On each iteration we take a vertex outside of R with the minimal dist value, add it to r, and relax all its outgoing edges.

### Implementation

#### Dijkstra(G, s)

```

Dijkstra(G, s) {

	for all u in V:
		dist[u] = inf
		prev[u] = null

	dist[s] = 0

	h = MakeQueue(V) {dist values as keys}

	while H is not empty:

		u = ExtractMin(H) // Extract the node with min value of dist

		for all (u, v) in E:

			if dist[v] > dist[u] + w(u, v):
				dist[v] = dist[u] + w(u, v)
				prev[v] = u
				ChangePriority(H, v, dist[v])

}

```

#### Running Time

**Total Running Time:**  T(MakeQueue) + |V|.T(ExtractMin) + |E|.T(ChangePriority)

The running time will actually depend on the data structue used in implementation.

* **Array:**

	+ O(|V| + |$V^2$| + |E|) = O(|$V^2$|)

* **Binary Heap/ Priority Queue**

 	+  O(|V| + |V| . log(|V|) ) + |E| . log(|V|) ) ) = O( (|V| + |E|) (log(|V|) ))