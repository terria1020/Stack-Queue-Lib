#include "../header/stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack* newStack(int maxSize)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->maxSize = maxSize;
	stack->top = -1;
	stack->head = NULL;
	return stack;
}
boolean push(Stack* stack, int data)
{
	if (stack->top == stack->maxSize - 1) return FALSE;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (stack->head == NULL)
	{
		stack->head = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->top++;
	return TRUE;
}
boolean pop(Stack* stack)
{
	if (stack->top < 0) return FALSE;
	else if (stack->head->next == NULL)
	{
		free(stack->head);
		stack->head = NULL;
	}
	else
	{
		Node* temp = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		free(temp);
	}
	stack->top--;
	return TRUE;
}
boolean isFullStack(Stack* stack)
{
	if (stack->top == stack->maxSize - 1) return TRUE;
	else return FALSE;
}
boolean isEmptyStack(Stack* stack)
{
	if (stack->top == -1) return TRUE;
	else return FALSE;
}
int top(Stack* stack)
{
	return stack->head->data;
}