
### Knapsack With Repetitions

#### Problem Statement:

We are given an unlimited quantity of each item.

**Input:**
We're given n items with weights w1, w2 ... wn. And its values are v1, v2 ... Vn.
W is the total weight of knapsack.

**Output:**
The maximum value of items whose weight does not exceed W. Each item can be used any number of times.


#### Solution

An optimal solution for a knapsack of total weight W we first take some smaller knapsack and an optimal solution for it and add an item i to it.

So first of all to be able to add an item i to it and get a knapsack of total weight W we need this smaller knapsack to be of total weight at most W minus w{i}, also when adding i'th item to it we increase its value by v{i}, and the final thing is we do not know which element to add exactly.

For this reason, we just go through all possible elements, n items, and select the maximal value.


#### Implementation

```

Knapscak(W) {

	value(0) = 0;

	for w from 1 to W:
		value(w) = 0

		for i from 1 to n:
			if w(i) <= w:
				val = value(w - w(i)) + v(i)
				if val > value(w):
				value(w) = val

	return value(w)

}

```

**Running Time:** O(nW)
