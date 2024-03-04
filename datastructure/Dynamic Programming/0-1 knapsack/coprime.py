def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def co_prime(num1,num2):

    if num1>num2:
        ans = gcd(num1,num2)
    else:
        ans = gcd(num2,num1)
    
    return ans==1

    
num1=int(input("Enter first Number"))
num2=int(input("Enter second Number"))
if(co_prime(num1,num2)):
    print("co-prime")
else:
    print("Notcoprime")


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
