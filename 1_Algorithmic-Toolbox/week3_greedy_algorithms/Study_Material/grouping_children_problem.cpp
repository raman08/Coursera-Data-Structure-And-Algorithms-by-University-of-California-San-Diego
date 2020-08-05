
/*
     Let's consider the following situation. You've invited a lot of children to a celebration party, and you want to entertain them and also teach them something in the process. You are going to hire a few teachers and divide the children into groups and assign a teacher to each of the groups this teacher will work with this group through the whole party.

     But you know that for a teacher to work with a group of children efficiently children of that group should be of relatively the same age. More specifically age of any two children in the same group should differ by at most one year.

     Also, you want to minimize the number of groups. Because you want to hire fewer teachers, and spend the money on presents and other kinds of entertainment for the children. So, you need to divide children into the minimum possible number of groups. Such that the age of any two children in any group differs by at most one year.
*/


/*

	long long min_groups_native() {
		m = len(C[]) // m = no. of groups.
					 // C = array contaning age of students

		for each partition into groups{
			C = G1 + G2 + ....+ G(k)
				// make different groups.

			good = true;

			for (int i = 0; i < k; ++i)
			{
				if (max(G[i]) - min(G[i]) > 1)
					good = false;
			}

			if (good)
				m = min(m, k);
					// Optamising no of groups.
		}

		return m;
	}
		// Time complaxity = sigma(2^n)

*/




/*

	long long min_groups_fast(C[n]) {


			//Consider age of student as points in line. Condider the line segment of length 1 and keep courser at left most point.



		R = set([]);
		i = 1;

		while(i<=n) {

		    l = C[i];
		    r = c[i] + 1; // r -l = 1

		    // [l, r] = [C[i], C[i] + 1]

		    R += l, r;
		    i += 1;

		    while(i<=n && C[i]<=r) {
		        i+=1;
		        // While i is less then n we didn't cover all points and we need to make sure that points doesn't goes beyond r.

		    }



		}


		return R;

		//  If C[] is sorted.... Time complexity = O(n)
		//  If C[] is not sorted.... Time complexity = O(nlog(n))
	}

*/