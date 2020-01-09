---
layout: default
title: 너비 우선 탐색(BFS)
parent: Algorithm
---

>루트 노드에서 시작해 인접한 노드를 먼저 탐색하는 방법

* 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법

* 두 노드 사이의 최단 경로 혹은 임의의 경로를 찾고 싶을 때 이 방법을 선택한다.

* 직관적이지 않다.

* 재귀적으로 동적하지 않는다.

![BFS의 과정](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/bfs-example.png)

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
    queue=list()
    queue.append('A')

    while queue:
        node=queue.pop(0)
        if node not in visit:
            print(node)
            visit.append(node)
            for i in graph[node]:
                queue.extend(graph[node])
```