def partion(nums, low, high):
    pivot = nums[high]
    i = low - 1
    for j in range(low, high):
        if nums[j] <= pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]
    nums[i + 1], nums[high] = nums[high], nums[i + 1]
    return i + 1

def quicksort(nums, low, high):
    if low < high:
        pi = partion(nums, low, high)
        quicksort(nums, low, pi - 1)
        quicksort(nums, pi + 1, high)

nums = list(map(int, input().split()))
quicksort(nums, 0, len(nums) - 1)
print(nums)
