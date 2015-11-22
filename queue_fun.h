#ifndef QUEUE_FUN_H
#define QUEUE_FUN_H
#include "queue_fun.h"
struct queue { 	int data;
				struct queue *next;
				struct queue *prev;
				};
struct queue * add_to_queue(struct queue *, struct queue *);
void print_all_queue(struct queue **, int);
void interface(void);
int binary_search(struct queue **, int, int);
void deleting(struct queue **, int , int *);
void sorting(struct queue **, int);
#endif
