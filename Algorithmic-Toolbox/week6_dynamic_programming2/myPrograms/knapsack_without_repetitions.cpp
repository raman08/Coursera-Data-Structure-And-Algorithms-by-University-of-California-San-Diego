/*
	Problem Statement:

		We're given n items with weights w1, w2 and so on, wn. And its values are v1, v2 and so on, Vn. By capital W we denote the total capacity or the total weight of the knapsack. And our goal is to select the subset of items where each item can be taken any number of times such that the total weight is at most capital W while the total value is as large as possible. we are not allowed to take more than a single copy of each item.

	Phusdo Code:

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

	Rnning Time: O(nW) = O(n* 2^log(W))





*/