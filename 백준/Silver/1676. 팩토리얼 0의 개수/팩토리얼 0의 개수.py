n = int(input())
sum = 0
while n >= 5:
    sum+=n//5
    n//=5
print(sum)    