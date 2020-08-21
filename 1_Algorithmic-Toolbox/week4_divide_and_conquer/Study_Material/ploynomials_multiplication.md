## Polynomial Multiplication

### What is polynomial multiplication?

**Polynomial Multiplication** is basically just taking two polynomials and multiplying them together.

**Input:** Two n−1 degree polynomials.

**Output:** The product polynomial.


#### Native Approch

```

MultPloy(A, B, n) {

	product = Array[2n -1]

	for i from 0 to 2n - 2:
		product[i] = 0

	for i from 0 to n - 1
		for j in 0 to n - 1:

			product[i + j] += A[i] * B[j];

	return product

}

```

**Runtime:** O(n ^ 2)

#### Native Divide and Conqure Algorithm

The idea is to take our long polynomial and we're going to break it in two parts.

- The upper half and the lower half.

Let the two given polynomials be A and B.
For simplicity, Let us assume that the given two polynomials are of same degree and have degree in powers of 2, i.e., n = 2 ^ i

- The polynomial 'A' can be written as A0 + A1 * x ^ n/2
- The polynomial 'B' can be written as B0 + B1 * x ^ n/2

For example 1 + 10x + 6x^2 - 4x^3 + 5x^4 can be written as (1 + 10x) + (6 - 4x + 5x2) * x^2

**A * B**  = (A0 + A1 * x^n/2) * (B0 + B1 * x^n/2)

= A0 * B0 + A0 * B1 * x^n/2 + A1 * B0 * x^n/2 + A1 * B1 * x^n

= A0 * B0 + (A0 * B1 + A1 * B0)x^n/2 + A1 * B1 * x^n

=> We required four multliplcation.

###### Parameters

- A and B are our arrays of coefficients.
- n is the size of the problem.
- a1 is the first coefficient that we're interested in.
- b1 is the coefficient in B, that we're interested in.


```

Mult2(A, B, n, a1, a2) {

  R = Array[2n - 1]

  if n == 1:
  	R[0] = A[a1] * B[b1];
  	return R;

  R[0..n-2] = Mult2(A, B, n/2, a1, b1);

  R[n..2n-2] = Mult2(A, B, n/2, a1 + n/2, b1 + n/2);

  D0E1 = Mult2(A, B, n/2, a1, b1 + n/2)

  D1E0 = Mult2(A, B, n/2, a1 + n/2, b1)

  R[n/2...n + n/2 - 2] += D1E0 + D0E1;

}

```

**Time Complxicity:**  O(n^2)


#### Fast Divide and Conqure ALgorithm (Karatsuba Approch):

=> in this approch we required three multliplcation

A(x) = A1x + A0

B(x) = B1x + B0

C(x) = A(x) * B(x) = A1B1 * x^2 + (A1.B0 + A0.B1)x + A0.B0

C = A * B can be written as:

A1B1 * x^2 + ( (A1 + A0)(B1 + B0) - A1.B1 - A0.B0)x + A0.B0

- X = (A0 + A1) * (B0 + B1) // First Multiplication
- Y = A0B0  // Second Multiplication
- Z = A1B1  // Third Multiplication

The missing middle term in above multiplication equation A0 * B0 + (A0 * B1 + A1 * B0) x^n/2 + A1 * B1 * x^n can obtained using below.

A0B1 + A1B0 = X - Y - Z

**Time complxicity:** O(n ^ log(3) ) = O(n ^ 1.58)
