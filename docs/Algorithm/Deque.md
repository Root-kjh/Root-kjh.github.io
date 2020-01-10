---
layout: default
title: 덱(Deque)
parent: Algorithm
nav_order: 3
---

> 삽입과 삭제가 양 쪽에서 가능한 자료구조

## 덱의 특징

* 크기가 가변적이다.

* 앞과 뒤에서 삽입 삭제가 가능하다.

* 중간에 데이터 삽입, 삭제가 용이하지 않다.

## Operations

* void DequeInit(Deque * pdeq);

    덱의 초기화를 진행한다.
    
    덱 생성 후 제일 먼저 호출되어야 하는 함수이다.

* int DQIsEmpty(Deque * pdeq);
>덱이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

* void DQAddFirst(Deque * pdeq, Data data);
> 덱의 머리에 데이터를 저장한다. data로 전달된 값을 저장한다.

* void DQAddLast(Deque * pdeq, Data data);
> 덱의 꼬리에 데이터를 저장한다. data로 전달된 값을 저장한다.

* Data DQRemoveFirst(Deque * pdeq);
>덱의 머리에 위치한 데이터를 반환 및 소별한다.

* Data DQRemoveLast(Deque * pdeq);
> 덱의 꼬리에 위치한 데이터를 반환 및 소멸한다.

* Data DQGetFirst(Deque * pdeq);
> 덱의 머리에 위치한 데이터를 소멸하지 않고 반환한다.

* Data DQGetLast(Deque * pdeq);
> 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.

```c
#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _dlDeque{
	Node * head;
	Node * tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque * pdeq);
int DQIsEmpty(Deque * pdeq);

void DQAddFirst(Deque * pdeq, Data data);
void DQAddLast(Deque * pdeq, Data data);

Data DQRemoveFirst(Deque * pdeq);
Data DQRemoveLast(Deque * pdeq);

Data DQGetFirst(Deque * pdeq);
Data DQGetLast(Deque * pdeq);

#endif // !__DEQUE_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq) {
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = pdeq->head;
	newNode->prev = NULL;
	newNode->data = data;
	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = pdeq->tail;
	newNode->data = data;
	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq) {
	Node * rnode = pdeq->head;
	Data retData = rnode->data;

	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->head = pdeq->head->next;
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	free(rnode);
	return retData;
}

Data DQRemoveLast(Deque * pdeq) {
	Node * rnode = pdeq->tail;
	Data retData = rnode->data;

	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->tail = pdeq->tail->prev;
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	free(rnode);
	return retData;
}

Data DQGetFirst(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;

}

Data DQGetLast(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}
```