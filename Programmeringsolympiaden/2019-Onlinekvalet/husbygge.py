#GER 60.85 sekunder
import math
t = int(input())
wow = input()
wow = wow.split()
n = int(wow[0])
m = int(wow[1])
k = int(wow[2])

if t == 4 or t == 6 or t == 9:

  in1 = []
  houses = []
  
  for i in range(0, n):
    in1.append([])
    row = input()
    row = row.split()
    for j in range(0, m):
      in1[i].append(int(row[j]))
  
  
  
  h = math.floor(math.sqrt(m * n / k))
  count = 0
  max = [0, 0, 0]
  x = 0
  y = 0
  while y +h<= n:
    if y + 2* h > n:
      b = n
    else:
      b = y +h
    x = 0
    if count >= k:
      break
     
    while x+h <= m:
      if x +2*h > m:
        a = m 
      else:
        a = x+ h
      for i in range(y, b):
        for j in range(x, a):
          if in1[i][j] > max[2]:
            max = [i, j, in1[i][j]]
      print(max[0]+1, max[1] +1)
      max =[0, 0, 0]
      count += 1
      x += h
    y +=h
    
    
else:
  in1 = []
  houses = []
  closest = []
  for i in range(0, n):
    in1.append([])
  
    closest.append([])
    row = input()
    row = row.split()
    for j in range(0, m):
      in1[i].append(int(row[j]))
      closest[i].append([0, 0, int(row[j])])
  
  max = [0, 0, 0]
  
  for i in range(0, n):
    for j in range(0, m):
      if closest[i][j][2] > max[2]:
        max = [i, j, closest[i][j][2]]
  
  houses.append([max[0], max[1]])
  for i in range(0, n):
    for j in range(0, m):
  
      closest[i][j] = [
        max[0], max[1], (abs(i - max[0]) + abs(j - max[1])) * in1[i][j]]
  
  for a in range(0, k - 1):
    max = [0, 0, 0]
    for i in range(0, n):
      for j in range(0, m):
        if closest[i][j][2] >= max[2]:
          max = [i, j, closest[i][j][2]]
  
    houses.append([max[0], max[1]])
    for i in range(0, n):
      for j in range(0, m):
        if abs(i - max[0]) + abs(j - max[1]) < abs(i - closest[i][j][0]) + abs(
            j - closest[i][j][1]):
          closest[i][j] = [
            max[0], max[1], (abs(i - max[0]) + abs(j - max[1]))**2 * in1[i][j]]
  
  for i in range(0, len(houses)):
    print(1 + houses[i][0], 1 + houses[i][1])
        
        
      
