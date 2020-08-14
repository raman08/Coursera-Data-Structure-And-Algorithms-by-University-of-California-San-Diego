# Pattren Matching

### Brute Force Method

Given a **text** and a **pattren** start from the first letter of the text and and match it with the first method of the pattren.If they match continue and go to the next letter, and if they not try the next letter in the text.

#### Implementation

```

sub_string(text, pattren) {

	text_length = |text|
	pattren_length = |pattren|

	for i in range(| text_lenght - pattren_lenght |):

		j = 0

		while(j < pattren_length and text[i + j] == pattren[j]):
			j = j + 1

		if j = pattren_length
			return i;

	return -1;

}

```

**Running Time:**  O(|text| . |pattren|)

If there is a list of the pattrens then it will take length of the text times sum of length of all pattrens.


### Tire Matching algotithm

In this approch we create a tree of the pattrens like given in the picture below:

![Tire Construction](images/tire_construction.png)

- match the first level of the tree with text.
- If match go on to the next level.
- If they don't match match next word in the text.


#### Impementation

**TrieConstruction**

```

 TrieConstruction(Pattrens) {

 	Tire = a graph consisting of the root node

 	for each pattrn in pattrens:

 		currentNode = root

 		for i = 1 to |Pattrens|:

 			currentSymbol = i-th symbol of the pattren

 			if there is an outgoing edge from the current node with lable currentSymbol:
 				currentNode = ending of this node

 			else
 				add a new node newNode to tire
 				add a new edge from currentNode to newNode with lable currentSymbol
 				currentNode = newNode

 	return Tire

 }

```


**PrefixTireMatching**

```

PrefixTireMatching(text, tire) {

	symbol = first letter of the text
	v = root of the tire

	while True:

		if v is a leaf in tire
			return the pattren spelled by path from root to v

		else if there is edge (v, w) in tire labeled by symbol:
			symbol = next letter of the text
			v = w

		else
			output "No Match"
			return

}
```

**TireMatching**

```

TireMatching(Text, Tire) {

	while text is not empty:
		PrefixTireMatching(text, tire)
		remove first symbol from the text

}
```

**Runtime:**  O(|text|. |length of the largest pattren|)

But in this approch the memory consumption become very very large.


The no. of the egdes in tire become sum of the length of the string.
So this approch is not practicle.