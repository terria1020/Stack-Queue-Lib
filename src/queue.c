#include "../header/queue.h"
#include <stdlib.h>

Queue* newQueue(int maxSize)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->maxSize = maxSize;
	queue->front = queue->rear = -1;
	queue->head = NULL;
	return queue;
}
boolean enqueue(Queue* queue, int data)
{
	if (queue->rear == queue->maxSize - 1) return FALSE;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (queue->head == NULL)
	{
		queue->head = node;
		queue->front++;
	}
	else
	{
		Node* temp = queue->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
		node->prev = temp;
	}
	queue->rear++;
	return TRUE;
}
boolean dequeue(Queue* queue)
{
	if (queue->rear < 0) return FALSE;
	else if (queue->head->next == NULL)
	{
		free(queue->head);
		queue->head = NULL;
	}
	else
	{
		Node* temp = queue->head;
		queue->head = queue->head->next;
		queue->head->prev = NULL;
		free(temp);
	}
	queue->rear--;
	return TRUE;
}
boolean enqueueFront(Queue* queue, int data)
{
	if (queue->rear == queue->maxSize - 1) return FALSE;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (queue->head == NULL)
	{
		queue->head = node;
	}
	else
	{
		node->next = queue->head;
		queue->head->prev = node;
		queue->head = node;
	}
	queue->rear++;
	return TRUE;
}
boolean dequeueRear(Queue* queue)
{
	if (queue->rear < 0) return FALSE;
	else if (queue->head->next == NULL)
	{
		free(queue->head);
		queue->head = NULL;
	}
	else
	{
		Node* temp = queue->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
	queue->rear--;
	return TRUE;
}
boolean isFullQueue(Queue* queue)
{
	if (queue->rear == queue->maxSize - 1) return TRUE;
	else return FALSE;
}
boolean isEmptyQueue(Queue* queue)
{
	if (queue->rear >= 0) return TRUE;
	else return FALSE;
}
int rear(Queue* queue)
{
	Node* temp = queue->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp->data;
}