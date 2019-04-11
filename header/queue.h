#pragma once
#include "node.h"
#include "boolean.h"

typedef struct queue
{
	int maxSize;
	int front;
	int rear;
	Node* head;
}Queue;

Queue* newQueue(int maxSize);//새로운 Queue를 생성해 반환
boolean enqueue(Queue* queue, int data);//뒤에 삽입하는 기본적인 enqueue
boolean dequeue(Queue* queue);//앞을 삭제하는 기본적인 dequeue
boolean enqueueFront(Queue* queue, int data);//앞에 삽입하는 enqueue
boolean dequeueRear(Queue* queue);//뒤를 삭제하는 enqueue
boolean isFullQueue(Queue* queue);//큐가 꽉 찼는지 검사
boolean isEmptyQueue(Queue* queue);//큐가 비었는지 검사
int rear(Queue* queue);//rear의 요소를 반환(예외처리 x)