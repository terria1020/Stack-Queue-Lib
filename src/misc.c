#include "../header/misc.h"
#include "../header/nodeIterator.h"
#include <stdio.h>

void swapData(Node* node, int index1, int index2)
{
	nodeIterator* it = getIterator(node);
	int temp = it->nodeArray[index1]->data;
	it->nodeArray[index1]->data = it->nodeArray[index2]->data;
	it->nodeArray[index2]->data = temp;
	freeIterator(&it);
}
void printQueue(Queue* queue)
{
	if (queue->rear == -1) return;

	nodeIterator* it = getIterator(queue->head);
	if (it->size == 1)
	{
		printf("%d\t[front = rear]\n", it->nodeArray[0]->data);
	}
	else
	{
		printf("%d\t[front]\n", it->nodeArray[0]->data);
		for (int i = 1; i < it->size - 1; i++)
		{
			printf("%d\n", it->nodeArray[i]->data);
		}
		printf("%d\t[rear]\n", it->nodeArray[it->size - 1]->data);
	}
	freeIterator(&it);
}
void printStack(Stack* stack)
{
	if (stack->top == -1) return;
	else
	{
		nodeIterator* it = getIterator(stack->head);
		printf("%d\t[top]\n", it->nodeArray[0]->data);
		for (int i = 1; i < it->size; i++)
		{
			printf("%d\n", it->nodeArray[i]->data);
		}
		freeIterator(&it);
	}
}
int getData(Node* node, int index)
{
	Node* temp = node;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}
boolean isPalindrome(Node* node)
{
	nodeIterator* it = getIterator(node);
	for (int i = 0; i < it->size / 2; i++)
	{
		if (it->nodeArray[i]->data != it->nodeArray[it->size - i - 1]->data)
		{
			freeIterator(&it);
			return FALSE;
		}
	}
	freeIterator(&it);
	return TRUE;
}
boolean isHaveSubStack(Stack* mainStack, Stack* subStack)
{
	return isHaveSubNode(mainStack->head, subStack->head);
}
boolean isHaveSubQueue(Queue* mainQueue, Queue* subQueue)
{
	return isHaveSubNode(mainQueue->head, subQueue->head);
}
boolean isHaveSubNode(Node* mainNode, Node* subNode)
{
	nodeIterator* mainIt = getIterator(mainNode);
	nodeIterator* subIt = getIterator(subNode);

	for (int i = 0; i < mainIt->size; i++)
	{
		if (mainIt->nodeArray[i]->data == subIt->nodeArray[0]->data)
		{
			for (int j = 1; j < subIt->size; j++)
			{
				i++;
				if (mainIt->nodeArray[i]->data != subIt->nodeArray[j]->data)
				{
					freeIterator(&mainIt);
					freeIterator(&subIt);
					return FALSE;
				}
			}
			freeIterator(&mainIt);
			freeIterator(&subIt);
			return TRUE;
		}
	}
	freeIterator(&mainIt);
	freeIterator(&subIt);
	return FALSE;
}
Stack* getReverseStack(Stack* original)
{
	Stack* stack = newStack(original->maxSize);
	for (Node* temp = original->head; temp != NULL; temp = temp->next)
	{
		push(stack, temp->data);
	}
	return stack;
}
Queue* getReverseQueue(Queue* original)
{
	Queue* queue = newQueue(original->maxSize);
	for (Node* temp = original->head; temp != NULL; temp = temp->next)
	{
		enqueueFront(queue, temp->data);
	}
	return queue;
}
Stack* QueueToStack(Queue* original)
{
	Stack* stack = newStack(original->maxSize);
	for (Node* temp = end(original->head); temp != NULL; temp = temp->prev)
	{
		push(stack, temp->data);
	}
	return stack;
}
Queue* StackToQueue(Stack* original)
{
	Queue* queue = newQueue(original->maxSize);
	for (Node* temp = original->head; temp != NULL; temp = temp->next)
	{
		enqueue(queue, temp->data);
	}
	return queue;
}