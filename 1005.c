#include <stdio.h>


int f_fast(int a, int b, int n) {
  int numbers[51] = {0};
  numbers[0] = 1;
  numbers[1] = 1;

  int pre_data_len = 0;
  int circle_data_len = 0;

  for (int i=2;i<51;i++) {
    int value = (a*numbers[i-1] + b*numbers[i-2]) % 7;
    numbers[i] = value;

    for (int j=0;j<i-1;j++) {
      if (numbers[j] == numbers[i-1] &&
          numbers[j+1] == numbers[i] ) {
        pre_data_len = j;
        circle_data_len = i-j-1;
        break;
      }
    }
    if (circle_data_len > 0)
      break;
  }

  if (n <= pre_data_len)
    return numbers[n-1];
  else {
    return numbers[(n-pre_data_len-1) % circle_data_len + pre_data_len];
  }
}


int main() {
  int a, b, n;
  while (1) {
    scanf("%d %d %d", &a, &b, &n);
    if (a == 0)
      break;

    int result = f_fast(a, b, n);
    printf("%d\n", result);
  }
  return 0;
}
