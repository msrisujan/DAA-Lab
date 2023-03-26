v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)
    graph[v].append(u)

visited=set()

def check_odd(graph,vertex,cycle : str):
    global visited

    if vertex in visited:
        if vertex in cycle and ((len(cycle)-cycle.index(vertex))%2==1):
            return True
        else :
            return False
    
    visited.add(vertex)

    for i in graph[vertex]:
        if len(cycle)==0 or i!=cycle[len(cycle)-1]:
            if check_odd(graph,i,cycle+vertex):
                return True
    return False

for i in vertices:
    if check_odd(graph,i,""):
        print("This graph has odd cycle")
        break
else:
    print("This graph is odd cycle free")