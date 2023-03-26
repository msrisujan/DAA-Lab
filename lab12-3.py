import collections

def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)
    bfs_list=[]

    while queue:

        vertex = queue.popleft()
        bfs_list.append(vertex)

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)
    return bfs_list


if __name__ == '__main__':
    graph=dict()
    vertices=[]
    v=int(input("enter no of vertices : "))
    for i in range(v):
        vertex=input(f"enter the vertex-{i+1} :")
        vertices.append(vertex)
        con_vertices=input(f"enter the connected vertices to vertex-{i+1} :")
        con_vertices=con_vertices.split(" ")
        graph[vertex]=con_vertices
    bfs_list=bfs(graph,vertices[0])
    if len(bfs_list)==v:
        print("This is connected graph")
    else:
        print("this is not connected graph")
