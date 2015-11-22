#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue_fun.h"

/*
this function adds element of local structure
to common queue.
it returns pointer of added structure to
common array, for it future sorting 
*/
struct queue * add_to_queue(struct queue * locale, struct queue * next)
{
	next->next = locale->next;
	next->prev = locale;
	locale->next = next;
	return next;
}

/*
this function prints all elements in queue

n - count of elements in queue
*/
void print_all_queue(struct queue ** array, int n)
{
	int i;
	printf("\n");
	for(i = 0; i < n; i++ )
	{
		printf("%d ", array[i]->data);
	}
	printf("\n");
}

/*
this function sorts all elements in array
for binary search

n - index of added element to array
*/
void sorting(struct queue ** array, int n)
{
	struct queue * buffer = NULL;
	int i;
	for(i = 0; i < n; i++)
	{
		if((array[i]->data) <= (array[n]->data))
		{
			buffer = array[i];
			array[i] = array[n];
			array[n] = buffer;
		}
	}
}

/*
this function finds "key" in "array" 
with "count" elements and returns:
index of this element
-1 if element does not exists
*/
int binary_search(struct queue ** array, int count, int key)
{
	int l = 0, r = count, i = 1;

	while(i != 0)
	{
		i = (l+r)/2;
		if((array[i]->data) > key)
		{
			l = i;
		}
		if((array[i]->data) < key)
		{
			r = i;
		}
		if((array[i]->data) == key)
			return i;
	}
	return -1;
}

/*
this function deletes element 
from "array" and queue
n - index of deleting element
*count - pointer on count of elements in queue 

*/
void deleting(struct queue ** array, int n, int *count)
{
	int i;
	(array[n]->prev)->next = array[n]->next;
	(array[n]->next)->prev = array[n]->prev;
	free(array[n]);
	for(i = n; i <= (*count) - 1; i++)
	{
		array[i] = array[i+1];
	}
	array[(*count)] = NULL;
	(*count)--;
}

void interface(void)
{
	printf("1 - To add element\n");
	printf("2 - To print all elements\n");
	printf("3 - To delete element\n");
	printf("4 - To exit from program\n");
}