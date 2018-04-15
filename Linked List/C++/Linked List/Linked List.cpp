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
	Node *head = new Node;
	Node *second = new Node;
	Node *third = new Node;
	Node *h_ref = head;

	head->age = 26;
	head->next = second;

	second->age = 29;
	second->next = third;

	third->age = 55;
	third->next = NULL;
	do {
		cout << "Would you like to create a new entry? (y/n): ";
		cin >> response;
	} while (response == 'y' || response == 'Y');

	printList(head);

	system("pause");
    return 0;
}

