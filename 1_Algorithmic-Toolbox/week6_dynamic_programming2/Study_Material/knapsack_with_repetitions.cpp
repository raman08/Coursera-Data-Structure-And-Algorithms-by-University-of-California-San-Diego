/*
	Problem Statement:

		we are given an unlimited quantity of each item.

		We're given n items with weights w1, w2 and so on, wn. And its values are v1, v2 and so on, Vn.
		By capital W we denote the total capacity or the total weight of the knapsack.
		Our goal is to select the subset of items where each item can be taken any number of times such that the total weight is at most capital W while the total value is as large as possible.

		An optimal solution for a knapsack of total weight w we first take some smaller knapsack and an optimal solution for it and add an item i to it. So first of all to be able to add an item i to it and get a knapsack of total weight W we need this smaller knapsack to be of total weight at most W minus wi, also when adding i'th item to it we increase its value by vi, and the final thing is we do not know which element to add exactly. For this reason, we just go through all possible elements, n items, and select the maximal value. The maximal value of the following thing: Value of W minus wi, plus vi.


	Phudo Code:

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

		Running Time : O(nW)





*/