INF = float('inf')
nv = int(input("Enter the number of vertices : "))
parent = [i for i in range(nv)]
print(f"Vertices are from 0 to {nv-1}")
graph = [[INF for i in range(nv)] for j in range(nv)]
ne = int(input("Enter the number of edges : "))
print("Enter the edges in 'vertex-1 vertex-2 weight' manner")
for i in range(ne):
    v1,v2,w = map(int,input(f'Enter edge-{i+1} : ').split())
    graph[v1][v2],graph[v2][v1] = w,w
def union(i,j):
    a = find(i)
    b = find(j)
    parent[a] = b
def find(i):
    while parent[i] != i:
        i = parent[i]
    return i
def kruskal(graph,nv):
    krusk = []
    min_cost = 0
    edge_count = 0
    while(edge_count < nv-1):
        min,a,b = INF,-1,-1
        for i in range(nv):
            for j in range(nv):
                if find(i) != find(j) and graph[i][j] < min :
                    min = graph[i][j]
                    a = i
                    b = j
        union(a,b)
        min_cost += min
        edge_count += 1
        krusk.append([a,b])
    print("The weight of the minimum spanning tree is :",min_cost)
    return krusk
krusk = kruskal(graph,nv)
print("The edges in minimum spanning tree are :")
print(krusk)