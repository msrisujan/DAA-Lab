INF=float("inf")
t=int(input("Enter no of vertices"))
graph=[[INF for i in range(t)]for j in range(t)]
e=int(input("Enter no of edges"))
print("Enter edges and weight")
for i in range(e):
    u,v,w=map(int,input().split())
    graph[u][v]=w
    graph[v][u]=w   
dist=[row[:] for row in graph]
for i in range(t):
    dist[i][i]=0
for i in range(t):
    for j in range(t):
        for k in range(t):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
for i in range(t):
    print(*dist[i])