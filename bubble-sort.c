#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printList(int *l, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(l + i));
  }
  printf("\n");
}
void swap(int *list, int a, int b) {
  int tmp = *(list + a);
  *(list + a) = *(list + b);
  *(list + b) = tmp;
}
void bubbleSort(int *list, int size) {
  int i = 0;
  for (int j = 0; j < (size - 1) * (size - 1); j++) {
    if (*(list + i) > *(list + i + 1)) {
      swap(list, i, i + 1);
    }
    if (i == size - 1) {
      i = 0;
    }
    i++;
  }
}

int main (void) {
  srand(time(NULL)); 
  int list[] = {1,8,9,3,5,4,6,7,4,3,5,6,2,3,9,9,1};
  int size = 17;
  bubbleSort(list, size);
  printList(list, size);

  return 0;
}
