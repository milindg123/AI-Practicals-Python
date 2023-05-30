def dfs(visited,graph,node):
    if node not in visited:
        print(node,end=" ")
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited,graph,neighbour)

def bfs(visited,graph,node, q):
    visited.add(node)
    q.append(node)
    while q:
        s= q.pop(0)
        print(s, end=" ")
        for neighbour in graph[s]:
            if neighbour not in visited:
                visited.add(neighbour)
                q.append(neighbour)

def main():
    visited1 = set()
    visited2 = set()
    queue = []
    n = int(input("Enter number of nodes: "))
    graph = dict()

    for i in range(1,n+1):
        edges = 