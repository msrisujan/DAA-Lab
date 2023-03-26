v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(v):
    u,v=input().split('-')
    graph[u].append(v)
    graph[v].append(u)

visited=[]

def triangle(graph,node,prev):
    global visited

    if node in visited:
        return True
    visited.append(node)

    for i in graph[node]:
        if prev in graph[i]:
            return False
        if not triangle(graph,i,node):
            return False
    
    return True

for v in vertices:
    if not triangle(graph,v,""):
        print("The graph is not triangle free")
        break
else:
    print("The graph is triangle free")

