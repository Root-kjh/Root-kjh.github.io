---
layout: default
title: 문자열 찾기(String Matching)
parent: Algorithm
nav_order: 14
---

# 기본 문자열 탐색법

패턴과 문자열을 한 글자씩 검사해가며 확인하는 방식

```python
def default(context,keyword):
    key_count=0
    keyword_len=len(keyword)
    pos=0
    count=0
    for idx in range(len(context)-keyword_len+1):
        while True:
            if context[idx+key_count]==keyword[key_count]:
                key_count+=1
                if key_count==keyword_len:
                    count+=1
                    key_count=0
                    break
            else:
                key_count=0
                break
    return count
```

# 라빈-카프 알고리즘

패턴 문자열의 길이만큼 문자열을 잘라 해쉬화 한 값을 비교한다.

해쉬 충돌 문제 때문에 같은 해쉬를 찾으면 해당 문자열이 같은지 한번 더 비교한다.

    이유는 모르겠지만 기본 알고리즘보다 성능이 좋지 않았다.

```python
def rabin_karp(context, keyword):
    modules=101
    alphabet_size=256
    keyword_len=len(keyword)
    context_len=len(context)
    keyword_hash=0
    context_hash=0
    power=1
    count=0
    for idx in range(keyword_len):
        context_hash=(ord(context[idx])+context_hash*alphabet_size)%modules
        keyword_hash=(ord(keyword[idx])+keyword_hash*alphabet_size)%modules
        if idx==keyword_len-1:
            continue
        power=(power*alphabet_size)%modules

    for idx in range(0,context_len-keyword_len+1):
        if context_hash==keyword_hash and context[idx:idx+keyword_len]==keyword:
            count+=1
        if idx==context_len-keyword_len:
            continue
        context_hash=(
            (context_hash-ord(context[idx])*power)*alphabet_size
            +ord(context[idx+keyword_len])
        )%modules
    return count
```

# KMP 알고리즘

    문자열의 접두사와 접미사가 일치하는 최대 일치 길이를 구해 점프해가며 문자열을 검색하는 알고리즘

* 접두사와 검사하는 글자 수 마다 패턴의 접미사가 일치하는 최대 길이 테이블을 구한다.

* 문자열과 패턴을 비교하던 중, 문자가 같지 않을 경우 마지막 일치 문자까지 되돌아간다.

```python
def kmp(context,keyword):
    keyword_len=len(keyword)
    keyword_max_idx=keyword_len-1
    context_len=len(context)
    kmp_table=[0]*keyword_len
    sub_idx=1
    idx=0
    count=0
    
    while sub_idx<keyword_len:
        if keyword[idx]==keyword[sub_idx]:
            idx+=1
        elif idx>0:
            idx=kmp_table[idx-1]
            continue
        kmp_table[sub_idx]=idx
        sub_idx+=1
    
    idx=0
    sub_idx=0

    while idx<context_len:
        if keyword[sub_idx]==context[idx]:
            if sub_idx==keyword_max_idx:
                count+=1
                sub_idx=0
            sub_idx+=1

        elif sub_idx>0:
            sub_idx=kmp_table[sub_idx-1]
            continue
        idx+=1
    return count
```

```python
import sys
import os
import timeit

def rabin_karp(context, keyword):
    modules=101
    alphabet_size=256
    keyword_len=len(keyword)
    context_len=len(context)
    keyword_hash=0
    context_hash=0
    power=1
    count=0
    for idx in range(keyword_len):
        context_hash=(ord(context[idx])+context_hash*alphabet_size)%modules
        keyword_hash=(ord(keyword[idx])+keyword_hash*alphabet_size)%modules
        if idx==keyword_len-1:
            continue
        power=(power*alphabet_size)%modules

    for idx in range(0,context_len-keyword_len+1):
        if context_hash==keyword_hash and context[idx:idx+keyword_len]==keyword:
            count+=1
        if idx==context_len-keyword_len:
            continue
        context_hash=(
            (context_hash-ord(context[idx])*power)*alphabet_size
            +ord(context[idx+keyword_len])
        )%modules
    return count

def default(context,keyword):
    key_count=0
    keyword_len=len(keyword)
    pos=0
    count=0
    for idx in range(len(context)-keyword_len+1):
        while True:
            if context[idx+key_count]==keyword[key_count]:
                key_count+=1
                if key_count==keyword_len:
                    count+=1
                    key_count=0
                    break
            else:
                key_count=0
                break
    return count

def kmp(context,keyword):
    keyword_len=len(keyword)
    keyword_max_idx=keyword_len-1
    context_len=len(context)
    kmp_table=[0]*keyword_len
    sub_idx=1
    idx=0
    count=0
    
    while sub_idx<keyword_len:
        if keyword[idx]==keyword[sub_idx]:
            idx+=1
        elif idx>0:
            idx=kmp_table[idx-1]
            continue
        kmp_table[sub_idx]=idx
        sub_idx+=1
    
    idx=0
    sub_idx=0

    while idx<context_len:
        if keyword[sub_idx]==context[idx]:
            if sub_idx==keyword_max_idx:
                count+=1
                sub_idx=0
            sub_idx+=1

        elif sub_idx>0:
            sub_idx=kmp_table[sub_idx-1]
            continue
        idx+=1
    return count

def readfile_read(file_dir):
    try:
        with open(file_dir,'r') as file: # 파일 오픈
            return file.read()
    except OSError as e:
        exit("can't open file")

if __name__ == '__main__':
    if len(sys.argv)!=3: # 인자의 수 확인
        exit("argv is incorrect")

    from_word=sys.argv[1]
    in_file=sys.argv[2]
    context=readfile_read(in_file)
    number=10
    print("count : "+str(timeit.timeit('context.count(from_word)',globals=globals(),number=number)))
    print("kmp : "+str(timeit.timeit('kmp(context,from_word)',globals=globals(),number=number)))
    print("rabin karp : "+str(timeit.timeit('rabin_karp(context,from_word)',globals=globals(),number=number)))
    print("default : "+str(timeit.timeit('default(context,from_word)',globals=globals(),number=number)))
```

```
count : 0.0014093999999999982
kmp : 0.4736629
rabin karp : 1.2707847
default : 0.5837794999999999
```

모든 알고리즘의 실행 결과는

1. count함수
3. KMP 알고리즘
2. Default 알고리즘
4. Rabin-Karp 알고리즘
의 순서로 나왔다.