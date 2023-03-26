v = int(input("enter no of vertices :"))
vertices = input("Enter all vertices :").split()
graph={n : [] for n in vertices}

e=int(input("Enter number of edges :"))
print("Enter connected edges :")
for i in range(e):
    u,v=input().split('-')
    graph[u].append(v)

list=[]
def end_l(list,node):
    list.reverse()
    for i in list:
        if i[-1]==node:
            return list.index(i)

def longest_path(graph, start):
    global list
    for i in graph[start]:
            list.append(list[end_l(list,start)]+'-'+i)
            longest_path(graph,i)

for i in graph:
    list.append(i)
    longest_path(graph,i)
print(list)
print("Longest path is :")
print(max(list,key=len))