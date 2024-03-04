def construct_path(parent, root, dest):
   path = []
   node = dest
   while node != root:
      path.append(node)
      node = parent[node]
   path.append(root)
   path.reverse()
   return path


def bfs_shortest_path(graph, root, dest):
   visited, queue = set(), []
   dist = {root: 0}
   parent = {root: None}
   queue.append(root)
   visited.add(root)
   while queue:
      parent_node = queue.pop(0)
      if parent_node == dest:
         return construct_path(parent, root, dest)
      for child in graph[parent_node]:
         if child not in visited:
            visited.add(child)
            dist[child] = dist[parent_node] + 1
            parent[child] = parent_node
            queue.append(child)
   return -1 



if __name__ == '__main__':
   graph = {} 
   n = int(input("Enter the number of edges in the graph: "))
   for i in range(n):
       nodes  = list(map(int, input().split()))
       if nodes[0] not in graph:
          graph[nodes[0]] = []
       graph[nodes[0]].append(nodes[1])
   root = int(input("Enter the root node: "))
   dest = int(input("Enter the destination node: "))
   shortest_path = bfs_shortest_path(graph, root, dest)
   
   if shortest_path == -1:
      print("No path found from root to destination")
   else:
      print(f"The shortest path from {root} to {dest} is {shortest_path}")