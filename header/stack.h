#pragma once
#include "node.h"
#include "boolean.h"

typedef struct stack
{
	int maxSize;
	int top;
	Node* head;
}Stack;

Stack* newStack(int maxSize);//새로운 Stack를 생성해 반환
boolean push(Stack* stack, int data);//데이터를 넣는 push 함수
boolean pop(Stack* stack);//데이터를 삭제하는 pop 함수
boolean isFullStack(Stack* stack);//스택이 꽉 찼는지 검사
boolean isEmptyStack(Stack* stack);//스택이 비었는지 검사
int top(Stack* stack);//top의 요소를 반환(예외처리 x)