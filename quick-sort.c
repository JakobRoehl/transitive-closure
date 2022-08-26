#include <stdio.h>
#include <stdlib.h>
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
int *listMerge(int *a, int *b, int a_size, int b_size, int center) {
  int *out = (int*)malloc((a_size + b_size + 1) * sizeof(int));
  memcpy(out, a, a_size * sizeof(int));
  *(out + a_size) = center;
  memcpy(out + a_size + 1, b, b_size * sizeof(int));
  return out;
}
int *quickSort(int *list, int size) {
  int pivot = *(list + size - 1);
  int low = 0;
  int high = size - 2;
  while (!(high < low)) {
    if (*(list + high) >= pivot) {
      high--;
    }
    if (*(list + low) <= pivot) {
      low++;
    }
    if (*(list + high) < pivot && *(list + low) > pivot && low < high) {
      swap(list, low, high);
    }
  }
  swap(list, size - 1, low);
  int first_size = low;
  int second_size = size - low;
  int *second = list + low;
  if (size == 1) {
    return list;
  }
  return listMerge(quickSort(list, first_size), quickSort(second, second_size), first_size, second_size, *(list + low));
}


int main (void) {
  int list[] = {1,8,9,3,5,4,6,7,4,3,5,6,2,3,9,9,1};
  int size = 17;
  quickSort(list, size);
  printList(list, size);
  return 0;
}
