# def shortest_path(parent,root,dest):
#     path = []
#     node = dest
#     while node!=root:
#         path.append(node)
#         node = parent[node]
    
#     path.append(root)
#     path.reverse()
#     return path
    

# def bfs_shortest_path(graph,root,dest):
#     visited,queue = set(),[]
#     dist = {root:0}
#     parent={root:None}
#     queue.append(root)
#     visited.add(root)
#     while queue:
#         parent_node = queue.pop(0)
#         if parent_node==dest:
#            return shortest_path(parent,root,dest)
#         for child in graph[parent_node]:
#             if child not in visited:
#                 visited.add(child)
#                 queue.append(child)
#                 dist[child] =  dist[parent_node]+1
#                 parent[child]=parent_node
        


    
# def main():
#     graph = [[]for _ in range(100)]
#     edge = int(input("Enter the number of Edge"))

#     for _ in range(edge):
#         x,y = map(int,input().split())
#         graph[x].append(y)
#         graph[y].append(x)
    
#     root = int(input("Enter the root node: "))
#     dest = int(input("Enter the destination node: "))

#     shortest_path = bfs_shortest_path(graph,root, dest)
#     print(shortest_path)

# visited = [False]*100
# graph = [[]for _ in range(100)]
# def dfs(s):
#     visited[s] = True
#     for i in graph[s]:
#         if not visited[i]:
#            dfs(i)
# def main():
   
#    edge = int(input("Enter the number of edges in the graph: "))
#    node = int(input("Enter the number of nodes in the graph: "))
#    for _ in range(edge):
#        x,y = map(int, input().split())
       
#        graph[x].append(y)
          
#    connectedComponents = 0
#    for i in range(1,node+1):
#         if not visited[i]:
#             dfs(i)
#             connectedComponents += 1
       
#    print("Number of connected components:", connectedComponents)
#    return 0
# def merge(nums,l,m,r):
#     n1 = m-l+1
#     n2 = r-m
#     l1 = [0] * n1
#     r1 = [0] * n2
#     for i in range(n1):
#         l1[i] = nums[i+l]
#     for j in range(n2):
#         r1[j] = nums[m+1+j]
    
#     i,j,k=0,0,l

#     while i<n1 and j<n2:
#         if l1[i]>r1[j]:
#            nums[k]=l1[i]
#            i+=1
#            k+=1
#         else:
#             nums[k] = r1[j]
#             j+=1
#             k+=1
    
#     while i<n1:
#         nums[k]=l1[i]
#         i+=1
#         k+=1
#     while j<n2:
#         nums[k] = r1[j]
#         j+=1
#         k+=1



# def mergesort(nums,l,r):
#     if l<r:
#         m = l+(r-l)//2       
#         mergesort(nums,l,m)
#         mergesort(nums,m+1,r)
#         merge(nums,l,m,r)


# nums = list(map(int,input().split()))
# size = len(nums)
# mergesort(nums,0,size-1)
# print(nums)
def anagram(word1, word2):
     char_count1 = {}
     char_count2 = {}

     for char in word1:
        char_count1[char] = char_count1.get(char, 0) + 1

     for char in word2:
        char_count2[char] = char_count2.get(char, 0) + 1

     for char, count in char_count1.items():
        if char_count2.get(char) != count:
            return False
     
     return True

   

s1 = input("Enter the first string")
s2 = input("Enter the second string")
if(anagram(s1,s2)):
   print("anagram")
else:
    print("Not anagram")


def is_prime(number):
    if number <= 1:
        return False
    sqrt_number = int(number ** 0.5) + 1
    for i in range(2, sqrt_number):
        if number % i == 0:
            return False
    return True

a, b = map(int, input("Enter two numbers: ").split())

for i in range(a, b + 1):
    if is_prime(i):
        print(f'{i} is a prime Number')
    else:
        print(f'{i} is not a prime Number')

# if __name__ == '__main__':
#    main()

   