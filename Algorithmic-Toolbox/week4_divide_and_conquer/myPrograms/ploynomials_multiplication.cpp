/*
	what is polynomial multiplication?

		So polynomial multiplication is basically just taking two polynomials and multiplying them together.

	Problem Statemt:
		So we're going to have two n- 1 degree polynomials. a sub n-1 is the coefficient of the x to the n-1 all the way down to a0 which is the coefficient of the x to the 0 term or the one term. And then we similarly have a b polynomial as well.

		If our incoming polynomials, are degree n- 1, then we're going to get a term of the x to the n- 1 in a, times x to the n- 1 in b, and that's going to give us an x to the 2n- 2 in the c term. So, the c sub 2n-2 term, comes about from multiplying the a sub n-1 term and the b sub n-1 term. The c sub 2n-3 term comes from the a sub n-1, b sub n-2, and a sub n-2, b sub n-1. So it's got two terms that multiply together. The c sub 2n-4 term would have three terms that multiply together. And we have more and more terms that get multiplied and summed together, and then fewer and fewer back down. So c sub 2 has three pairs which get added together, c sub 1 has two pairs and c sub 0 has one pair.

	Phsudo Code:

		Native Approch:

			MultPloy(A, B, n) {

				product <-- Array[2n -1]

				for i from 0 to 2n - 2:
					product[i] = 0

				for i from 0 to n - 1
					for j in 0 to n - 1:

						product[i + j] += A[i] * B[j];

				return product

			}

			Runtime: O(n ^ 2)

	Native Divide and Conqure ALgorithm:

		The idea is, we're going to take our long polynomial and we're going to break it in two parts. The upper half and the lower half.

		Let the two given polynomials be A and B.
		For simplicity, Let us assume that the given two polynomials are of same degree and have degree in powers of 2, i.e., n = 2 ^ i

		The polynomial 'A' can be written as A0 + A1 * x ^ n/2
		The polynomial 'B' can be written as B0 + B1 * x ^ n/2

		For example 1 + 10x + 6x^2 - 4x^3 + 5x^4 can be written as (1 + 10x) + (6 - 4x + 5x2)*x^2

		A * B  = (A0 + A1 * x^n/2) * (B0 + B1 * x^n/2) = A0 * B0 + A0 * B1 * x^n/2 + A1 * B0 * x^n/2 + A1 * B1 * x^n = A0 * B0 + (A0 * B1 + A1 * B0)x^n/2 + A1 * B1 * x^n

		This required four multliplication....



		Recurrence: T(n) = 4T(n/2) + kn

		Pseudo Code:

			// So A and B are our arrays of coefficients.
			// n is the size of the problem.
			// a1 is the first coefficient that we're interested in.
			// b1 is the coefficient in B, that we're interested in.

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

		Time Complxicity theta(n^2)

	Fast Divide and Conqure ALgorithm (Karatsuba Approch):

		But in this approch we required three multliplcation........

		A(x) = A1x + A0
		B(x) = B1x + B0

		C(x) = A(x) * B(x) = A1B1 * x^2 + (A1B0 + A0B1)x + A0B0

		C = A * B can be written as:
			A1B1 * x^2 + ((A1 + A0)(B1 + B0) - A1B1 - A0B0)x + A0B0

		X = (A0 + A1) * (B0 + B1) // First Multiplication
		Y = A0B0  // Second
		Z = A1B1  // Third

		The missing middle term in above multiplication equation A0 * B0 + (A0 * B1 + A1 * B0)x^n/2 + A1 * B1 * x^n can obtained using below.
		A0B1 + A1B0 = X - Y - Z

		Time complxicity: theta(n ^ log(3) [base 2]) = theta(n ^ 1.58)

*/




int * MultPloy(A, B, n) {

	static int product[2n -1];

	for (int i = 0; i < 2n -2; ++i){
		product[i] = 0;
	}


	for (int i = 0; i < n - 1; ++i){
		for (int i = 0; i < n - 1; ++i) {
			product[i + j] += A[i] * B[j];
		}
	}

	return product;
	// Function return the pointer address of the array product.
	// To acess the element of the array use *(p + i) where p is the variable for calling function.

}