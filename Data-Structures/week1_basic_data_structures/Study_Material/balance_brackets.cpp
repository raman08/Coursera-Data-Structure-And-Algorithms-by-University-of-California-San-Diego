/*
	Problem Statement:

		we have a string. And it has left parens, right parens, left square brackets, and right square brackets. And we want to determine whether or not that string of parentheses and square brackets, whether they're balanced.

		Input:
			A string ste consisting of '(', ')',  '{', '}', '[', ']' chracters.

		Output:
			return whether or not string's parentheses and square brackets are balanced.


		Examples:

			blance:

				"([])[]()"
				"((([([])])) ())"

			Unbalanced:

				"([]]()"
				"]["

	Phudo Code:

		IsBalanced(str) {

			Stack stack;

			for char in str:

				if char in ['(', '[', '{']:
					stack.Push(char)

				else:

					if stack.Empty():
						return False;

					top = stack.pop()

					if (top == "[" and char != ']') or (top == "(" and char != ')') or (top == "{" and char != '}'):
						return False;


			return stack.Empty();

		}

*/