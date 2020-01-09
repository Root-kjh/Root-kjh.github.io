#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List * plist) {
	plist->head = ((Node*)malloc(sizeof(Node)));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void SInsert(List * plist, LData data) {

}

void LInsert(List * plist, LData data) {
	Node * TempPlist = plist->head;

		Node * newNode = ((Node*)malloc(sizeof(Node)));
		newNode->data = data;
		newNode->next = plist->head->next;
		plist->head->next = newNode;
		(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

LData LRemove(List * plist) {
	Node * TempNode = plist->cur;
	LData TempData = TempNode->data;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	(plist->numOfData)--;
	free(TempNode);

	return TempData;
}

int LCount(List * plist) {
	return plist->numOfData;
}