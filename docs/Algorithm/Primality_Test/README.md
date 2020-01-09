# 소수 판별법(Primality Test)

> 1과 자기 자신으로만 나누어지는 자연수를 찾는 방법에 대해 학습

## 기본 방법

1부터 특정 수 까지 순회하며 1과 자기 자신 외의 약수가 있지 않을 경우 소수로 판단한다.

```python
def is_prime(n):
    if n==1:
        return False
        
    for i in range(1,n+1):
        if i!=1 and i!=n:
            if n%i==0:
                return False
    return True
```

## 제곱근를 이용한 방법

1부터 특정 수 까지 순회할 필요 없이 n의 제곱근 까지 순회한다.(i*i=n 이기 때문에 n의 제곱근 이상 검사하는 것이 의미가 없다.)

```python
import math

def is_prime(n):
    if n==1:
        return False
        
    for i in range(1,math.sqrt(n)+1):
        if i!=1:
            if n%i==0:
                return False
    return True
```

## 에라토스테네스의 체

일정 범위에 속하는 모든 소수들을 구할 때 적합한 방법이다.

구하고 싶은 소수의 범위를 배열로 선언한 뒤, 소수를 판별하여 판별된 소수의 배수를 모두 합성수로 판단한다.

```python
import math

def is_prime(n):
    arr=[True]*(n+1)
    arr[0]=False
    arr[1]=False
    for i in range(2,math.sqrt(n)+1):
        prime_flag=True
        for j in range(2,math.sqrt(i)+1):
            if i%j==0:
                prime_flag=False
        if prime_flag:
            for j in range(i*2,n+1,i):
                arr[j]=False
    return arr
```
## AKS 소수판별법
>수학적 지식이 부족해 직접 구현할 수 없었고, 예제 코드도 찾지 못했기에 아래 합동식을 이해할 수 있을 때 다시 코드구현을 해보겠습니다.

n은 n과 서로소인 모든 정수 a에 대해 다음 합동식이 성립할 때만 소수이며, 그렇지 않으면 합성수이다.

![AKS 소수 판별법-합동식](https://wikimedia.org/api/rest_v1/media/math/render/svg/da2b748412959ef2df65dc78a826c55931069506)

## 리먼 소인수분해

## 페르마의 소인수분해

## 리먼+페르마 알고리즘 융합