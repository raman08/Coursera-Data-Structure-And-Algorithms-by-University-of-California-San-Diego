/*
	Qick Sort:

		The algorithm is comparison based, meaning that it sorts the n given elements by comparing pairs of them.
		Its running time is also asymptotically n log(n), but not in the worst case, as was with the merge sort algorithm, for example, but on the average case.
		This is because this algorithm is randomized, so it uses random numbers to sort the given n objects.

		Phuso Code:

				A = given Array
				l, r = lower and upper bond

			Recursive Method:

				Quick_sort(A, l, r) {

					if l>= r:
						return;

					m = Partition(A, l, r)

					Quick_sort(A, l, m - 1)
					Quick_sort(A, m + 1, r)
				}

			Tail Recursion Method:

				The procedure is called tail recursion. And there is a known way to eliminate such a recursive call. Namely, instead of making this recursive call, let's just update. Well, in the second recursive call, we sort the right part of our array. I mean, the part from index n+1 to index r. Instead of making this recursive call, let's replace the with a while loop, inside this while loop we call the partition procedure as shown on the slide. Then we make a recursive call to the left part, but instead of making the recursive call for the right part, we'll just update the value of l to be equal to m+1. And then we go to the beginning of this while loop, and this essentially mimics our recursive call.


				Quick_sort(A, l, r) {

					while l < r:

						m = Partition(A, l, r)
						Quick_sort(A, l, m - 1)
						l = m + 1
				}

				Quick_sort(A, l, r) {

					while l < r:

						m = Partition(A, l, r)

						if (m - l) < (r - m):
							Quick_sort(A, l, m - 1)
							l = m + 1

						else:
							Quick_sort(A, m + 1, r)
							r = m - 1


				}



			partition :
				1. the pivot is x = A[l]
				2. move i from l + 1 to r mantaning the following invariant:
					a) A[k] <= x for all l + 1 <= k <= j
					b) A[k] > x for all j + 1 <= k <= i
				3. in the end, move A[l] to its final position.

				Phudo Code:
					Parition(A, l, r) {

						x = A[l];
						j = l;

						for i from l + 1 to r:
							if A[i] <= x:
								j = j + 1;
								swap A[j] and A[i];

						swap A[l] and A[j];
						return j;
					}


		Unbalance Partitions:

			First of all, let's consider a pathological case, when somehow, it always happens that we select the minimum value of our current subarray as our pivot element. Well in this case, well let's see what happens with our current subarray. Say of size n. And we select its minimum value as a pivot. And partition, the subarray with respect to the sum. Since this is the minimum value, it's final position is just the first position, is the resulting array, right? Which means that we partition into two parts. The first part is just empty, we have no elements smaller than our pivot. And the second part, contains n- 1 elements,
			because all the remaining elements are greater than our current element.

			Case 1:
				T(n) = n + T(n - 1)
				T(n) = n + (n - 1) + (n - 2) + .... = O(n^2)

			Case 2:
				 T(n) = n + T(n - 5) + T(4)
				 T(n) = n + (n - 5) + (n - 10) + .... = O(n^2)

			Case 3:
				T(n) = 2T(n/2) + n
				T(n) = O(n log(n))

			Case 4:
				T(n) = T(n/10)  + T(9n/10) + O(n)
				T(n) = O(n log(n))

			So running time of Algorithm of the Quick Sort is depends on how balanced our partitions. If all our politicians are balanced does that make improved that the running time is at most n log n hypothetically. At the same time if all of our partitions are unbalanced then the running time is quadratic.

			So to solve the problem we will use the following elegant solutions, so let's just select the pivot element from the current subarray randomly. To implement this solution, we do the following. Before following the partition procedure. We just select a random index between l and m, and we swap elements A[l] and this random element. Okay, then we call partition, and then we proceed in a usual way.

			Randomized_Quick_sort(A, l, r) {
				if l>= r:
					return;

				k = random number between l and r;

				swap A[l] and A[k];

				m = Partition(A, l, r)

				Quick_sort(A, l, m - 1)
				Quick_sort(A, m + 1, r)
			}

			Intro Sort:

				Run quick sort with a simple deterministic pivot selection heuristic (say, median of the first, middle, and last element)

				If the recursion depth exceeds a certain threshold c log(n) the algorithm swhich to heap sort.

				Running time is O(n log(n)) in the worse case.


		Equal Elements:

			If all the element in an array are equal then it will take O(n^2)!!!!!!!

			To handle equal elements, we replace line
				m = Partition(A, l, r)

			with line

				m1, m2 = Partition3(A, l, r)

					such that:

						1. for all l <= k <= m1 - 1, A[k] < x
						2. for all m1 <= k <= m2, A[k] = x
						3. for all m2 + 1 <= k <= r, A[k] > x

			This is called three way paritition.

			Phsudo Code:

				Quick_sort(A, l, r) {

					if l>= r:
						return;

					k = random number between l and r;
					swap A[l] and A[k];

					m1, m2 = Partition3(A, l, r)

					Quick_sort(A, l, m1 - 1)
					Quick_sort(A, m2 + 1, r)
				}


*/

void swap(int &a, int &b){

	int temp;

	temp = a;
	a = b;
	b = temp;

}



int parition(int &A, int l, int r) {

	int x = A[l];
	int j = l;

	for (int i = l + 1; i < r; ++i) {

		if (A[i] <= x) {

			j = j + 1;
			swap(A[j], A[i]);
		}
	}

	swap(A[l], A[j]);

	return j;
}



void Quick_sort(int &A, int l, int r) {
	if (l>= r)
		return;

	int m = partition(A, l, r);

	Quick_sort(A, l, m - 1);
	Quick_sort(A, m + 1, r);
}


void Tail_Recursive_Quick_sort(A, l, r) {

	while l < r:

		m = Partition(A, l, r);

		if( (m - l) < (r - m) ){

			Quick_sort(A, l, m - 1);
			l = m + 1;
		}

		else {

			Quick_sort(A, m + 1, r);
			r = m - 1;
		}

}



int random_no_generator(int min, int max) {

	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;

	do{
		x = rand();
	} while (x >= RAND_MAX - remainder);

	return min + x % n;

}

void Randomized_Quick_sort(A, l, r) {

	if (l >= r) {
		return;
	}

	k = ramdom_no_generator(l, r);

	swap(A[l], A[k]);

	m = Partition(A, l, r);

	Quick_sort(A, l, m - 1);
	Quick_sort(A, m + 1, r);
}