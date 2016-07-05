import random

def f(a, b, n):
  if n <= 2:
    return 1
  else:
    return (a * f(a, b, n-1) + b * f(a, b, n-2)) % 7



def f_fast(a, b, n):
  numbers = range(50)
  numbers[0] = 1
  numbers[1] = 1

  #print("1, 1, ")

  pre_data_len = 0
  circle_data_len = 0

  for i in range(2, 51):
    value = (a*numbers[i-1] + b*numbers[i-2]) % 7
    numbers[i] = value

    #print("%d, " % value)

    for j in range(i-1):
      if (numbers[j] == numbers[i-1] and
          numbers[j+1] == numbers[i] ):
        pre_data_len = j
        circle_data_len = i-j-1
        break

    if (circle_data_len > 0):
      break

  # for number in numbers:
  #   print "%d, " % number,
  # print
  # print pre_data_len, circle_data_len

  if (n <= pre_data_len):
    return numbers[n-1]
  else:
    return numbers[(n-pre_data_len-1) % circle_data_len + pre_data_len]



def main():

    for i in range(10):
        a = random.randint(1, 1000)
        b = random.randint(1, 1000)
        n = random.randint(1, 10)

        # a, b, n = 451, 966, 7
        print a, b, n
        result = f_fast(a, b, n)
        print("\n%d" % result)

        result = f(a, b, n)
        print("%d\n" % result)


main()
