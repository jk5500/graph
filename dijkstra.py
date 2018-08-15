from collections import defaultdict
import heapq 


class Graph:

	def __init__(self, vertex):
		self.vertex = vertex
		self.graph = defaultdict(list)

	def add_graph(self, u, v, w):
		self.graph[u].append((v, w))
		self.graph[v].append((u, w))

	def print_graph(self):
		print(self.graph)

	def dijk(self, start, end):
		priority_queue, seen = [(0, start, ())], set()
		while priority_queue:
			(cost, v1, path) = heapq.heappop(priority_queue)
			if v1 not in seen:
				seen.add(v1)
				path = (v1, path)
				if end == v1:
					return (cost, path)
				for v2, c in self.graph[v1]:
					if v2 not in seen:
						heapq.heappush(priority_queue, (cost+c, v2, path))
	def print_path(self):
		for v in range(self.vertex):
			print(self.dijk(0, v))


g = Graph(9)
g.add_graph(0, 1, 4)
g.add_graph(0, 7, 8)
g.add_graph(1, 2, 8)
g.add_graph(1, 7, 11)
g.add_graph(2, 3, 7)
g.add_graph(2, 8, 2)
g.add_graph(2, 5, 4)
g.add_graph(3, 4, 9)
g.add_graph(3, 5, 14)
g.add_graph(4, 5, 10)
g.add_graph(5, 6, 2)
g.add_graph(6, 7, 1)
g.add_graph(6, 8, 6)
g.add_graph(7, 8, 7)



g.print_graph()
g.print_path()
