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

bridged=[]

def componets(graph):
    global visited
    count=0
    for i in graph:
        if i not in visited:
            count+=1
            bfs(graph,i)
    return count

com=componets(graph)

def remove_ele(graph,v1,v2):
    temp={key : value[:] for key,value in graph.items()}
    temp[v1].remove(v2)
    temp[v2].remove(v1)
    return temp

for i in graph:
    for j in graph[i]:
        if([j,i] not in bridged):
            visited=[]
            temp=remove_ele(graph,i,j)
            c=componets(temp)
            if c>com:
                bridged.append([i,j])

if len(bridged)==0:
    print("There are no bridged edges")

else:   
    print("The bridged edges are :",*bridged)
