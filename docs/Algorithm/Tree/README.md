# 트리(Tree)
>트리는 1개 이상의 노드를 갖는 집합으로 노드들은 다음 조건을 만족한다.

    1. 트리는 하나의 루트 노드를 갖는다.

    2. 루트 노드는 0개 이상의 자식 노드를 갖고 있다.

    3. 그 자식 노드 또한 0개 이상의 자식 노드를 갖고 있고, 이는 반복적으로 정의된다.
    

## 트리의 특징

* 트리는 계층 모델 이다.

* 트리는 DAG(Directed Acyclic Graphs, 방향성이 있는 비순환 그래프)의 한 종류이다.

* loop나 circuit이 없다.

* 노드가 N개인 트리는 항상 N-1개의 간선(edge)을 가진다.

* 간선은 항상 (정점의 개수 - 1) 만큼을 가진다.

* 루트에서 어떤 노드로 가는 경로는 유일하다.

* 임의의 두 노드 간의 경로도 유일하다. 즉, 두 개의 정점 사이에 반드시 1개의 경로만을 가진다.

* 한 개의 루트 노드만이 존재하며 모든 자식 노드는 한 개의 부모 노드만을 가진다.

* 부모-자식 관계이므로 흐름은 top-bottom/bottom-top으로 이루어진다.

* 순회는 Pre-order/In-order/Post-order로 이루어진다. 이 3가지 모두 DFS/BFS 안에 있다.

## 트리의 종류

1. 해시 트리

    Hash Tree

2. B 트리

    B Tree

    B+Tree

3. 이진 탐색 트리

    [Binary Tree](/Algorithm/Tree/Binary_Tree)

    AA Tree

    AVL Tree

    RB-Tree

    Balanced Tree

    Splay Tree

4. R트리

    R Tree

    R+Tree