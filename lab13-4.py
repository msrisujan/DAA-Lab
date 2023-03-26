import collections
v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)
    graph[v].append(u)

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

start=bfs(graph,vertices[0])

list=[start[-1]]
visited=set()
def end_l(list,node):
    for i in list:
        if i[-1]==node:
            return list.index(i)

def longest_path(graph, start):
    global list
    global visited
    visited.add(start)
    for i in graph[start]:
        if i not in visited:
            list.append(list[end_l(list,start)]+'-'+i)
            longest_path(graph,i)

longest_path(graph,start[-1])
print("Longest path is :")
print(max(list,key=len))