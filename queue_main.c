#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue_fun.h"

typedef struct queue queue;

int main()
{
	int max_in_queue, change, current_element_index = -1;
	queue **array, *new_element;
	int i;

	printf("Please, enter maximal length of your queue\n");
	scanf("%d",&max_in_queue);

	array = (queue**)malloc(max_in_queue);

	while(1)
	{
		interface();
		scanf("%d", &change);

		switch(change)
		{
			case 1:
				current_element_index++;
				new_element = malloc(sizeof(queue));
				printf("Please, enter adding element ");
				scanf("%d", &(new_element->data));
				printf("\n");
				if(current_element_index == max_in_queue)
				{
					printf("Sorry, maximal count of elements in queue. Press '3' for deleting some element\n");
					current_element_index--;
					break;
				}
				if(current_element_index == 0)
					array[current_element_index] = add_to_queue(new_element, new_element);
				else
					array[current_element_index] = add_to_queue(array[current_element_index - 1], new_element);
				sorting(array, current_element_index);
				break;
			case 2:
				if(current_element_index < 0)
					printf("No elements in queue\n");
				else
					print_all_queue(array, current_element_index+1);
				break;
			case 3:
				printf("Please, enter any element index [0 - %d] for it deleting\n", current_element_index);
				scanf("%d", &change);
				if((change < 0) || (change > current_element_index))
				{
					printf("Incorrect number\n");
					break;
				}
				else
				deleting(array,change,&current_element_index);
				break;
			case 4:
				for(i = 0; i <=current_element_index; i++)
				{
					free(array[i]);
				}
				exit(1);
				break;
			default:
				printf("Incorrect number, try again\n");
				break;
		}

	}
}