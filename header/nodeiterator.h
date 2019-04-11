#pragma once
#include "node.h"

//빠른 접근을 위한 []사용을 위해 접근자처럼 사용할
//구조체 iterator
typedef struct iterator
{
	int size;
	Node** nodeArray;
}nodeIterator;

Node* start(Node* node);//Node의 시작노드를 반환
Node* end(Node* node);//Node의 끝노드를 반환
nodeIterator* getIterator(Node* node);//iterator 생성 후 반환
void synchronize(nodeIterator** it, Node* node);//새로운 값이 들어오거나 삭제된 Node와의 동기화
void freeIterator(nodeIterator** it);//iterator free 함수