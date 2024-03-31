
input_str = input()
li = list(map(int, input_str.split()))
left,right = 0,len(li)-1

while left<=right:
    li[left],li[right] = li[right],li[left]
    left+=1
    right-=1

print(li)

