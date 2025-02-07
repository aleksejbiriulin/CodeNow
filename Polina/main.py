

n = int(input())
a = list(input())
d = [0 for _ in range(128)]
for i in a:
    d[ord(i)] += 1
ans = ""
center = ""
for i in range(len(d)):
    alpfa = chr(i)
    count = d[i]
    ans += alpfa * (count // 2)
    if count % 2 == 1:
        if center == "":
            center = alpfa
print(ans + center + ans[::-1])

        

