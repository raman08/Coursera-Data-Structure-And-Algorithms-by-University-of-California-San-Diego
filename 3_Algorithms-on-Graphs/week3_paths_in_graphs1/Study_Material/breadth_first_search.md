# Breadth First Search

Breadth First Search in a Graph is same as in the tree.

The only point to remenber is that there can be some nodes for which graph repeats itself.

In this we :

- initizalized all the distance from a given node to infinity.
- find the starting node and find all node connected to starting postion.
- mark them as visited and do some computation simultaneously in all the found nodes.
- and go to the next layer and repeat till there is no further node left.


But the probem there is that we cann't process the found nodes simultaneously. We need to have order on those nodes.

We can achived this by putting the nodes in *queue*.

When we need to process any node we simply dequeue it, process it and add next layer into the queue and continued.

>It means that the nodes which were discovered earlier will also be processed earlier. And so, in general the order of layers won't change.

### Implenemtation

##### BFS(G, s)

> G is the graph and s os the starting node.

```

BFS(G, s) {

	for all u in V: // for all nodes
		dist[u] = inf

	dist[s] = 0 // dist to store the distance/level of the nodes

	Q = {s} // Queue contanning all the discovered node.

	while Q is not empty:

		u = dequeue(Q)

		for all (u, v) in E: // For all edges start with u
			if dist[v] = inf:
				Enqueue(Q, v)
				dist[v] = dist[u] + 1

}
```

**Running Time:** O(|E|+|V|)

>When node u is discovered (enqueued), dist[u] is assigned exactly d(S, u).