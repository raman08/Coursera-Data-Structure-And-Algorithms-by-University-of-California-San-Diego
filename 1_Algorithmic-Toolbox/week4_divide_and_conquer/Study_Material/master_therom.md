## What is Master Theorm?

The Master Theorem says if you have a recurrence relation

**T(n)** = a * T(floor(n / b) + O(n^d)

where:

- a is a constant greater than 0,
- b is greater than 1 because we want to actually make sure the problem size gets smaller
- d is greater than equal to 0.

then we have a **solution for T(n).**

***There are three sub cases.***

1. if d > log(a) [base b],
			   **T(n)** = O(n ^ d)

2. if d = log(a) [base b],
			   **T(n)** = O((n ^ d) * log(n))

3. if d < log(a) [base b],
			   **T(n)** = O(n ^ (log(a) [base b]))