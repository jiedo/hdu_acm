#include <stdio.h>
#include <string.h>


typedef struct {
  char color[16];
  int count;
} Color_Count_Pair;


int bin_search_color(Color_Count_Pair *all_color_counts, char *color, int total) {
  if(total == 0)
    return -1;

  int idx = total/2;
  int cmp = strcmp(all_color_counts[idx].color, color);
  if(cmp == 0) {
    return idx;
  }

  if (cmp > 0) {
    int result = bin_search_color(all_color_counts, color, idx);
    if (result >= 0) {
      return result;
    }

  } else {
    int result = bin_search_color(&all_color_counts[idx+1], color, total-idx-1);
    if (result >= 0) {
      return idx + result + 1;
    }
  }
  return -1;
}


void increase_color(Color_Count_Pair *all_color_counts, char *color, int *total, int *max_idx) {
  int idx = bin_search_color(all_color_counts, color, *total);
  if (idx < 0) {
    idx = *total;
    strncpy(all_color_counts[idx].color, color, 16);
    all_color_counts[idx].count = 1;

    Color_Count_Pair tmp_color;
    for (int i=0; i<idx; i++) {
      int cmp = strcmp(all_color_counts[idx-i-1].color,
                       all_color_counts[idx-i].color);
      if(cmp > 0) {
        /* swap */
        tmp_color = all_color_counts[idx-i-1];
        all_color_counts[idx-i-1] = all_color_counts[idx-i];
        all_color_counts[idx-i] = tmp_color;
      } else {
        break;
      }
    }
    (*total)++;
  } else {
    all_color_counts[idx].count += 1;
  }

  if (all_color_counts[*max_idx].count < all_color_counts[idx].count)
    *max_idx = idx;
}


void get_most_populer_color(int num) {
  Color_Count_Pair all_color_counts[1000];
  char line_color[16];
  int total = 0;
  int max_idx = 0;
  for (int i=0; i < num; i++) {
    scanf("%s", &line_color);
    increase_color(all_color_counts, line_color, &total, &max_idx);
  }

  printf("%s\n", all_color_counts[max_idx].color);
}


int main() {
  int num;
  while (1) {
    scanf("%d", &num);
    if (num == 0)
      break;

    get_most_populer_color(num);
  }
  return 0;
}
