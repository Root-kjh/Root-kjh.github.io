# 덱(Deque)
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