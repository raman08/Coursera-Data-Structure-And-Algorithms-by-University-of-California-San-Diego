## Robin Karp's Algorithms



For some hash function h

- If h(P) != h(S), then definately P != S

- If h(P) = h(S), call AreEqual(P, S)

Use polynomical hash family P\<p> with prime p

- If p != S, the probability

	- P[h(p) = h(S)] <= |P| / p
		for polynomial hashing.


#### RobinKarp(T, P)

```
RobinKarp(T, P) {

  p = big prime
  x = random(1, p - 1)

  result = empty list

  pHash = PolyHash(P, p, x)

  for i from 0 to |T| - |P|:

  	tHash = PolyHash(T[i .. i + |P| - 1], p, x)

  	if pHash != tHash:
  		continue

  	if AreEqual(T[i .. i + |P| - 1], p)
  		result.append(i)

  return result

}

```

#### Running Time Estimation


- Running time without AreEqual

	- h(p) is computed in O(|P|)

	- h(T[i .. i + |P| - 1]) is computed in O(|P|), |T| - |P| + 1 times

	- **Final Time:** O(|P|) + O( (|T| - |P| + 1) * |P|) = O(|T| * |P|)

- AreEqual Running time

	- AreEqual is computed in O(|P|).

	- AreEqual is called only if string are equal or there is collosion in hashing but we can reduce collision by selecting p >> |T|*|P|.

- Total Running Time:

	- If P is found q time in T then total time spend in AreEqual is O((q + ( (|T| - |P| + 1)/p )) * |P|) = O(q|P|) for p >> |T|||P

	- **Total running time:** O(|T||P|) + O(q|P|) = O(|T||P|) as q <= |T|



`Notaion: h(T[i .. i + |P| - 1]) by H[i]`

### Optimization

- H[i + 1] = sum(T[j] * x^(j - i - 1)) mod p
					for all i + 1 <= j <= i + |P|


- H[i] = sum(T[j] * x^(j - i)) mod p
		for all i <= j <= i + |P|

	= sum(T[j] * x^(j - i) + T[i] - (T[i + |P|] * x^|P|)) mod p
			for all i + 1 <= j <= i + |P|

	= x * sum(T[j] * x^(j - i - 1) + (T[i] - (T[i + |P|] * x^|P|))) mod p
			for all i + 1 <= j <= i + |P|

	= x * H[i + 1] + (T[i] - T[i + |P|] * x^|P|) mod p

#### PrecomputeHashes(T, |P|, p, x)

```
PrecomputeHashes(T, |P|, p, x) {

  H = array[|T| - |P| + 1]
  S = T[|T| - |P| .. |T| - 1]

  H[|T| - |P|] = PolyHash(S, p, x)

  y = 1

  for i from 1 to |P|:
  	y = (y * x) mod p

  for i from |T| - |P| - 1 down to 0:
  	H[i] = (x * H[i + 1] + T[i] - (y * T[i + |P|]) ) mod p

  return H

}

```

**Running time:** O(|P| + |P| + |T| - |P|)  =  O(|T| - |P|)

### Improved RabinKarp Algorithm

#### RabinKarp(T, P)

```

RobinKarp(T, P) {

  p = big prime
  x = random(1, p - 1)

  result = empty list

  pHash = PolyHash(P, p, x)

  H = PrecomputeHashes(T, |P|, p, x)

  for i from 0 to |T| - |P|:

  	if pHash != H[i]:
  		continue

  	if AreEqual(T[i .. i + |P| - 1], p)
  		result.append(i)

  return result

}

```

#### Running Time Estimation for Optimized Algorithm


- h(p) is computed in O(|P|)

- PrecomputeHashes(T, |P|, p, x) runs in O(|T| - |P|)

- AreEqual is computed in O(q*|P|) where q is the number of occurrences of P in T

- **Total Running Time:**	O(|T| + (q + 1) * |P|)