#pragma once

typedef struct node Node;

struct node
{
	int data;
	Node* next;
	Node* prev;
};