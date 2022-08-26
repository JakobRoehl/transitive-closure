#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printList(int *l, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(l + i));
  }
}
int *merge(int *a, int *b, int a_size, int b_size) {
  a_size++;
  b_size++;
  int a_pointer = 0;
  int b_pointer = 0;
  int *out = (int*)malloc((a_size + b_size) * sizeof(int));
  int out_pointer = 0;
  while (a_pointer != a_size - 1 || b_pointer != b_size - 1) {
    int a_element = *(a + a_pointer);
    int b_element = *(b + b_pointer);
    if ((a_element < b_element && a_pointer != a_size - 1) || b_pointer == b_size - 1) {
      *(out + out_pointer) = a_element;
      out_pointer++;
      a_pointer++;
      continue;
    }
    if ((b_element < a_element  && b_pointer != b_size - 1) || a_pointer == a_size - 1) {
      *(out + out_pointer) = b_element;
      out_pointer++;
      b_pointer++;
      continue;
    }
    if (b_element == a_element) {
      *(out + out_pointer) = a_element;
      out_pointer++;
      *(out + out_pointer) = b_element;
      out_pointer++;
      a_pointer++;
      b_pointer++;
      continue;
    }
  }
  return out;
}

int *mergeSort(int *list, int size) {
  if (size == 1) {
    return list;
  }
  int first_size = size / 2;
  int second_size = first_size + ((size % 2 == 1) ? 1 : 0);
  int *second = list + first_size;
  return merge(mergeSort(list, first_size), mergeSort(second, second_size), first_size, second_size);
}


int main (void) {
  int list[] = {1,3,2,3,6,2,5,1,6,4,7,2,1,8,1,3,2,3,6,2,5,1,6,4,7,2,1,8,1,3,2,3,6,2,5,1,6,4,7,2,1,8,1,3,2,3,6,2,5,1,6,4,7,2,1,8};
  int size = 56;
  printList(mergeSort(list, size), size);
  return 0;
}
