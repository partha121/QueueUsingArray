/*
 * QueueUsingArray.c
 *
 *  Created on: 19-Aug-2018
 *      Author: partha
 */

//NOTE: GO Assignment Part 1 and Assignment Part 2 are included in the below code

#include <stdio.h>
#include <stdlib.h>
#define size 5

struct queue
{
	int array[size];
	int front, rear;
	//char full;
};

int enqueue(struct queue * myqueue, int elem)
{
	/*if(myqueue -> full){
			printf("Queue is full");
			return -1;

	}*/

	if(++(myqueue->rear)% size == myqueue->front){//precedence of ++ is higher than mod(%)
			printf("Queue overflow.\n");
			myqueue->rear = size-1;
			return -1;
	}
	else{
		myqueue->array[(myqueue->rear)%size]=elem;
		return 0;
	}
}

int dequeue(struct queue *myqueue, int *status)
{
	if(myqueue->rear == myqueue->front){
			printf("queue underflow.\n");
			*status=0;
			return -1;
	}

	else{
			*status=1;
			int item=myqueue->array[++myqueue->front%size];
			return item;
	}

}

void init(struct queue *myqueue)
{
	myqueue -> front = 0;
	myqueue -> rear = 0;
	//myqueue -> full = 0;
}

int main()
{
	int elem;
	struct queue myqueue;
	init(&myqueue);
	int choice;
	int val, status;
	while(-100)//any non-zero value makes condition true
	{
	        printf("\nEnter:\n\t1 - to Insert to Queue\n\t2 - to Delete from Queue\n\t0 - to Exit: ");
	        scanf("%d", &choice);
	        switch(choice)
	        {
	            case 1:
	                printf("Please enter the queue element: ");
	                scanf("%d", &elem);
	                enqueue(&myqueue, elem);
	                break;
	            case 2:
	                val = dequeue(&myqueue, &status);
	                if(status  == 1)
	                {
	                    printf("Removed queue element is: = %d\n", val);
	                }
	                break;
	            case 0:
	            	printf("Thank you.\n");
	            	exit(0);

	        }
	}
	printf("\n");
	return 0;

}
