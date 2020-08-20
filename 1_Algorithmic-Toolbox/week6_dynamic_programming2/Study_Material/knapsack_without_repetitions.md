### Knapsack Without Repetitions

#### Problem Statement:

We are given an unlimited quantity of each item.

**Input:**
We're given n items with weights w1, w2 ... wn. And its values are v1, v2 ... Vn.
W is the total weight of knapsack.

**Output:**
The maximum value of items whose weight does not exceed W. Each item can be used at most once.



#### Implementation

```
Knapsack(W) {

	initialized all value(0, j) = 0
	initialized all value(w, 0) = 0

	for i from 1 to n:
		for w from 1 to W:
			value(w, i) = value(w, i -1)

			if w(i) <= w:
				val = value(w - w(i), i - 1) + v(i)

				if value(w, i) < val
					value(w, i) = val

	return value(W, n)

}

```

**Running Time:** O(nW) = O(n* 2^log(W))
