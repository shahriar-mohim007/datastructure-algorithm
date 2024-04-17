import heapq
input_str = input()
li = list(map(int, input_str.split()))
k = int(input())
max_heap = []
for num in li:
    heapq.heappush(max_heap, num)
    print(max_heap)
    if len(max_heap) > k:
        heapq.heappop(max_heap)

print(max_heap[0])