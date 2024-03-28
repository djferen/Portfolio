import heapq

class Graph:
  def __init__(self, vertices):
    self.V = vertices
    self.graph = [[] for _ in range(self.V)]

  def add_edge(self, u, v, weight):
    self.graph[u].append((v, weight))  # (neighbor, weight)

  # Function to implement Dijkstra's algorithm
  def dijkstra(self, src):
    dist = [float('inf')] * self.V  # Initialize distances as infinite
    dist[src] = 0                   # Distance to source is 0
    pq = []                         # Priority queue to store vertices
    heapq.heappush(pq, (0, src))     # Push source vertex with distance 0

    while pq:
      u, distance = heapq.heappop(pq)

      # If vertex is already visited (with a better or equal distance), continue
      if dist[u] < distance:
        continue

      # Relax adjacent vertices
      for neighbor, weight in self.graph[u]:
        new_dist = distance + weight
        if new_dist < dist[neighbor]:
          dist[neighbor] = new_dist
          heapq.heappush(pq, (new_dist, neighbor))

    return dist

# Example usage
graph = Graph(5)
graph.add_edge(0, 1, 4)
graph.add_edge(0, 2, 8)
graph.add_edge(1, 2, 2)
graph.add_edge(1, 3, 6)
graph.add_edge(2, 3, 3)
graph.add_edge(2, 4, 9)
graph.add_edge(3, 4, 7)
