#include <stdio.h>
#include <stdlib.h>


double count_percent(float d) {
  double minute_to_hour[22];
  double second_to_hour[1438];
  double second_to_minute[1416];

  double cycle_minute_to_hour = 180.0 * 120 / 11;
  double cycle_second_to_hour = 180.0 * 120 / 719;
  double cycle_second_to_minute = 180.0 * 10 / 59;

  double start_minute_to_hour = d * 120 / 11;
  double start_second_to_hour = d * 120 / 719;
  double start_second_to_minute = d * 10 / 59;

  for (int i=0; i<11; i++) {
    minute_to_hour[2*i] = start_minute_to_hour + i*cycle_minute_to_hour*2;
    minute_to_hour[2*i+1] = cycle_minute_to_hour*2 - start_minute_to_hour + i*cycle_minute_to_hour*2;
  }

  for (int i=0; i<719; i++) {
    second_to_hour[2*i] = start_second_to_hour + i*cycle_second_to_hour*2;
    second_to_hour[2*i+1] = cycle_second_to_hour*2 - start_second_to_hour + i*cycle_second_to_hour*2;
  }

  for (int i=0; i<708; i++) {
    second_to_minute[2*i] = start_second_to_minute + i*cycle_second_to_minute*2;
    second_to_minute[2*i+1] = cycle_second_to_minute*2 - start_second_to_minute + i*cycle_second_to_minute*2;
  }

  int i_mh = 0;
  int i_sh = 0;
  int i_sm = 0;

  int is_on_mh = 0;
  int is_on_sh = 0;
  int is_on_sm = 0;

  int is_on = 0;

  double last_start_x = 0;
  double total_length = 0;
  while (1) {
    int min_hand = 0;
    double min_x = second_to_hour[i_sh];
    if (minute_to_hour[i_mh] < min_x) {
      min_x = minute_to_hour[i_mh];
      min_hand = 1;
    }
    if (second_to_minute[i_sm] < min_x) {
      min_x = second_to_minute[i_sm];
      min_hand = 2;
    }

    switch (min_hand) {
    case 0:
      if (i_sh++ % 2)
        is_on_sh = 0;
      else
        is_on_sh = 1;
      break;

    case 1:
      if (i_mh++ % 2)
        is_on_mh = 0;
      else
        is_on_mh = 1;

      break;

    case 2:
      if (i_sm++ % 2)
        is_on_sm = 0;
      else
        is_on_sm = 1;

      break;
    }

    if (is_on_sh && is_on_mh && is_on_sm) {
      is_on = 1;
      last_start_x = min_x;
    } else {
      if (is_on) {
        total_length += (min_x - last_start_x);
      }
      is_on = 0;

      if (i_mh >= 22 || i_sh >= 1438 || i_sm >= 1416)
        break;
    }
  }

  return total_length;
}


int main() {
  float d;
  while (1) {
    scanf("%f", &d);
    if (d < 0)
      break;

    printf("%.3f\n", count_percent(d)/432);
  }
  return 0;
}
