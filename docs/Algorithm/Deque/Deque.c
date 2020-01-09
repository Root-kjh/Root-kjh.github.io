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