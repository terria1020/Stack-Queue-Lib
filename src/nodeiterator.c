#include "../header/nodeiterator.h"
#include <stdlib.h>

Node* start(Node* node)
{
	return node;
}
Node* end(Node* node)
{
	Node* temp = node;
	while (temp->next != NULL) temp = temp->next;
	return temp;
}
nodeIterator* getIterator(Node* node)
{
	nodeIterator* it = (nodeIterator*)malloc(sizeof(nodeIterator));
	Node* temp = node;
	int size = 0;
	for (; temp != NULL; temp = temp->next)
	{
		size++;
	}
	it->size = size;

	it->nodeArray = (Node**)malloc(sizeof(Node*) * it->size);
	temp = node;
	for (int i = 0; i < size; i++)
	{
		it->nodeArray[i] = temp;
		temp = temp->next;
	}
	return it;
}
void synchronize(nodeIterator** it, Node* node)
{
	freeIterator(it);
	*it = getIterator(node);
}
void freeIterator(nodeIterator** it)
{
	free((*it)->nodeArray);
	free(*it);
}