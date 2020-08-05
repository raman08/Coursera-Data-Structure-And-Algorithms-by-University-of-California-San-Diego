# Hash Functions

#### Defination
	For any set of object S and any integer m > 0, a function h : S --> {0, 1, 1,3, ... , m - 1} is called hash function.

	m is called the cardinality of hash function h.

	When h(x) = h(y) and x != y, this is called collision.

#### Properties

	1) Hash Functon must be deterministic.
	2) Fast to compute
	3) Distribute keys well into different cells
	4) Few collisions

There is no universal hash functions

`Load factor = n/m`

### Universal Family

#### Defination

	Let U be the universe - the set of all possible keys.
	A set of hash functions

			H = {h : U --> {0, 1, 2, ...., m- 1}}

	is called a universal family if for any two keys x, y belong to U, x!=y the probability of collision

			P[h(x) = h(y)] <= (1/m)

### Hashing Integers

	H<p> = {h<p>(x) = ((ax + b) mod p) mod m}
			for all a, b : 1 <= a <= p-1
				       0 <= b <= p-1
				       p is a prime > 10^len(data)

	is a universal family.

	Size of H = p(p -1)

### Hashing String

	|S| represent length of the string S.

	We should use all the chracters in the string.

	Prepration:

		Convert each chracter S[i] to integer code (ASCII code, Unicode etc.)

		Choose big prime number p.

#### Polynomial Hashing

	Family of hash functions:

		P<p> = {h<p>(S) = sum(S[i]x^i mod p)}
				for all 1<= x <= p-1

		There are p - 1 different hash functions.

##### PolyHash(S, p, x)

	PolyHash(S, p, x) {

		hash = 0

		for i from |S| - 1 down to 0:
			hash += (hash * x + S[i]) mod p;

		return hash
	}

~~~

For any two different string s1 and s2 of length at most L + 1, if you choose j from P<p> at random, the probability of collision

		P[h(s1) = h(s2)] <= L/p

~~~

##### Cardinality Fix

	For using in a hash table of size m, we need a hash function of size m.
	But if we use PolyHash function then the cardinality become p, the big prime number. This will increse the memory consumption.

	To fix this we first apply random h from P<p> and then hash the resulting hash against using the integer hashing. 
	Denote the resulting function by h<m>.

~~~

For any two different string s1 and s2 of length at most L + 1 and cardinality m, the probability of collision

		P[h(s1) = h(s2)] <= 1/m + L/p

~~~

~~~

If p > mL, for any two different strings s1 and s2 of the length at most L + 1, the probability of collision

		P[h(s1) = h(s2)] = O(1/m)

~~~

### Running Time to build a hash table using new family of hash functions

	For big enough p again we have c = O(1 + n/m)

	Computing PolyHash(S) runs in time O(|S|)
