/*
	Problem Statement:

		The Alignment Game:

			So we define the alignment score as number of matches minus mu number of mismatches and minus sigma number of indels. And the optimal alignment problem is given two strings mismatch penalty mu, and indel penalty sigma find an alignment of two strings maximizing the score.

				Input:
					Two strings, mismatched palenty u and indel penalty o.

				Output:
					An alignment of strings maximizing the score.

		Longest common subsequence problems:

			We will define common subsequence as simply matches in an alignment of two strands. In this case, common subsequence is represented by ATGT, and the longest common subsequence problems that we will be interested in is the following. Given two strings we want to find the longest common subsequence of these strings.

				Input:
					Two strings

				Output:
					Find the longest common subsequence of these strings

		Edit Distane Problem:

			Another classical problem in computer science is the edit distance problem. Given two strings, find the minimum number of elementary operations, insertions, deletions, or substitutions of symbols. That transform one string into another. And of course the minimum number of insertions, deletions, and mismatches in an alignment of two strings, represents the edit distance.

				Input:
					Two strings

				Output:
					Find the minimum number of elementary operations, insertions, deletions, or substitutions of symbols that transform one string into another.



			Phuso Code:
				EditDistance(A, B){
					D(i, 0) = i and D(j, 0) = j for all i, j;

					for j from 1 to m:
						for i from 1 to n:
							insertion = D(i, j - 1) + 1
							deletion = D(i -1, j) + 1
							match = D(i - 1, j - 1)
							mismatch = D(i- 1, j - 1) + 1

							if A[i] == B[j]:
								D(i, j) = min(insertion, deletion, match)
							else:
								D(i, j) = min(insertion, deletion, mismatch)

					return D(n, m)
				}

		Minimizing edit distane = maximizing alignment score.

*/