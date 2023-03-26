def bipartite(vertices,graph):
    colour=[-1]*(vertices)
    q=[]

    for i in range(vertices):
        if(colour[i]!=-1):
            q.append([i,0])
            colour[i]=0

            while(len(q)!=0):
                p = q[0]
                q.pop(0)
                v=p[0]
                c=p[1]

                for j in graph[v]:
                    if(colour[j]==c):
                        return False
                    if (colour[j] == -1):
                       
                        if c == 1:
                            colour[j] = 0
                        else:
                            colour[j] = 1
                        q.append([j, colour[j]])
    return True



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
    if(bipartite(v,graph)):
        print("it is bipartite graph")
    else:
        print("it is not bipartite graph")
    