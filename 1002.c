#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sum_a_b(char *a, char *b) {
  int int_64_20 = 1000000000;

  int addition = 0;
  int int_64_a[112] = {0};
  int int_64_b[112] = {0};

  int len_a = strlen(a);
  int len_b = strlen(b);

  int idx_a = 0;
  while(len_a > 0) {
    a[len_a] = 0;

    len_a -= 9;
    if (len_a < 0)
      len_a = 0;

    int_64_a[idx_a++] = atoi(&a[len_a]);
  }

  int idx_b = 0;
  while(len_b > 0) {
    b[len_b] = 0;

    len_b -= 9;
    if (len_b < 0)
      len_b = 0;

    int_64_b[idx_b++] = atoi(&b[len_b]);
  }

  int len_sum = idx_b;
  if (idx_a > idx_b)
    len_sum = idx_a;

  for (int i=0; i < len_sum; i++) {
    if (int_64_a[i] >= int_64_20 - int_64_b[i] - addition) {
      int_64_a[i] -= int_64_20 - int_64_b[i] - addition;
      addition = 1;
    } else {
      int_64_a[i] += int_64_b[i] + addition;
      addition = 0;
    }
  }
  if (addition == 1) {
    int_64_a[len_sum++] = 1;
  }

  for (int i=0; i < len_sum; i++) {
    if (i == 0)
      printf("%d", int_64_a[len_sum-i-1]);
    else
      printf("%09d", int_64_a[len_sum-i-1]);
  }
  printf("\n");
}

int main() {
  int n;
  char a[1001];
  char b[1001];
  scanf("%d", &n);
  for (int i=0; i < n; i++) {
    scanf("%s %s", a, b);
    printf("Case %d:\n", i+1);
    printf("%s + %s = ", a, b);
    sum_a_b(a, b);
    if (i < n-1)
      printf("\n");
  }
  return 0;
}
