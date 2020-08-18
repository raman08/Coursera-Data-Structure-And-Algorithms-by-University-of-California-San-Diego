# Knuth Morris Pratt Algrithm

#### Steps

- Create a new string S = P + '$' + T, where $ is the special chracter absent from both P and T.
- Compute prefix function s for string S.
- For all position i such that i > |P| and s(i) = |P|, add i - 2.|P| to the output.

##### Explation

- For all i, s(i) <= |P|, because of the '$'.
- If i > |P| and s(i) = |P|, then P = S[0...|P| - 1] = S[i - |P| + 1...i] = T[i - 2.|P|... i - |P| - 1]
- If s(i) < |P|, no full occurance of |P| ends in position i.

#### Implementations

```

FindAllOccurrences(P, T) {

	S = P + '$' + T

	s = ComputePrefixFunction(S)

	result = empty list

	for i from |P| + 1 to |S| - 1:
		if s[i] == |P|:
			result.append(i - 2.|P|)

	return result

}

```

**Running Time:** O(|P|+|T|)