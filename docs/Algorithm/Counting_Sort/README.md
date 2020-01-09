# 계수 정렬(Counting Sort)

>수열에 해당하는 각 숫자의 갯수를 세어 정렬된 배열에 저장 후, 배열을 순회하며 작은 값에서 큰 값의 개수를 산출하는 알고리즘

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