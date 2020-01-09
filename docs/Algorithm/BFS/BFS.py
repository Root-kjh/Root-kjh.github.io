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