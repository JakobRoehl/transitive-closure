#include <iostream>
#define MATRIX_SIZE 4
using namespace std;
int printmatrix(int m[MATRIX_SIZE][MATRIX_SIZE]) {
  cout << "\n";
  for (int i = 0; i < MATRIX_SIZE; i++) {
    for (int j = 0; j < MATRIX_SIZE; j++) {
      cout << " " << m[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
int main(void) {
  int matrix[MATRIX_SIZE][MATRIX_SIZE] = {{1,1,1,0},
                                          {0,0,1,0},
                                          {0,0,0,0},
                                          {0,0,0,0}};
  for (int r = 0; r < MATRIX_SIZE; r++)
    for (int i = 0; i < MATRIX_SIZE; i++)
      if (matrix[i][r])
        for (int j = 0; j < MATRIX_SIZE; j++)
          if (matrix[i][r] && matrix[r][j])
            matrix[i][j] = 1;
  printmatrix(matrix);
  return 0;
}
