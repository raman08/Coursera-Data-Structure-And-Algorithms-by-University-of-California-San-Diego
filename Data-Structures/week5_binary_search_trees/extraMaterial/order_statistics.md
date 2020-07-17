# Order Statistics

Input : The root of the tree T and a number k
Output : The k<th> smallest element

To solve this problem ass a new field N.size which should returns number of the elements in the subtree N.

### RecompueSize(N)

	RecompueSize(N) {
		N.size = N.Left.Size + N.Right.Size + 1
	}


### OrderStatistic(R, k)

	OrderStatistic(R, k) {

		s = R.Left.Size

		if k = s + 1
			return R

		else if k < s + 1:
			return OrderStatistic(R.Left, k)

		else if k > s + 1:
			return OrderStatistic(R.Right, k -s - 1)

	}

#### Runtime

	OrderStatistic(R, k) : O(height)

# Color Flips

There is a array of square and each square is a color black or white. We want to able to flip colors of all the square after index x.

~`To create the 2 tree with opposite colore`

### NewArray(n)

	NewArray(n) {

		Create two trees T1, T2 with keys 1 to n.
		Give node extra color field.
		All T1 have color White.
		All T2 have color Black.

	}

`To find the color of the m<th> node`

### Color(m)

	Color(m) {
		N = Find(m, T1)
		return N.color
	}

`To flip the colors`

### Flip(x)

	Flip(x) {

		(L1, R1) = Split(T1, x)
		(L2, R2) = Split(T2, x)
		Merge(L1, R2) = T1
		Merge(L2, R1) = T2

	}