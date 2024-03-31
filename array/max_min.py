input_str = input()
li = list(map(int, input_str.split()))
max_int = float('inf')
min_int = -float('inf')
for value in li:
    if value>min_int:
        min_int =  value
    if value<max_int:
        max_int = value

print(min_int,max_int)


