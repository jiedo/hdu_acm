#include <stdio.h>

int main(int n) {
  int cache[65536] = {0};
  while (scanf("%d",&n)+1) {
    if (cache[n] == 0) {
      if(n%2)
        cache[n] = (n + 1)/2*n;
      else
        cache[n] = n/2*(n + 1);
    }
    printf("%d\n\n", cache[n]);
  }
}
