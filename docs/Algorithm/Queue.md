---
layout: default
title: 큐(Queue)
parent: Algorithm
---

>먼저 넣은 데이터가 먼저 나오는 FIFO(First In First Out) 구조로 저장하는 자료구조이다.

## 큐의 종류

* Queue

	* 선형으로 이루어진 큐

* Circular Queue

	* front가 큐의 끝에 닿으면 큐의 맨 앞으로 자료를 보내어 원형으로 현결하는 큐
		
	```c
	#ifndef __C_QUEUE_H__
	#define __C_QUEUE_H__

	#define TRUE 1
	#define FALSE 0

	#define QUE_LEN 100
	typedef int Data;

	typedef struct _cQueue{
		int front;
		int rear;
		Data queArr[QUE_LEN];
	} CQueue;

	typedef CQueue Queue;

	void QueueInit(Queue * pq);
	int QIsEmpty(Queue * pq);

	void Enqueue(Queue * pq, Data data);
	Data Dequeue(Queue * pq);
	Data QPeek(Queue * pq);

	#endif // !__C_QUEUE_H__
	```

	```c
	#include <stdio.h>
	#include <stdlib.h>
	#include "Circular_Queue.h"

	void QueueInit(Queue * pq) {
		pq->front = 0;
		pq->rear = 0;
	}

	int QIsEmpty(Queue * pq) {
		if (pq->front == pq->rear)
			return TRUE;
		else 
			return FALSE;
	}

	int NextPosIdx(int pos) {
		if (pos == QUE_LEN - 1)
			return 0;
		else
			return pos + 1;
	}

	void Enqueue(Queue * pq, Data data) {
		if (NextPosIdx(pq->rear) == pq->front) {
			printf("Queue Memory Error!");
			exit(-1);
		}
		pq->rear = NextPosIdx(pq->rear);
		pq->queArr[pq->rear]=data;
	}

	Data Dequeue(Queue * pq) {
		if (QIsEmpty(pq)) {
			printf("Queue Memory Error!");
				exit(-1);
		}
		pq->front = NextPosIdx(pq->front);
		return pq->queArr[pq->front];
	}

	Data QPeek(Queue * pq) {
		if (QIsEmpty(pq)) {
			printf("Queue Memory Error!");
			exit(-1);
		}
		return pq->queArr[NextPosIdx(pq->front)];
	}
	```

* List Base Queue

	* 연결 리스트로 구현해 길이를 쉽게 늘릴 수 있는 큐

	```c
	#ifndef __LB_QUEUE_H__
	#define __LB_QUEUE_H__

	#define TRUE 1
	#define FALSE 0

	typedef int Data;

	typedef struct _node
	{
		Data data;
		struct _node * next;
	} Node;

	typedef struct _lQueue{
		Node * front;
		Node * rear;
	} LQueue;

	typedef LQueue Queue;

	void QueueInit(Queue * pq);
	int QIsEmpty(Queue * pq);

	void Enqueue(Queue * pq, Data data);
	Data Dequeue(Queue * pq);
	Data QPeek(Queue * pq);

	#endif // !__LB_QUEUE_H__
	```

	```c
	#include <stdio.h>
	#include <stdlib.h>
	#include "ListBaseQueue.h"

	void QueueInit(Queue * pq) {
		pq->front = NULL;
		pq->rear = NULL;
	}

	int QIsEmpty(Queue * pq) {
		if (pq->front == NULL)
			return TRUE;
		else
			return FALSE;
	}

	void Enqueue(Queue * pq, Data data) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->data = data;
		if (QIsEmpty(pq)) {
			pq->rear = newNode;
			pq->front = newNode;
		}
		else {
			pq->rear->next = newNode;
			pq->rear = newNode;
		}
		
	}

	Data Dequeue(Queue * pq) {
		if (QIsEmpty(pq)) {
			printf("Queue Memory Error!");
			exit(-1);
		}
		Node* temp = pq->front;
		Data retData = temp->data;
		pq->front = pq->front->next;

		free(temp);
		return retData;
	}

	Data QPeek(Queue * pq) {
		if (QIsEmpty(pq)) {
			printf("Queue Memory Error!");
			exit(-1);
		}
		return pq->front->data;
	}
	```