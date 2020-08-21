
### Fractional Knapsack

Algorithm to determine which food items and in which amounts should you take with yourself on a really long hike so that to maximize their total energy value.

So, you're planning a long hike. It will take a few days or maybe a few weeks, but you don't know exactly how long will it take. So, to be safe, you need to get enough food with you. And you have a knapsack which can fit up to 15 kilograms of food in it. And you've already bought some cheese, some ham, some nuts, and maybe some other food items. You want to fit them all in the knapsack, so as to maximize the amount of calories that you can get from them. Of course you can cut the cheese. You can cut the ham. You can select only some of the nuts. And then fit all of that into your knapsack.


**Input:**

- Weights w1, w2, ....., w(n) [Weights of food items]

- Values v1, v2, v3, ........ [Calories of each items]

- W [capicity of bag]

**Output:**  Maximun total value of fraction of item that fits the bag.


##### Solution:

Find the value pre item for each and fill the bag with product with maximun value per item first and so on....


#### Greedy Algorithm

##### Steps:

- While knapsack is not full
- Choose item i with maximum v{i} / w{i}
- If item fits into knapsack, take all of it
-  Otherwise take so much as to fill the knapsack
- Return total value and amounts taken




```

Knapsack(W, w1, v1, .... , w{n}, v{n}) {

	A = [0,0,0,.......]
	V = 0;

	repeat n times:
		if W == 0:
			return(V, A)

		select i with w(i) > 0 && max(v[i] / w[i])

    	a = min(w[i], W)

    	V = V + a * (v[i] / w[i]);

    	w[i] =w[i] - a
    	A[i] = A[i] + a
    	W = W -a;

```

**Running Time:**  O(n^2)


 - If we sorted the value by weight then we will can optamized it.....  **Running Time:**  O(n . log(n) )
