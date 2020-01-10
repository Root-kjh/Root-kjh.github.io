---
layout: default
title: 스택(Stack)
parent: Algorithm
nav_order: 11
---

>한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Las In First Out) 형식의 구조

## 스택의 종류

* Array Stack
    
    * 전역 배열상태로 존재하는 정적 Stack

    ```c
    #ifndef __AB_STACK_H__
    #define __AB_STACK_H__

    #define TRUE 1
    #define FALSE 0
    #define STACK_LEN 100

    typedef int Data;

    typedef struct _arrayStack {
        Data stackArr[STACK_LEN];
        int topIndex;
    } ArrayStack;

    typedef ArrayStack Stack;

    void StackInit(Stack * pstack);
    int SIsEmpty(Stack * pstack);

    void SPush(Stack * pstack, Data data);
    Data SPop(Stack * pstack);
    Data SPeek(Stack * pstack);

    #endif // !__AB_STACK_H__
    ```

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include "ArrayBaseStack.h"

    void StackInit(Stack * pstack) {
        pstack->topIndex = -1;
    }

    int SIsEmpty(Stack * pstack) {
        if (pstack->topIndex == -1)
            return TRUE;
        else
            return FALSE;
    }

    void SPush(Stack * pstack, Data data) {
        pstack->topIndex += 1;
        pstack->stackArr[pstack->topIndex] = data;
    }

    Data SPop(Stack * pstack) {
        int rIdx;
        if (SIsEmpty(pstack)) {
            printf("Stack Memory Error!");
            exit(-1);
        }
        rIdx = pstack->topIndex;
        pstack->topIndex -= 1;

        return pstack->stackArr[rIdx];
    }

    Data SPeek(Stack * pstack) {
        if (SIsEmpty(pstack)) {
            printf("Stack Memory Error!");
            exit(-1);
        }
        
        return pstack->stackArr[pstack->topIndex];
    }
    ```

* Linked List Stack

    * malloc()을 사용한 동적 할당 Stack

    ```c
    #ifndef __LB_STACK_H__
    #define _LB_STACK_H__

    #define TRUE 1
    #define FALSE 0

    typedef int Data;

    typedef struct _node{
        Data data;
        struct _node * next;
    } Node;

    typedef struct _listStack {
        Node * head;
    }ListStack;

    typedef ListStack Stack;

    void StackInit(Stack * pstack);
    int SIsEmpty(Stack * pstack);

    void SPush(Stack * pstack, Data data);
    Data SPop(Stack * pstack);
    Data SPeek(Stack * pstack);

    #endif // !__LB_STACK_H__
    ```

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include "ListBaseStack.h"

    void StackInit(Stack * pstack) {
        pstack->head = NULL;
    }

    int SIsEmpty(Stack * pstack) {
        if (pstack->head == NULL)
            return TRUE;
        else
            return FALSE;
    }

    void SPush(Stack * pstack, Data data) {
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = pstack->head;
        pstack->head = newNode;
    }

    Data SPop(Stack * pstack) {
        Data rdata;
        Node * rnode;
        
        if (SIsEmpty(pstack)) {
            printf("Stack Memory Error!");
            exit(-1);
        }

        rdata = pstack->head->data;
        rnode = pstack->head;

        pstack->head = pstack->head->next;

        free(rnode);
        return rdata;
    }

    Data SPeek(Stack * pstack) {
        if (SIsEmpty(pstack)) {
            printf("Stack Memory Error!");
            exit(-1);
        }

        return pstack->head->data;
    }
    ```