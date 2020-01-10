---
layout: default
title: 피보나치(Fibonacci)
parent: Algorithm
nav_order: 5
---

> fibo(n)=fibo(n-1)+fibo(n-2) 로, n번째 수를 구하는 알고리즘에 대해 학습

## 기본 풀이
>fibo(n) 함수가 fibo(n-1), fibo(n-2) 함수를 재귀적으로 호출해 모든 값을 합한 후 n번째 fibonacci 값을 반환한다.
```python
def fibo(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)
```

## 동적 계획법 풀이
>fibo(n-1) fibo(n-2)값 만을 가지고 반복적으로 더해 값을 구한다.
```python
def fibo(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        fibo_list=[0,1]
        for i in range(n-1):
            temp=fibo_list[0]
            fibo_list[0]=fibo_list[1]
            fibo_list[1]=fibo_list[0]+temp
        return fibo_list[1]
```

## 일반항을 사용한 풀이
>n번째 피보나치 수를 구하는 일반항을 이용해 값을 구한다.
```python
def fibo(n):
    sqrt_5=5**(1/2)
    ans=1/sqrt_5*(((1 + sqrt_5) / 2) ** n - ((1 - sqrt_5) / 2) ** n )
    return int(ans)
```

### 피보나치 수열의 일반항을 구하는 방법
>피보나치 수열의 일반항을 구하기 위해선 여러 수학적 개념에 대해 알고있어야 합니다.

* 등차수열의 점화식

* 등차수열의 일반항

* 등차수열의 점화식을 일반항으로 변환하기

#### 등차수열의 점화식
```
a(1)=3

a(2) = 5
a(3) = 7
```
위와같은 식이 있다고 가정할 때, 점화식은
```
a(n)=a(n-1)+2
```
F(1)=1, F(2)=1

F(n+2)=F(n+1)+F(n)

#### 등차수열의 일반항
다음은 수열 3,5,7 . . . 을 a(n)에 대해 n으로 나타낸 식입니다.
```
a(n)=3+2(n-1)

a(5)=3+2(5-1) = 3+2(4) = 3+8 = 11
```

#### 등차수열의 점화식을 일반항으로 변환하기

```
a(1)=3
a(m)=(an-1)+2
```
이 식에서 첫째항은 3, 공차는 2 입니다.
따라서 첫째항은 A이고 공차가 B일 때, 일반항은 
```
A+B(n-1)
```
따라서 수열의 일반항은
```
a(n)=3+2(n-1)
```

### 피보나치 수열의 일반항
```
a(1)=1 , a(2)=1

a(n+2)=a(n+1)+a
```

>학습 후 재 업로드 예정