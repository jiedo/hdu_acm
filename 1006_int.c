#include <stdio.h>
#include <stdlib.h>


int degree_each_second[43200];

void init() {
  for (int t=0;t<43200;t++) {
    /* d*120 */
    int hour_minute_a = abs((t%3600)*12 - t);
    int hour_minute_b = 43200 - hour_minute_a;

    int hour_second_a = abs((t%60)*720 - t);
    int hour_second_b = 43200 - hour_second_a;

    int second_minute_a = abs((t%60)*720 - (t%3600)*12);
    int second_minute_b = 43200 - second_minute_a;

    int min_d = hour_minute_a;
    if (hour_minute_b < min_d)
      min_d = hour_minute_b;

    if (hour_second_a < min_d)
      min_d = hour_second_a;
    if (hour_second_b < min_d)
      min_d = hour_second_b;

    if (second_minute_a < min_d)
      min_d = second_minute_a;
    if (second_minute_b < min_d)
      min_d = second_minute_b;

    degree_each_second[t] = min_d*10000;
  }
}


int count_percent(int d) {
  int n = 0;
  for (int i=0;i<43200;i++) {
    if (degree_each_second[i] >= d)
      n++;
  }
  return n;
}


int main() {
  float d;
  init();
  while (1) {
    scanf("%f", &d);
    if (d < 0)
      break;

    int result = count_percent((int)(d*1200000));
    printf("%.3f\n", result/432.0);
  }
  return 0;
}
