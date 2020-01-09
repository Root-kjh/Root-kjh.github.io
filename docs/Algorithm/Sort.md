---
layout: default
title: 정렬(Sort)
parent: Algorithm
---

> n 개의 숫자가 주어졌을 때, 이를 사용자가 지정한 기준에 맞게 정렬하여 출력하는 알고리즘
    

## 정렬의 종류

* 선택 정렬(Selection Sort)

* 삽입 정렬(Insertion Sort)

* 버블 정렬(Bubble Sort)

* 병합 정렬(Merge Sort)

* 퀵 정렬(Quick Sort)
    
    > 분할 정복 알고리즘의 하나로, 평균적으로 매우 빠른 수행속도를 자랑한다.

    * 리스트 안의 한 요소를 선택한다. 이 요소를 피벗(pivot) 이라 부른다.

    * 피벗을 기준으로 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로, 큰 요소들은 오른쪽으로 옮겨진다.

    * 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다.

    * 분할된 부분 리스트에 대해 순환 호출을 이용해 정렬을 반복한다.

    * 부분 리스트의 크기가 0이나 1이 될 때까지 반복한다. 

    ```python
    table=[4,1,7,6,3,8,2,5]

    def Quick_Sort(low,high):
        global table

        if high-low<1:
            return

        tlow=low
        thigh=high
        pivot=high
        high-=1
        while high>=low:
            while table[low]<table[pivot] and low<=thigh:
                low+=1
            while table[high]>table[pivot] and high>=tlow:
                high-=1
            if high>low:
                temp=table[high]
                table[high]=table[low]
                table[low]=temp
                low+=1
                high-=1
        temp=table[low]
        table[low]=table[pivot]
        table[pivot]=temp
        Quick_Sort(tlow,low-1)
        Quick_Sort(low+1,thigh)

    if __name__ == "__main__":
        Quick_Sort(0,len(table)-1)
        print(table)
    ```

* 힙 정렬(Heap Sort)

* 팀 정렬(Tim Sort)

* 인트로 정렬(Intro Sort)

* 기수 정렬(Radix Sort)

* 카운팅 정렬(Counting Sort) : 수열에 해당하는 각 숫자의 갯수를 세어 정렬된 배열에 저장 후, 배열을 순회하며 작은 값에서 큰 값의 개수를 산출하는 알고리즘

    * O(n)의 시간 복잡도를 갖는다.

    * 0, 2, 0, 1000, 1, 3 과 같이 수가 넓게 분포되어 있는 경우 매우 비효율적인 알고리즘이다

    ```python
    def counting_sort(A, k):
        
        B = [-1] * len(A)
        
        C = [0] * (k + 1)
        
        for a in A:
            C[a] += 1
        
        for i in range(k):
            C[i+1] += C[i]
        
        for j in reversed(range(len(A))):
            B[C[A[j]] - 1] = A[j]
            C[A[j]] -= 1

        return B
    ```