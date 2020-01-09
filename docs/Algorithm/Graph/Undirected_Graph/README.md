# Undirected Graph
---

### Operations

* int V()
> * 정점의 개수를 리턴

* int E()
> * 간선의 개수를 리턴 

* void addEdge(int v,int w)
> * 정점간 간선 추가

* bool contains(int v, int w)
> *  그래프에 v-w 간선이 있으면 True, 그렇지 않으면 False

* 
> * LFirst 또는 LNext 함수의 마지막 반환 데이터 삭제
> * 삭제된 데이터 반환
> * 마지막 반환 데이터르 작제하므로 연이은 반복 호춣 X

* int LCount(List * plist);
> * 리스트의 저장되어 있는 데이터의 수 반환