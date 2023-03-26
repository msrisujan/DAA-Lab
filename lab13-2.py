visited1=set()
visited2=set()
visited3=set()
def dfs_stack(graph, start, stack):
    global visited1
    visited1.add(start)

    for i in graph[start]:
        if i not in visited1:
            dfs_stack(graph,i,stack)
    stack.append(start)
    return stack

def dfs(graph, start,visited3):
    global visited2
    visited2.add(start)
    print(start,end=" ")
    for next in graph[start]:
        if next not in visited2:
            dfs(graph, next, visited3)
    return visited3

def rev_graph(graph,vertices,stack):
    graph_t={n : [] for n in vertices}
    for i in stack:
        for j in graph[i]:
            if j in stack:
                graph_t[j].append(i)
    return graph_t


v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)

print("all maximal strongly connected components in G are :")
for v in vertices:
    s=[]
    s=dfs_stack(graph,v,s)
    g2={}
    g2=rev_graph(graph,vertices,s)
    s.reverse()
    for i in s:
        if i not in visited2:
            dfs(g2,i,visited3)
            print("")
