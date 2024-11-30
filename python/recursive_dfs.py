
def dfs_recursive(graph, node, visited):
    if node not in visited:
        visited.add(node)
        print(node)
        for neighbor in graph[node]:
            dfs_recursive(graph, neighbor, visited)

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

visited = set()
dfs_recursive(graph, 'A', visited)
