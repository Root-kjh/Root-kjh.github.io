---
layout: default
title: 깊이 우선 탐색(DFS)
parent: Algorithm
---

> 로트 노드에서 시작해 다음 분기로 넘어가기 전에 해당 분기를 완벽히 탐색하는 방법

* 모든 노드를 방문 하고자 하는 경우 이 방법을 선택한다.

* 너비 우선 탐색에 비해 조금 더 간단하다.

* 너비 우선 탐색에 비해 느리다.

![DFS의 과정](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/dfs-example.png)

```python
graph = {
    'A': ['B'],
    'B': ['A', 'C', 'H'],
    'C': ['B', 'D', 'G'],
    'D': ['C', 'E'],
    'E': ['D', 'F'],
    'F': ['E'],
    'G': ['D'],
    'H': ['B', 'I', 'J', 'M'],
    'I': ['H'],
    'J': ['H', 'K'],
    'K': ['J', 'L'],
    'L': ['K'],
    'M': ['H']
}

if __name__ == "__main__":
    visit=list()
    stack=list()
    stack.append('A')

    while stack:
        flag=False
        node=stack.pop()
        if node not in visit:
            visit.append(node)
            for i in graph[node]:
                stack.extend(list(reversed(graph[node])))
```