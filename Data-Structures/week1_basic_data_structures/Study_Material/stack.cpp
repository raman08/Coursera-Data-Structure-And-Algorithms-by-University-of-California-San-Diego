#define MAX 1000


class Stack {

	int top;

public:

	int a[MAX];

	Stack() {
		top = -1;
	}

	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();

};

bool Stack::push(int x) {

	if (top >= (MAX - 1)) {
		return false;
	}

	else {
		a[++top] = x;
		return true;
	}
}

int Stack::pop() {

	if (top < 0)
		return -1;

	else {
		int x = a[top--];
		return x;
	}
}

int Stack::isEmpty() {
	return (top < 0);
}