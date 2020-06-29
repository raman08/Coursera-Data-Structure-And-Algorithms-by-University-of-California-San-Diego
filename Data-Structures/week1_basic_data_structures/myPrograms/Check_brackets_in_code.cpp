#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct stack_Item
{
	char Bracket_Type;
	int str_idx;
};

string Is_Balanced(string str) {

	stack<stack_Item> checking_stack;

	for (int i = 0; i < str.length(); i++)
	{

		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {

			stack_Item item;
			item.Bracket_Type = str[i];
			item.str_idx = i;
			checking_stack.push(item);

		}

		else if (str[i] == ']' || str[i] == '}' || str[i] == ')') {

				if (checking_stack.empty()) return  std::to_string(i + 1);

				stack_Item top = checking_stack.top();

				checking_stack.pop();

				if ((top.Bracket_Type == '[' && str[i] != ']') || (top.Bracket_Type == '{' && str[i] != '}') || (top.Bracket_Type == '(' && str[i] != ')'))
					return  std::to_string(i +1);

		}
	}

	return (checking_stack.empty() ? "Success" : std::to_string(checking_stack.top().str_idx + 1));
}


int main() {

	std::string input;
	getline(cin, input);


	cout << Is_Balanced(input);


	return 0;
}