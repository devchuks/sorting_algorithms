#include "sort.h"

/**
 * swap_node - swap two nodes in a doubly linked list
 * @a: address of the first node
 * @b: address of the second node
 *
 * Return: void
 */

void swap(listint_t *big, listint_t *small)
{
	/* if big is not the first node */
	if (big->prev)
		big->prev->next = small;
	/* if small is not the last node */
	if (small->next)
		small->next->prev = big;
	big->next = small->next;
	small->prev = big->prev;
	big->prev = small;
	small->next = big;
}

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: the list of integers to be sorted
 *
 * Description: Use the insertion sort algorithm to sort a doubly linked list
 * of integers in ascending order. Print the whole list each time two nodes are
 * swapped to show how the sort progresses.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nextNode, *current;

	if (!list || !*list || !(*list)->next)
		return;

	/*
	 * set tracking pointer to the second node in the list
	 * because we start by comparing the second node to the first
	 */
	nextNode = (*list)->next;
	while (nextNode)
	{
		/* move pointers to the next pair of nodes */
		current = nextNode;
		nextNode = nextNode->next;
		/* while the node we're working with isn't NULL */
		while (current && current->prev)
		{
			/* if previous node's value > current node's value */
			if (current->prev->n > current->n)
			{
				swap(current->prev, current);
				/*
				 * if the prev pointer is NULL, current is now
				 * the head of the list, reset list pointer
				 */
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
