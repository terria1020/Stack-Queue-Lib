#pragma once
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "boolean.h"

void swapData(Node* node, int index1, int index2);//index1과 index2에 있는 값을 swap
void printQueue(Queue* queue);//queue의 데이터를 출력
void printStack(Stack* stack);//stack의 데이터를 출력
int getData(Node* node, int index);//index번 째의 데이터를 가져옴(예외처리 x)
boolean isPalindrome(Node* node);//팰린드롬 노드인지 검사
boolean isHaveSubStack(Stack* mainStack, Stack* subStack);//Stack안에 subStack이 포함되어 있는지 검사
boolean isHaveSubQueue(Queue* mainQueue, Queue* subQueue);//Queue안에 subQueue가 포함되어 있는지 검사
boolean isHaveSubNode(Node* mainNode, Node* subNode);//Node안에 subNode가 포함되어 있는지 검사
Stack* getReverseStack(Stack* original);//거꾸로 된 Stack를 반환
Queue* getReverseQueue(Queue* original);//거꾸로 된 Queue를 반환
Stack* QueueToStack(Queue* original);//Queue에서 데이터를 정방향 순서대로 가지고 있는 Stack포인터를 만들어 반환
Queue* StackToQueue(Stack* original);//Stack에서 데이터를 정방향 순서대로 가지고 있는 Queue포인터를 만들어 반환