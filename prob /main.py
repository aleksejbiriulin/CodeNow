a = list(map(int, input().split()))
n = len(a)
dp = [0 for _ in range(n + 1) for _ in range(n)]
# dp[i][j] ответ на задачу для подотрекза массива который начинается в j а имеет длину i
for len_ in range(1, n + 1):
  for i in range(n - len_ + 1):
    if len_ <= 2:
      dp[len_][i] = sum(a[i:i + len_])
    else:
      for x in range(i + 1, i + len_ - 1):
        dp[len_][i] = max((dp[x - i + 1][i] + dp[len_ - x + i - 2][x + 1]) * a[x], dp[len_][i])
print(dp[-1][0])