nums = list(map(int, input().split()))
ans = []

for num in nums:
    if num == 0:
        ans.append(num)

for num in nums:
    if num == 1:
        ans.append(num)

for num in nums:
    if num == 2:
        ans.append(num)

print(ans)

counter = [0, 0, 0]
for i in range(len(nums)):
    counter[nums[i]] += 1

i=0
for index, f in enumerate(counter):
    for _ in range(f):
        nums[i] = index
        i += 1


print(nums)



left = 0
mid = 0
right = len(nums)-1
while mid<=right:
    if nums[mid] == 0:
        nums[left],nums[mid] = nums[mid],nums[left]
        mid+=1
        left+=1
    elif nums[mid] ==1:
        mid+=1
    elif nums[mid] == 2:
        nums[mid],nums[right] = nums[right],nums[mid]
        right-=1




print(nums)

#2 0 2 0 1
#1 0 2 1 0 2