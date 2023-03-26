
import sys


class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def printSolution(self, dist):
		print("Vertex \tDistance from Source")
		for node in range(self.V):
			print(node, "\t", dist[node])

	
	def minDistance(self, dist, sptSet):

		min = sys.maxsize
		for u in range(self.V):
			if dist[u] < min and sptSet[u] == False:
				min = dist[u]
				min_index = u

		return min_index

	
	def dijkstra(self, src):

		dist = [sys.maxsize] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for cout in range(self.V):
			x = self.minDistance(dist, sptSet)

			sptSet[x] = True
			for y in range(self.V):
				if self.graph[x][y] > 0 and sptSet[y] == False and \
						dist[y] > dist[x] + self.graph[x][y]:
					dist[y] = dist[x] + self.graph[x][y]

		self.printSolution(dist)

if __name__ == "__main__":
    
    v = int(input("enter no of vertices :"))
    g = Graph(v)
    g.graph =[]
    e=int(input("enter no of edges :"))
    print("Enter edges and weights")
    for i in range(e):
        v1=int(input())
        v2=int(input())
        w=int(input())
        g.graph.append([v1,v2,w])
    s=int(input("Enter source :"))
    g.dijkstra(s)