#include <stdio.h>

void get_max_sum(int *numbers, int *numbers_max_sum, int num,
                 int *max_sum,
                 int *idx_begin,
                 int *idx_end
                 ) {
  *max_sum = numbers[0];
  *idx_begin = 0;
  *idx_end = 0;

  int sum = 0;
  for (int k=0; k < num; k++) {
    sum += numbers[k];
    numbers_max_sum[k] = sum;

    if (sum > *max_sum) {
      *max_sum = sum;
      *idx_end = k;
    }
  }

  numbers_max_sum[0] = *max_sum;
  int temp_max_sum = *max_sum;

  for (int k=1; k < (*idx_end)+1; k++) {
    temp_max_sum -= numbers[k-1];
    numbers_max_sum[k] = temp_max_sum;
    if (numbers_max_sum[k] > *max_sum) {
      *max_sum = numbers_max_sum[k];
      *idx_begin = k;
    }
  }

  if (num-(*idx_end)-1 == 0)
    return;

  int max_sum_next = 0;
  int idx_begin_next = 0;
  int idx_end_next = 0;
  get_max_sum(&numbers[(*idx_end)+1], &numbers_max_sum[(*idx_end)+1], num-(*idx_end)-1,
              &max_sum_next,
              &idx_begin_next,
              &idx_end_next
              );
  if (max_sum_next > *max_sum) {
    *max_sum = max_sum_next;
    *idx_begin = idx_begin_next + (*idx_end) + 1;
    *idx_end = idx_end_next + (*idx_end) + 1;
  }
}


int main() {
  int case_n;
  int numbers[100000];
  int numbers_max_sum[100000] = {0};
  scanf("%d", &case_n);
  for (int i=0; i < case_n; i++) {
    int num;
    scanf("%d", &num);
    for (int j=0; j < num; j++)
      scanf("%d", &numbers[j]);

    printf("Case %d:\n", i+1);

    int max_sum = 0;
    int idx_begin = 0;
    int idx_end = 0;
    get_max_sum(numbers, numbers_max_sum, num,
                &max_sum,
                &idx_begin,
                &idx_end
                );

    printf("%d %d %d\n", max_sum, idx_begin+1, idx_end+1);
    if (i < case_n-1)
      printf("\n");
  }
  return 0;
}
