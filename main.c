#include <stdio.h>
#include <stdlib.h>
#include "header/stack.h"
#include "header/queue.h"
#include "header/nodeiterator.h"
#include "header/misc.h"

int main(int argc, char const *argv[])
{
	Stack* stack = newStack(10);
	for (int i = 0; i < 10; i++)
	{
		push(stack, i + 1);
	}
	printStack(stack);
}