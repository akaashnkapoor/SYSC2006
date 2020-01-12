/* SYSC 2006 Summer 2019 Lab 9
   linked_list.c - functions that operate on singly-linked lists of integers. 
 */

#include <assert.h>	// assert
#include <stdlib.h>	// malloc, free
#include <stdbool.h>
#include <stdio.h>	// printf

#include "linked_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Insert a new node containing data at the front of the linked list
 * pointed to by head. (If head is NULL, the linked list is empty.)
 * Return a pointer to the first node in the modified list.
 Terminate (via assert) if memory for the node cannot be allocated.
 */
node_t *push(node_t *head, int data)
{
	node_t *newnode = malloc(sizeof(node_t));
	assert(newnode != NULL);
	newnode->data = data;
	newnode->next = head;
	return newnode;
}

/* Return the number of nodes in the linked list pointed to by head.
 * (Return 0 if the linked list is empty.) 
 */
int length(node_t *head)
{
	int count = 0;
	for (node_t * current = head; current != NULL; current = current->next)
	{
		count += 1;
	}
	return count;
}

/* Print the linked list pointed to by head, using the format:
   value1 -> value2 -> value3 -> ... -> last_value
   Print NULL if the list is empty.
 */
void print_list(node_t *head)
{
	if (head == NULL)
	{
		printf("NULL");
		return;
	}

	node_t *curr;

	/* This loop prints every node in the linked list except the last one,
	   using the format "value -> ", where "->" represents the link from 
	   the currentnode to the node to the following node.

	   Notice that the loop condition is:
	   curr->next != NULL
	   and not:
	   curr != NULL

	   During the last iteration, the value in the second-last node is
	   printed, then curr is updated to point to the last node. The
	   condition curr->next != NULL now evaluates to false, so the 
	   loop exits, with curr pointing to the last node (which has  
	   not yet been printed.) 
	 */

	for (curr = head; curr->next != NULL; curr = curr->next)
	{
		printf("%d -> ", curr->data);
	}

	/* Print the last node. */
	printf("%d", curr->data);
}

/*****************************************************************
 * Solutions to Lab 9 exercises
 *****************************************************************/

// Exercise 1

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * 
 * Return 0 if the linked list is empty.
 */
int count(node_t *head, int target)
{
	int count = 0;
	for (node_t * current = head; current != NULL; current = current->next)
	{

		if (current->data == target)
		{
			count++;
		}

	}
	return count;
}

// Exercise 2

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the largest integer in the linked list.
 *
 * The function terminates (via assert) if the linked list is empty.
 */
int max(node_t *head)
{
	assert(head != NULL);
	int count = 0;
	int max = 0;
	for (node_t * current = head; current != NULL; current = current->next)
	{

		if (count == 0)
		{
			max = current->data;
		}

		if (max < current->data)
		{
			max = current->data;
		}
		count++;
	}
	return max;
}

// Exercise 3

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the integer stored in the node at the specified index.
 * (The first node is at index 0, the second node is at index 1, etc.)
 *
 * The function terminates (via assert) if the linked list is empty
 * or if index is invalid.
 */
int fetch(node_t *head, int index)
{
	assert(head != NULL);
	int len = length(head);
	assert(index >= 0 && index < len);

	int count = 0;
	for (node_t * current = head; current != NULL; current = current->next)
	{

		if (count == index)
		{
			return current->data;
		}

		count++;
	}

	return -1;
}

// Exercise 4

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the index (location) of the first node that contains an 
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 *
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int index(node_t *head, int target)
{
	if (head == NULL)
	{
		return -1;
	}

	int count = 0;
	for (node_t * current = head; current != NULL; current = current->next)
	{

		if (current->data == target)
		{
			return count;
		}

		count++;
	}

	return -1;
}

// Exercise 5

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Parameter other points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Extend the linked list pointed to by head so that it contains
 * copies of the values stored in the linked list pointed to by other.
 *
 * The function terminates (via assert) if the the linked list 
 * pointed to by head is empty.
 */
void extend(node_t *head, node_t *other)
{
		
	assert(head!=NULL);
    for( ; head->next != NULL; head = head->next);//Walks the pointer through head
        for(;other != NULL;other=other->next){ //Walks the pointer through other
          head->next = push(NULL, other->data);//Push a NULLed data structure and link with the head pointer
          head = head->next;//Head then points to the new node
        }
  

}//Doesn't matter where head is because when the function ends, the address of first remains head. 


