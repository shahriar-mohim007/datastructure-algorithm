graph = [[] for _ in range(100)]
visited = [False]*6


def dfs(s):
    
    visited[s] = True
    for i in graph[s]:
        if not visited[i]:
         dfs(i)


def main():
   global graph,visited
   edge = int(input("Enter the number of edges in the graph: "))
   node = int(input("Enter the number of nodes in the graph: "))
   for _ in range(edge):
       x,y = map(int, input().split())
       
       graph[x].append(y)
       graph[y].append(x)
          
   connectedComponents = 0
   for i in range(1,node+1):
        if not visited[i]:
            dfs(i)
            connectedComponents += 1
       
   print("Number of connected components:", connectedComponents)
   return 0

if __name__ == '__main__':
   main()    