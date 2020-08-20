## Patterns Search

### Problem

Given a text T (book, website, facebook profile) and a pattern P (word, phrase, sentence), fing all occurrences of P in T.

**Input:** String T and P

**Output:** All such postion i in T, 0 <= i <= |T| - |P| that T[i..i + |P| - 1] = P


### Substring Notation

Denote by S[i..j] the substring of string S starting in positon i and end at position j including i and j.

### Native Algorithm

##### AreEqual(S1, S2)

```

AreEqual(S1, S2) {

	if |S1| != |S2|:
		return False

	for i from 0 to |S1| - 1:
		if S1[i] != S2[i]:
			return False

	return True

}

```

##### FindPatternNative(T, P)

```

FindPatternNative(T, P) {

	result = empty list

	for i from 0 to |T| - |P|:
		if AreEqual(T[i .. i + |P| - 1], P):
			result.append(i)

	return result

}

```

**Running Time:**  O(|T| * |P|)

