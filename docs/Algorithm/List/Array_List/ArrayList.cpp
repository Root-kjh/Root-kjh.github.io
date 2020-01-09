#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data) {
	if ((plist->numOfData) >= LIST_LEN) {
		puts("No more values ​​can be entered.");
		return;
	}
	
	(plist->arr[(plist->numOfData)]) = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->numOfData == 0)
		return FALSE;
	
	(plist->curPosition) = 0;
	*pdata = (plist->arr[0]);

	return true;
}

int LNext(List * plist, LData * pdata) {
	if ((plist->curPosition) + 1 >= (plist->numOfData))
		return FALSE;

	(plist->curPosition)++;
	*pdata = (plist->arr[(plist->curPosition)]);

	return TRUE;
}

LData LRemove(List * plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];

	while (rpos < num - 1) {
		plist->arr[rpos] = plist->arr[rpos + 1];
		rpos++;
	}

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int LCount(List * plist) {
	return (plist->numOfData);
}