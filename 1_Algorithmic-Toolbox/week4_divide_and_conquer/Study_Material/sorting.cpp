/*
	Problem Statement:

		You are given a sequence of finite elements. And your goal is to output these same elements in non-decreasing order.


	Selection Sort:

		Steps:
			1. Find the minimun element by scanning the array.
			2. Swap it with first element.
			3. Repeat with the remaining part of array...


		Phsudo Code:
			selection_sort(A){

				for i from 1 to n:
					minIndex = i

					for j from i + 1 to n:
						if A[j] < A[minIndex]:
							minIndex = j

					swap(A[i], A[minIndex])
			}

		Time Complxicity: O(n ^ 2)


	Merge Sort:

		merge_sort(A[]) {

			if n = 1:
				return A;

			m = n/2;

			B = merge_sort(A[1...m])
			C = merge_sort(A[m + 1....n])

			A' = merge(B, C)

			return A';
		}

		merge(B[p], C[q]) {

			int D[p + q]

			while B and C are both non-empty:
				b = B[0];
				c = C[0];

				if b <= c:
					move b from B to end of D

				else:
					move c from C to end of D

			move the rest if B and C to the end of D

			return D;

		}

		T(n) <= 2T(n/2) + O(n) //merge time of B and C

		Time Complxity: O(n log(n))

	Counting Sort:

		Steps:

			1. Assume that all elements of A[] are integer from 1 to M.
			2. By single scan of the array A, count the number if occurrences of each 1 <= k <= M in the array A and store it in count[k].
			3. Use this information, fill in the sorted array A'.

		Phsudo Code:

			count_sort(A[]) {

				count[1...M] = 0;

				for i from 1 to n:
					count[A[i]] += 1;

				Pos[1....M] = 0;
				Pos[1] = 1;

				for j from 2 to M:
					Pos[j] = Pos[j - 1] + count[j - 1]

				for i from 1 to n:
					A'[Pos[A[i]]] = A[i]
					Pos[A[i]] += 1;

			}

			Running time: O(n + M)

*/

void swap(int &a, int &b){

	int temp;

	temp = a;
	a = b;
	b = temp;

	return;

}

void selection_sort(int A[]) {
	for (int i = 0; i < n; ++i) {

		minIndex = i;

		for (int j = i + 1; j < n; ++j) {
			if A[j] < A[minIndex]
				minIndex = j;
		}

		swap(A[i], A[minIndex]);
	}
}