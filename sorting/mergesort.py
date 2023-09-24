def merge(nums,l,m,r):
    n1 = m-l+1
    n2 = r-m
    l1 = [0]*n1
    r1 = [0]*n2
    
    for i in range(n1):
        l1[i] = nums[l+i]
    
    for j in range(n2):
        r1[j] = nums[m+1+j]

    i=0
    j=0
    k=l

    while i<n1 and j<n2:
        if l1[i]<r1[j]:
            nums[k] = l1[i]
            i+=1
            k+=1
        else:
            nums[k] = r1[j]
            j+=1
            k+=1

    while i<n1:
        nums[k] = l1[i]
        i+=1
        k+=1

    while j<n2:
        nums[k] = r1[j]
        j+=1
        k+=1



def mergesort(nums,l,r):
    if l<r:
        m = l+(r-l)//2
        mergesort(nums,l,m)
        mergesort(nums,m+1,r)
        merge(nums,l,m,r)
        
nums = list(map(int,input().split()))
size = len(nums)
mergesort(nums,0,size-1)
print(nums)