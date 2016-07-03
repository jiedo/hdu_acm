#include <stdio.h>
#include <string.h>

struct Color_Count_Pair {
  char color[16];
  int count;
};



int bin_search_color(Color_Count_Pair *all_color_counts, char *color, int *total) {

  idx = total/2;
  int cmp = strcmp(all_color_counts[idx]->color, color);

  if(cmp == 0) {
    return idx;
  }

  if (cmp < 0) {
    bin_search_color(all_color_counts, color, idx);
  } else {
    bin_search_color(&all_color_counts[idx+1], color, idx);
  }

}

int incrase_color(Color_Count_Pair *all_color_counts, char *color, int *total) {


  idx = total/2;
  int cmp = strcmp(all_color_counts[idx]->color, color);

  if(cmp == 0) {
    return idx
  }

    for (int i=0; i < num; i++) {


    }


}

void get_most_populer_color(int num, char *color) {
  Color_Count_Pair all_color_counts[1000];
  char line_color[16];
  int total = 0;
  for (int i=0; i < num; i++) {
    scanf("%s", &line_color);

    incrase_color(&all_color_counts, line_color, &total)
  }
}


int main() {
  int color[16];
  int num;
  while (1) {
    scanf("%d", &num);
    if (num == 0)
      break;

    get_most_populer_color(num, &color);
    printf("%s\n", color);
  }
  return 0;
}
