# Fastest Route

Find the fastest route from a node to other in terms of the weights/times on the edges.

- There are no negitive weights edges.

### Native Algorithm

#### Observations

- Any subpath of an optimal path is also optimal.
	* If S -> ... -> u -> t is a shortest path from S to t, then

			- d(S, t) = d(S, u) + w(u, t)

- dist[v] will be an upper bound on the actual distance (<=) on the actual distance from S to v.

- The **edge relaxtation** procedure for an edge (u, v) just check whether going from S to v through u improves the current value of the dist[v].


#### Relax((u,v) in E)

```
Relax((u, v) in E) {

	if dist[v] > dist[u] + w(u, v):
		dist[v] = dist[u] + w(u, v)
		prev[v] = v

}

```

#### Native(G, s)

```

Native(G, s) {

	for all u in V:
		dist[u] = inf
		prev[u] = NULL

	dist[s] = 0

	do:
		relax all the edges

	while:
		at least one dist changes

}

```


* After the call to a Native algorithm all the distances are set corretly.