v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)

visited=set()

def check_cycle(graph,vertex,cycle : str):
    global visited

    # if vertex in visited:
    if vertex in cycle:
        return True
    
    visited.add(vertex)

    for i in graph[vertex]:
        if len(cycle)==0 or i!=cycle[len(cycle)-1]:
            if check_cycle(graph,i,cycle+vertex):
                return True
    return False

for i in vertices:
    if i not in visited:
        if check_cycle(graph,i,""):
            print("This graph is not DAG")
            break
else:
    print("This graph is DAG")