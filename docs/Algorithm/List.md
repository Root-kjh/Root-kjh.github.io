---
layout: default
title: 리스트(List)
parent: Algorithm
nav_order: 7
---

>정의되지 않은 갯수의 데이터를 관리하기 용이한 자료구조

## 리스트의 특징

* 크기가 유동적이므로 크기를 미리 몰라도 된다.

* 각각의 원소들은 자기 자신 다음의 원소만을 기억하고 있다.

* 어떠한 원소를 삽입/삭제할 때, 그 원소를 찾기 위해 O(n)의 시간이 추가적으로 발생하게 된다.

## 리스트의 종류

* Array List

	* 배열을 사용해 연결한 리스트

	```c
	#ifndef __ARRAY_LIST_H__
	#define __ARRAY_LIST_H__

	#define TRUE 1
	#define FALSE 0

	#define LIST_LEN 100

	typedef int LData;

	typedef struct __ArrayList
	{
		LData arr[LIST_LEN];
		int numOfData;
		int curPosition;
	} ArrayList;

	typedef ArrayList List;

	void ListInit(List * plist);
	void LInsert(List * plist, LData data);

	int LFirst(List * plist, LData * pdata);
	int LNext(List * plist, LData * pdata);

	LData LRemove(List * plist);
	int LCount(List * plist);

	#endif // !__ARRAY_LIST_H__
	```

	```c
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
	```

* Linked List

	* 각 원소를 포인터로 연결한 리스트 

	```c
	#ifndef __LINKED_LIST_H__
	#define __LINKED_LIST_H__

	#define TRUE 1
	#define FALSE 0

	#define LIST_LEN 100

	typedef int LData;

	typedef struct _node
	{
		LData data;
		struct _node *next;
	} Node;

	typedef struct _linkedList
	{
		Node * head;
		Node * cur;
		Node * before;
		int numOfData;
	}LinkedList;

	typedef LinkedList List;

	void ListInit(List * plist);
	void LInsert(List * plist, LData data);

	int LFirst(List * plist, LData * pdata);
	int LNext(List * plist, LData * pdata);

	LData LRemove(List * plist);
	int LCount(List * plist);


	#endif // !__LINKED_LIST_H__
	```

	```c
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
	```

* Circular Linked List

	* 일반적인 연결 리스트에 마지막 노드와 처음 노드를 연결시켜 원형으로 만든 리스트

	```c
	#ifndef __LINKED_LIST_H__
	#define __LINKED_LIST_H__

	#define TRUE 1
	#define FALSE 0

	#define LIST_LEN 100

	typedef int Data;

	typedef struct _node
	{
		Data data;
		struct _node *next;
	} Node;

	typedef struct _CLL
	{
		Node * tail;
		Node * cur;
		Node * before;
		int numOfData;
	}CList;

	typedef CList List;

	void ListInit(List * plist);
	void LInsert(List * plist, Data data);
	void LInsertFront(List * plist, Data data);
	int LFirst(List * plist, Data * pdata);
	int LNext(List * plist, Data * pdata);

	Data LRemove(List * plist);
	int LCount(List * plist);


	#endif // !__LINKED_LIST_H__
	```

	```c
	#include <stdio.h>
	#include <stdlib.h>
	#include "CLinkedList.h"

	void ListInit(List * plist) {
		plist->tail = NULL;
		plist->cur = NULL;
		plist->before = NULL;
		plist->numOfData = NULL;
	}

	void LInsert(List * plist, Data data) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (plist->tail == NULL) {
			plist->tail = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->next = plist->tail->next;
			plist->tail->next = newNode;
			plist->tail = newNode;
		}

		(plist->numOfData)++;

	}

	void LInsertFront(List * plist, Data data) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (plist->tail == NULL) {
			plist->tail = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->next = plist->tail->next;
			plist->tail->next = newNode;
		}

		(plist->numOfData)++;

	}

	int LFirst(List * plist, Data * pdata) {
		if (plist->tail == NULL)
			return FALSE;
		
		plist->before = plist->tail;
		plist->cur = plist->tail->next;

		*pdata = plist->cur->data;

		return TRUE;
	}

	int LNext(List * plist, Data * pdata) {
		if (plist->tail == NULL)
			return FALSE;

		plist->before = plist->cur;
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;

		return TRUE;
	}

	Data LRemove(List * plist) {
		Node * TempNode = plist->cur;
		Data TempData = TempNode->data;
		
		if (plist->tail == TempNode) {
			if (plist->tail == plist->tail->next)
				plist->tail = NULL;
			else
				plist->tail = plist->before;
		}

		plist->before->next = plist->cur->next;
		plist->cur = plist->before;

		(plist->numOfData)--;
		free(TempNode);

		return TempData;
	}

	int LCount(List * plist) {
		return plist->numOfData;
	}
	```

* Doubly linked list

	* 2개의 포인터 공간으로 앞 노드와 뒤 노드를 모두 가리키는 리스트

	```python
	class list:
		class Node:
			def __init__(self,data,next=None,prev=None):
				self.data=data
				self.next=next
				self.prev=prev

		def __init__(self):
			self.head=self.Node(None,None,None)
			self.tail=self.Node(None,None,self.head)
			self.head.next=self.tail
			self.sizze=0

		def size(self): return self.size
		def isEmpty(self): return self.size==0

		def insertBefore(self,p,data):
			t=p.prev
			n=self.Node(data,p,t)
			t.next=n
			p.prev=n
			self.size+=1

		def insertAfter(sefl,p,data):
			t=p.next
			n=self.Node(data,t,p)
			t.prev=n
			p.next=n
			self.size+=1

		def delete(self,x):
			f=x.prev
			r=x.next
			f.next=r
			r.prev=f
			self.size-=1
			return x.data

		def printList(self):
			if self.isEmpty():
				print("The list is empty")
			else:
				p=self.head.next
				while p!=self.tail:
					if p.next!=self.tail:
						print(p.data,"<=>" end='')
					else:
						print(p.data)
					p=p.next
	```