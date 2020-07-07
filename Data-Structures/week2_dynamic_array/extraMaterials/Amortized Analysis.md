#Defination

##Amotized Cost:
	Given a sequence of n operations, amortized cost is:
		( Cost(n operations)/n )

##Aggregate Method

##Banker's Method
	Charge extea for each cheap operation
	Save the extra charges as tokens in your data structure
	Use the tokens to pay expensive operations

##Physicist's Method
	define a potential function, phi which maps states of the data structure to integers:

		phi(h0) = 0
		phi(h[t]) >= 0

	amortized cost for operation t:
		c[t] + phi(h[t]) - phi(h[t - 1])

	Choose phi so that:
		if c[t] is small, the potential increses
		if c[t] is large, the potential decreses by same scale

	The cost of n operation is sum(c[i]) i=0 to n