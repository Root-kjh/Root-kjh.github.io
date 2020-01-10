---
layout: default
title: BackTracking
parent: Algorithm
nav_order: 1
---

>조합 알고리즘 문제에서 조건이 만족하는 모든 조합의 수를 살펴보는 알고리즘

* 노드의 유망성을 점검 후, 유망하지 않으면 그 노드의 부모노드로 되돌아간 후 다른 자손노드를 검색한다.

* 스택을 사용하며 스택에 넣기 전에 유망성검사를 실시한다.

참조 : https://idea-sketch.tistory.com/29