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