---
layout: default
title: Crack Crack Crack it
parent: Wargame.kr
nav_order: 18
---

# Crack Crack Crack it

htpasswd 의 암호화된 Passwd를 찾는 문제다.

암호는 md5 Hash화 되어있고, Brute Force 기법을 활용해 풀면 된다.

```python
import itertools

chrs= 'abcdefghijklmnopqrstuvwxyz0123456789'
min_length, max_length = 2, 5

for n in range(min_length, max_length+1):
    for xs in itertools.product(chrs, repeat=n):
        print 'G4HeulB'+''.join(xs)
```