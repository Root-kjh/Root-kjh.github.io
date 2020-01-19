---
layout: default
title: 가장 긴 증가하는 부분수열(LIS)
parent: Algorithm
nav_order: 13
---

    LIS(Longest Increasing Subsequence)는 앞에서부터 뒤로 숫자를 선택하며 부분 수열을구성해 나갈 때
    
     증가하는 순서대로 숫자를 고르면서 고른 부분 수열의 길이가 최대 길이가 되도록 숫자를 선택하는 알고리즘이다.

![LIS](https://t1.daumcdn.net/cfile/tistory/217AA83B5888A4B936)

## 기본 방법

    O(N^2)의 시간복잡도를 가지는 DP로 구현하는 방법

    dp 테이블 dp[x]는 x번째 수를 마지막 원소로 가지는 lis의 길이이다.

    그렇게 되면 dp[x] 는 수열의 x번째 값보다 작은 dp[0]~dp[x-1] 값 중, 가장 큰 값+1이 된다.

```python
n=int(input())
table=list(map(int,input().split()))
dp=[0]*len(table)
max_dp=0
for i in range(n):
    count=0
    for j in range(i):
        if dp[j]>count and table[j]<table[i]:
            count=dp[j]
    dp[i]=count+1
    if max_dp<dp[i]:
        max_dp=dp[i]
print(max_dp)
```