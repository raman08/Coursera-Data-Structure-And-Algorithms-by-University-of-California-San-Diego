## Connectivity in graph

#### Defination

Two vertices v, w in a directed graph are **connected** if you can reach v from w and can reach w from v.

##### Theorm

A directed graph can be partitioned into **strongly connected components** where two vertices are connected if and only if they are in same component.

![Strongly Connected Component](images/scc_graph.png)

From each of the square we can reach any vertex which is in same square. So each of the square is a independent connected components.

##### Theorm

A directed graph can be partationed into **strongly connected components** where two vertices are connected if and only if they are in the same components.

#### Metagraph

![Metagraph](images/metagraph.png "Metagraph of the above strongly connected graph")

- The metagraph of the any graph G is a DAG.

### Strongly Connected Component

**Input :** A directed graph G.

**Output :** The strongly connected component

#### EasySCC(G)

```

EasyScc(G) {

	for each vertex v:
		run explore to determine vertices rechable from v

	for each vertex v:
		find the u rechable from v that can also reach v

	these are the SCCs

}

```

`Runtime: ` O($|V|^2$ + |V||E|)

We need faster algorithm from this one.

- The vertex with the largest postorder number is in a sourec component.

### Reverse Graph

A graph obtain by reversing all the edges in a given graph G is called **Reverse Graph** ($G^R$).

![Reversed Graph](images/reverse_graph.png "If $1^st$ graph is G then $2^nd$ grph is $G^R$")

- Both of the graph has the same strongly connected components.
- Sourece component of the $G^R$ are sink component of G.

We can find the sink components of the G by running DFS on $G^R$.