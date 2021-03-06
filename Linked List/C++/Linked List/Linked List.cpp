// Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node {
	int age;
	 Node *next;
};

void push(Node **head_ref, int new_age) {
	
	/* 1. Create new node */
	Node *new_node = new Node;

	/* 2. Insert data */
	new_node->age = new_age;

	/* 3. point to second link head_ref */
	new_node->next = *head_ref;

	/* 4. Move the head to point to the new node */
	*head_ref = new_node;
}
void insertAfter(Node *prev_node, int new_age) {
	/* 1. Check if prev_node is NULL */
	if (prev_node == NULL)
	{
		cout << "Prev_node is NULL\n";
		return;
	}

	/* 1. Create new node */
	Node *new_node = new Node;

	/* 2. Insert data */
	new_node->age = new_age;

	/* 3. Point new_node to the next of prev_node */
	new_node->next = prev_node->next;

	/* 4. Make prev_node point to new_node */
	prev_node->next = new_node;
}
void append(Node **head_ref, int new_age) {
	/* 1. Create new node */
	Node *new_node = new Node;

	Node *last = *head_ref; // Used in step 5.

	/* 2. Give new age to new node */
	new_node->age = new_age;

	/* 3. Make next of new node be NULL */
	new_node->next = NULL;

	/* 4. If the linked list is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else travers through list and find the last node */
	while (last->next != NULL)
		last = last->next;
	
	/* 6. Change next of last point to new node */
	last->next = new_node;
	return;
}
void printList(Node *head_ref) {
	int linkNum = 1;
	while (head_ref != NULL)
	{
		cout << "Link " << linkNum << "'s age: " << head_ref->age << endl;
		head_ref = head_ref->next;
		linkNum++;
	}
}

int main()
{
	char response;
	int optionChoice;
	Node *head = new Node;
	Node *second = new Node;
	Node *third = new Node;

	/* Keep track of head, head_ref is a pointer to head */
	Node **head_ref = &head;

	/* Create three links in the chain with some data */
	head->age = 26;
	head->next = second;

	second->age = 29;
	second->next = third;

	third->age = 55;
	third->next = NULL;

	/* Prompt */
	do {
		cout << "Would you like to create a new entry? (y/n): ";
		cin >> response;
		if (response != 'y' && response != 'Y' && response != 'n' && response != 'N')
			cout << "\nSorry, " << response << " is not a valid entry. Try again.\n";
	} while (response != 'y' && response != 'Y' && response != 'n' && response != 'N');

	/* Bring up user promt */
	do {
		
		if (response == 'y' || response == 'Y')
		{
			do {


				cout << "\nOkay, would you like to instert your entry at the beggining, after a spcific entry or at the end of the list?";
				cout << "\n1. At the front of the list";
				cout << "\n2. After a specific entry";
				cout << "\n3. At the end of the list:";
				cout << "\n4. Print the list";
				cout << "\n5. Cancel";
				cout << "\n6. Quit application";
				cout << "\n\nEnter number as response.\n(eg. 1, 2, 3, 4)\nWhat would you like to to: ";
				cin >> optionChoice;
			} while (optionChoice != 1 && optionChoice != 2 && optionChoice != 3 && optionChoice != 4 && optionChoice != 5 && optionChoice != 6);

			/* Check for case, perform function */
			switch (optionChoice){
			case 1:
				push(head_ref, optionChoice);
				break;
			case 2:
				insertAfter(second, optionChoice);
				break;
			case 3:
				append(head_ref, optionChoice);
				break;
			case 4:
				printList(head);
				break;
			case 5:
				break;
			case 6:
				cout << endl << endl;
				system("pause");
				return 0;
			}
		}
		if (response == 'n' || response == 'N')
			break;

		/* Prompt*/
		do {
			cout << "Would you like to create another? (y/n): ";
			cin >> response;
			if (response != 'y' && response != 'Y' && response != 'n' && response != 'N')
				cout << "\nSorry, " << response << " is not a valid entry. Try again.\n";
		} while (response != 'y' && response != 'Y' && response != 'n' && response != 'N');

	} while (response == 'y' || response == 'Y');

	do {
		cout << "\nWould you like to see the current entries? (y/n): ";
		cin >> response;
		if (response != 'y' && response != 'Y' && response != 'n' && response != 'N')
			cout << "\nSorry, " << response << " is not a valid entry. Try again.\n";
	} while (response != 'y' && response != 'Y' && response != 'n' && response != 'N');

	if (response == 'y' || response == 'Y')
		printList(head);
	
	cout << "\nProgram will now end\n\n";

	system("pause");
    return 0;
}

