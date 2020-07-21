#include <iostream>

using namespace std;

// This struct will store all the information about the node.
// This is for singly list list.

struct Node {

	int data;
	Node* next;

};

class link_list {

	// The first node is the head and last node is the tail.
	// We can access the full linked list via the head.

	Node *head, *tail;

public:

	// The first and the last node constructor is stored as NULL as there is nothing to store.
	link_list() {
		head = NULL;
		tail = NULL;
	}


	// Return the head of the given node....
	Node* return_head() {
		return head;
	}

	/*
		############ Functions for inserting the element in the linked list ###########

	*/


	// Function to add the node at the end of the linked list
	// Time Complaxity = O(1)
	void push_first(int x) {

	Node* temp = new Node; // Creating a new node

	temp->data = x; // Adding data to the new node;

	temp->next = head; //Points the temp node to the NULL of list is empty otherwise point the temp node to the old first node.

	head = temp; // Points head to the temp;

	}



	// Function to add the node after a give position of the linked list
	// Time Complaxity = O(n)
	void push_after(int value, int position) {


		Node* temp = new Node;

		temp->data = value;
		temp->next = NULL;

		// If we want to add to the head or at index 0;
		if (position == 1) {

			temp->next = head;
			head = temp;

			return;
		}

		Node* temp_1 = head; // Creating a new node to store the position of (n-1)th node.

		// For loop to iterate to the n-2 th node;
		for (int i = 0; i < position-2; i++) {
			temp_1 = temp_1->next;
		}


		temp->next = temp_1->next; // Storing the pointer of the new node to the  next of the n-2 node;

		temp_1->next = temp; // Storing the pointer of the n-2 node to the new node.


	}




	// Function to add the node at the end of the linked list without the tail
	// Time Complaxity = O(n)
	void push_back_without_tail(int value) {

		Node* temp = new Node; // Creating a new node
		temp->data = value; // Adding the data to new node.

		temp->next = NULL;

		if (head == NULL) {

			head = temp;
			return;

		}


		Node* temp_1 = head; // Creating a temp_1 node to iterate through node.

		// iterate to the second last node
		while (temp_1->next != NULL) {
			temp_1 = temp_1->next;
		}

		temp_1->next = temp; // Pointing the temp_1 node to the last node of the linked list
	}




	// Function to add the node at the end of the linked list with the tail.
	// Time Complaxity = O(1)

	// Issue: push_with_tail not working............
	void push_back_with_tail(int value) {

		Node* temp = new Node; // Creating the new node.
		temp->data = value; // Adding the value to the data field.
		temp->next = NULL; // Pointing next to the null.

		// If it is the first node to add.
		if (head == NULL) {

			head = temp;
			tail = temp; // Pointing head and tail to the temp node.

			temp = NULL; // pointing next of the temp to the null.
		}

		else {

			tail->next = temp; // otherwise pointing next of the tail to the temp.

			tail = temp; //and tail into temp
		}

	}


	/*
		############ Functions for deleting the element in the linked list ###########

	*/


	// delete the element from the first start of the link list.
	// Time Complaxity = O(1)
	void pop_front(){

		Node* temp = head; // temp node to store head;
		head = temp->next; // pointing head to the next node (2nd node)

		delete temp; // deleting the 1st node.

	}

	// delete the node from the particular position.




	// Delete the last node from given linked list from the ....
	// Time Complaxity = O(n)
	void pop_back() {

		Node* current = head; // new node to store the last node of the linked list

		Node* previous = new Node; // new node to store the second last element of the linked list

		// iterating to the last element of the list
		while (current->next != NULL){

			previous = current; // setting the previous to the second last element

			current = current->next; // setting the current to the next element to the current;

		}

		tail = previous; // setting the tail pointer to the second last element of the linked list

		previous->next = NULL; // removing the pointer of the second last element to the last element

		delete current; // delete the last node of the linked list

	}

	// deleting a node after a particular position in linked list
	// Time Complaxity = O(n)
	void pop_after(int position) {


		Node* current = head; // node to store the position node

		Node* previous = new Node; // node to store the previous of the current node.

		// if user want to delete the first element
		if (position == 1) {

			head = current->next;

			delete current;
			return;
		}


		// for any other position
		// moving the variables to respective positions.
		for (int i = 1; i < position; i++) {

			previous = current;
			current = current->next;

		}

		previous->next = current->next; // linking the  n - 1 node to the n + 1 node

		delete current; // deleting the positioned ndoe;

	}


	/*
		############ Functions for printing the the element in the linked list ###########

	*/


	// Printing the give list.....
	void printLinkedList_iterative() {//Node* head) {

		Node* temp = head;

		while(temp != NULL){

			cout << temp->data << " ";
			temp = temp->next;

		}

	}

	void printLinkedList_recursion(Node* head) {

		if (head == NULL) // Exit condition
			return;

		cout << head->data << " "; // printing the data
		printLinkedList_recursion(head->next); // recursice call
	}



	/*
		############ Functions for reverse the element in the linked list ###########

	*/

	// Function for the reversing the linked list;
	// Time complexity: O(n)
	void reverse_iterative() {

		// Initialzing the 3 pointers variables
		Node* current = head;
		Node* previous = NULL;
		Node* next = NULL;

		// loop till end of the linkedlist is reached;
		while (current != NULL) {

			// storing the next postions
			next = current->next;
			// reversing the node pointer
			current->next = previous;

			// moving the pointers ahead
			previous = current;
			current = next;
		}

		head = previous;
	}


	// Function for the reversing the linked list;
	// Time complexity: O(n)
	void reverse_recursion(Node* p) {

		// Exit condition
		if (p->next == NULL){

			head = p;
			return;
		}

		// Recursive call to the finction
		reverse_recursion(p->next);

		// Creating node to store the next of the p.
		Node* q = p->next;

		// changing the pointer
		q->next = p;
		p->next = NULL;

	}



};


// Main Driver Program.

int main() {

	link_list list;

	cout << "Enter the number of elements:\n";

	int n;
	cin >> n;

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		int input = 0;

		cout << "\nEnter the " << i + 1 << " element: ";

		cin >> input;
		list.push_back_without_tail(input);

		// cout << endl << "The list become: ";
		// list.printLinkedList();
	}

	// list.reverse_iterative();

	list.printLinkedList_recursion(list.return_head());



	return 0;

}