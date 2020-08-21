## Suffix Array

**Input:** String S

**Output:** All suffixes of S in lexographic order

</br>
</br>

#### Lexographically Order

String S is lexographically smaller then string T if S != T and there exist such i that:

- 0<= i<= |S|
- S[0..i - 1] = T[0..i - 1]
- Either i = |S or S[i] < T[i]

</br>

If S is a prefix of T then S < T is a incovenient rule.
To solve this problem we add a special chracter '$' at end of the S.


###### Example

- 'ab' < 'bc'
- 'abc' < 'abd'
- 'abc' < 'abcd'

##### Example of the suffix array

**S = ababaa** => **S' = ababba$**

- *Suffixes  of S in lexicographical order:*
	- a
	- aa
	- abaa
	- ababba
	- baa
	- babaa

- *Suffixes of S' in lexicographical order:*
	- $
	- a$
	- aa$
	- abaa$
	- ababba$
	- baa$
	- babaa$

#### Storing Suffix Array

- Total length of the all suffixes is 1 + 2 + 3 + ... + |S| = O(|S|^2)
- Storing all of them will cost too much of the memory.
- Alternatively, we can store the order of all suffixes in O(|S|) memory.
- **Suffix array** is the order of such suffixes.

###### Example

For S = ababaa$

Suffix Array: [6, 4, 4, 2, 0, 3, 1]