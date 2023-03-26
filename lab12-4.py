import collections
from copy import deepcopy

visited=[]

def bfs(graph, root):
    global visited

    queue = collections.deque([root])
    visited.append(root)
    bfs_list=[]

    while queue:

        vertex = queue.popleft()
        bfs_list.append(vertex)

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
    return bfs_list

v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)
    graph[v].append(u)

articulate=[]

def componets(graph):
    global visited
    count=0
    for i in graph:
        if i not in visited:
            count+=1
            bfs(graph,i)
    return count

com=componets(graph)

def remove_ele(graph,vertex):
    temp={key : value[:] for key,value in graph.items()}
    for i in temp:
        if vertex in temp[i]:
            temp[i].remove(vertex)
    temp.pop(vertex)
    return temp

for i in vertices:
    visited=[]
    temp=remove_ele(graph,i)
    c=componets(temp)
    if c>com:
        articulate.append(i)
    
print("The articulate points are :",*articulate)

