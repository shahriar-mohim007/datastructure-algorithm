def partition(nums, low, high):
    pivot = nums[high]
    i = low - 1

    for j in range(low, high):
        if nums[j] <= pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]

    nums[i + 1], nums[high] = nums[high], nums[i + 1]
    return i + 1

def findKthLargest(nums, k):
    low = 0
    high = len(nums) - 1

    while low <= high:
        
        pivotPos = partition(nums, low, high)
        if pivotPos == len(nums) - k:
            return nums[pivotPos]
        elif pivotPos > len(nums) - k:
            high = pivotPos - 1
        else:
            low = pivotPos + 1

    return -1


nums = list(map(int, input().split()))
k = int(input())
print(findKthLargest(nums, k))
